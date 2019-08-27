package dr.servlet;

import dr.domainmodel.entities.Project;
import dr.domainmodel.entities.Task;
import dr.domainmodel.repository.base.ProjectRepository;
import dr.domainmodel.repository.base.TaskRepository;
import dr.domainmodel.repository.impl.mysql.MySqlProjectRepository;
import dr.domainmodel.repository.impl.mysql.MySqlTaskRepository;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.sql.SQLException;
import java.util.Date;
import java.util.List;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.UnavailableException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class DayReport extends HttpServlet {

    //<editor-fold desc="Data Fields">

    // параметри подключения к базе данных MySQL
    private final String DB_CONNECTION_URL = "jdbc:mysql://localhost/DR?user=root";

    //</editor-fold>

    //<editor-fold desc="Servlet Life Cycle">

    @Override
    public void init(ServletConfig config) throws ServletException {
        super.init(config);
        try {
            // загрузка JDBC-драйвера MySQL
            Class.forName("com.mysql.jdbc.Driver");
        } catch (Throwable e) {
            // если в процессе инициализации сервлета возникла ошибка - сервлет недоступен
            throw new UnavailableException("Servlet could not be created");
        }
    }

    @Override
    protected void doGet(HttpServletRequest request,
        HttpServletResponse response) throws ServletException, IOException {
        try {
            // создать состояние модели по умолчанию
            ModelState modelState = createDefaultModelState(request, null);
            // отображение страницы
            doRequest(response, request, modelState);
        } catch (Throwable e) {
            // любое исключение представить как ServletException
            throw new ServletException(e);
        }
    }

    @Override
    protected void doPost(HttpServletRequest request,
            HttpServletResponse response) throws ServletException, IOException {
        try {
            ModelState modelState;
            // проверяем с помощью какой кнопки
            // HTML-форма была отправлена на сервер
            if (request.getParameter("save") != null) {
                // форма была отправлена на сервер с помощью кнопки Save

                // считывание полей формы из запросса
                modelState = readModelFromRequest(request);
                // проверка коррекности введенных данных
                validateModel(modelState);
                if (modelState.isValid()) {
                    // введенные данные корректные

                    // получение объекта Task из состояния модели
                    Task task = readTaskFromModelState(modelState);
                    // установить текущую дату дла отчета
                    task.setReportedAt(new Date());
                    // создание репозитария для таблицы Task
                    TaskRepository taskRepository
                            = new MySqlTaskRepository(DB_CONNECTION_URL);
                    // сохранить отчет в базе данных
                    taskRepository.insert(task);
                    // сохранение ключа проекта в cookie-наборе
                    setDefaultProjectID(response, task.getProjectID().toString());
                    // создать состояние модели по умолчанию
                    modelState = createDefaultModelState(request, task.getProjectID());
                }
            } else {
                // форма была отправлена на сервер с помощью кнопки Cancel

                // создать состояние модели по умолчанию
                modelState = createDefaultModelState(request, null);
            }
            // отображение страницы
            doRequest(response, request, modelState);
        } catch (Throwable e) {
            // любое исключение представить как ServletException
            throw new ServletException(e);
        }
    }

    /**
     * Отображение страницы
     * с учетом текущеного состояния модели
     *
     * @param response - HTTP-ответ
     * @param request - HTTP-запрос
     * @param modelState - состояние модели
     */
    private void doRequest(HttpServletResponse response,
            HttpServletRequest request,
            ModelState modelState)
            throws IOException, SQLException, ServletException {

        // создание репозитария для таблицы Project
        ProjectRepository projectRepository
                = new MySqlProjectRepository(DB_CONNECTION_URL);
        // создание репозитария для таблицы Task
        TaskRepository taskRepository
                = new MySqlTaskRepository(DB_CONNECTION_URL);
        // определение типа содержимого HTTP-ответа
        response.setContentType("text/html;charset=UTF-8");
        // получение списка всех проектов,
        // в которых берет участие пользователь
        List<Project> projects = projectRepository.select();
        PrintWriter writer = response.getWriter();
        try {
            // включение верхний части страницы
            renderResource(request, response, "PageHeader");
            // вывод в поток ответа HTML-верстки
            // формы ввода данных о новой задаче
            renderAddNewTaskForm(writer, projects, modelState);
            // включение нижней части страницы
            renderResource(request, response, "PageFooter");
        } finally {
            writer.close();
        }
    }

    //</editor-fold>

    //<editor-fold desc="HTML Rendering">

    /**
     * Включение содерживого ресурса resourceName
     * в HTTP-ответ
     *
     * @param request - HTTP-запрос
     * @param response - HTTP-ответ
     * @param resourceName - имя ресурса
     * @throws ServletException
     * @throws IOException
     */
    private void renderResource(
            HttpServletRequest request,
            HttpServletResponse response,
            String resourceName) throws ServletException, IOException {
        // получения диспатчера для ресурса resourceName
        RequestDispatcher requestDispatcher
                = request.getServletContext().getNamedDispatcher(resourceName);
        // включение в ответ содержимого ресурса resourceName
        requestDispatcher.include(request, response);
    }

    /**
     * Идентификатор поля project
     */
    private final String PROJECT_ATTRIBUTE = "project";
    /**
     * Идентификатор поля hours
     */
    private final String HOURS_ATTRIBUTE = "hours";
    /**
     * Идентификатор поля description
     */
    private final String DESCRIPTION_ATTRIBUTE = "descriptioin";

    /**
     * Генерация HTML-представления формы
     * добавления новой задачи к отчету
     *
     * @param writer - поток HTTP-ответа
     * @param projects - список проектов пользователя
     * @param modelState - текущее состояние модели
     */
    private void renderAddNewTaskForm(PrintWriter writer,
            List<Project> projects, ModelState modelState) {
        writer.println("<div>");
        // HTML-форма
        writer.println("<form method='POST'>");
        writer.println("<h2>Add New Task</h2>");

        // сообщения валидации
        writer.println("<div class='validationsummary'>");
        if (!modelState.isValid()) {
            writer.println("<b>Validation Summary</b>");
        }
        writer.println("<ul>");
        for (String message : modelState.getValidationMessages()) {
            writer.println("<li>" + message + "</li>");
        }
        writer.println("</ul>");
        writer.println("</div>");

        // выпадающий список для выбора проекта
        writer.println("<b>Project&nbsp;</b>");
        // считывание значения ProjectID из состояния модели
        String project = modelState.is(PROJECT_ATTRIBUTE)
                ? modelState.get(PROJECT_ATTRIBUTE).getValue() : "";
        writer.println("<select name='"+ PROJECT_ATTRIBUTE + "'>");
        for(Project p : projects) {
            writer.println("<option value='" + p.getProjectID() + "'"
                    + (p.getProjectID().toString().equals(project)
                    ? "selected" : "")
                    + ">" + p.getName() + "</option>");
        }
        writer.println("</select>");
        writer.println("&nbsp;&nbsp;");

        // поле для ввода значения количества затраченных часов
        writer.println("<b>Hours&nbsp;</b>");
        // считывание значения Hours из состояния модели
        String hours = modelState.is(HOURS_ATTRIBUTE)
                ? modelState.get(HOURS_ATTRIBUTE).getValue() : "";
        writer.println("<input type='text' name='"
                + HOURS_ATTRIBUTE
                + "' value='" + hours + "'/>");
        writer.println("<br/>");

        // поле для ввода описания проделанной работы
        writer.println("<b>Task Description&nbsp;</b>");
        writer.println("<br/>");
        // считывание значения Description из состояния модели
        String description = modelState.is(DESCRIPTION_ATTRIBUTE)
                ? modelState.get(DESCRIPTION_ATTRIBUTE).getValue() : "";
        writer.println("<textarea name='"
                + DESCRIPTION_ATTRIBUTE
                + "' rows='5' cols='50' />" +
                description
                + "</textarea>");
        writer.println("<br/>");

        // кнопка подтверждения введенных данних
        writer.println("<input type='submit' name='save' value='Save' />");

        // кнопка отклонения введенных данних
        writer.println("<input type='submit' name='cancel' value='Cancel' />");

        writer.println("</form>");
        writer.println("</div>");
    }

    //</editor-fold>

    //<editor-fold desc="Validation">
    
    /**
     * Проверка корректности данных,
     * введенных пользователем
     *
     * @param modelState - состояние модели
     * @return состояние модели с сообщениями валидации
     */
    private ModelState validateModel(ModelState modelState) {

       // проверка коректности значения Project
       // проверка коректности значения Project
       AttributeState projectState = modelState.get(PROJECT_ATTRIBUTE);
       String project = projectState.getValue();
       if (project == null || project.isEmpty()) {
           projectState.getValidationMessages().add("'Project' is required value");
       }
       try {
           Integer.parseInt(project);
       } catch (NumberFormatException e) {
           projectState.getValidationMessages().add("'Project' is incorrect");
       }

       // проверка коректности значения Hours
       AttributeState hoursState = modelState.get(HOURS_ATTRIBUTE);
       String hours = hoursState.getValue();

      if (hours == null || hours.isEmpty()) {
           hoursState.getValidationMessages().add("'Hours' is required value");
       } else {
           try {
               BigDecimal bigDecimalHours = new BigDecimal(hours);
               if (bigDecimalHours.scale() > 1) {
                   projectState.getValidationMessages().add("'Hours' has incorrect format");
               }
               if (bigDecimalHours.doubleValue() <= 0 || bigDecimalHours.doubleValue() > 24) {
                   projectState.getValidationMessages().add("'Hours' has incorrect value");
               }
           } catch (NumberFormatException e) {
               projectState.getValidationMessages().add("'Hours' has incorrect format");
           }
       }

       // проверка коректности значения Description
       AttributeState descriptionState = modelState.get(DESCRIPTION_ATTRIBUTE);
       String description = descriptionState.getValue();
       if (description == null || description.isEmpty()) {
           hoursState.getValidationMessages().add("'Description' is required value");
       } else if (description.length() > 1000) {
           hoursState.getValidationMessages().add("'Description' should less than 1001");
       }       

       return modelState;
    }
    
    //</editor-fold>

    //<editor-fold desc="Helpers">

    /**
     * Создание состояния модели по умолчанию
     * 
     * @param request - HTTP-запрос
     * @param lastProjetID - ключ последнего использованного проекта
     * @return состояние модели по умолчанию
     */
    private ModelState createDefaultModelState
            (HttpServletRequest request, Integer lastProjectID) {
        ModelState modelState = new ModelState();
        // получение проекта по умолчанию
        String defaultProjectID = lastProjectID == null
                ? getDefaultProjectID(request)
                : lastProjectID.toString();
        if (defaultProjectID != null) {
            // определение проекта по умолчанию
            modelState.put(PROJECT_ATTRIBUTE,
                new AttributeState(PROJECT_ATTRIBUTE, defaultProjectID));
        }
        return modelState;
    }

    /**
     * Считывание значение аттрибутов модели с запроса
     *
     * @param request - HTTP-запрос
     * @return состояние модели
     */
    private ModelState readModelFromRequest(HttpServletRequest request) {
        ModelState modelState = new ModelState();

        String project = request.getParameter(PROJECT_ATTRIBUTE);
        String hours = request.getParameter(HOURS_ATTRIBUTE);
        String description = request.getParameter(DESCRIPTION_ATTRIBUTE);

        modelState.put(PROJECT_ATTRIBUTE, new AttributeState(PROJECT_ATTRIBUTE, project));
        modelState.put(HOURS_ATTRIBUTE, new AttributeState(HOURS_ATTRIBUTE, hours));
        modelState.put(DESCRIPTION_ATTRIBUTE, new AttributeState(DESCRIPTION_ATTRIBUTE, description));

        return modelState;
    }

    /**
     * Имя cookie-набора, содержащего
     * значение ключа проекта по умолчанию
     */
    private final String DEFAULT_PROJECT_ID_COOKIE = "default_project_id";
    /**
     * Получение из cookie-набора ключа проекта по умолчанию
     * 
     * @param request - HTTP-запрос
     * @return значение ключа проекта по умолчанию,
     * или null, если cookie-набор не определен
     */
    private String getDefaultProjectID(HttpServletRequest request) {
        // получаем массив cookie-наборов запроса
        Cookie[] cookies = request.getCookies();
        if (cookies != null) {
            // ищем cookie-набор с нужным именем
            for (Cookie c : cookies) {
                if (c.getName().equals(DEFAULT_PROJECT_ID_COOKIE)) {
                    // если cookie-набор найден,
                    // возвращаем его значение
                    return c.getValue();
                }
            }
        }
        // если cookie-набор не найден,
        // возвращаем значение null
        return null;
    }
    /**
     * Сохранение в cookies ключа проекта,
     * который будет использоваться по умолчанию
     *
     * @param response - HTTP-ответ
     * @param projectID - ключ проекта
     */
    private void setDefaultProjectID(HttpServletResponse response,
            String projectID) {
        // создаем объект Cookie
        Cookie cookie = new Cookie(DEFAULT_PROJECT_ID_COOKIE, projectID);
        // устанавливаем время жизни cookie-набора,
        // равним 24 часам
        cookie.setMaxAge(3600 * 24);
        // добавляем cookie-набор к ответу
        response.addCookie(cookie);
        
    }

    /**
     * Создание объекта Task
     * на основании значений состояния модели
     *
     * @param modelState - состояние модели
     * @return объект Task
     */
    private Task readTaskFromModelState(ModelState modelState) {
        Task task = new Task();
        task.setProjectID(Integer.parseInt(modelState.get(PROJECT_ATTRIBUTE).getValue()));
        task.setHours(new BigDecimal(modelState.get(HOURS_ATTRIBUTE).getValue()));
        task.setDescription(modelState.get(DESCRIPTION_ATTRIBUTE).getValue());
        return task;
    }


    //</editor-fold>
}