package dr.servlet;

import dr.domainmodel.entities.Project;
import dr.domainmodel.repository.base.ProjectRepository;
import dr.domainmodel.repository.base.TaskRepository;
import dr.domainmodel.repository.impl.mysql.MySqlProjectRepository;
import dr.domainmodel.repository.impl.mysql.MySqlTaskRepository;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.UnavailableException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class DayReport extends HttpServlet {

    //<editor-fold desc="Fields">

    private final String DB_CONNECTION_URL
            = "jdbc:mysql://localhost/DR?user=root";

    //</editor-fold>

    //<editor-fold desc="Servlet Life Cycle">

    @Override
    public void init(ServletConfig config) throws ServletException {
        super.init(config);
        try {
            // загрузка JDBC-драйвера MySQL
            Class.forName("com.mysql.jdbc.Driver");
        } catch (Throwable e) {
            // сервлет недоступен,
            // если в процессе инициализации сервлета возникла ошибка
            throw new UnavailableException("Servlet could not be created");
        }
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException {
        try {
            // создание репозитария для таблицы Project
            ProjectRepository projectRepository
                    = new MySqlProjectRepository(DB_CONNECTION_URL);
            // создание репозитария для таблицы Task
            TaskRepository taskRepository
                    = new MySqlTaskRepository(DB_CONNECTION_URL);
            // получение списка всех проектов,
            // в которых берет участие пользователь
            List<Project> projects = projectRepository.select();
            // определение типа содержимого HTTP-ответа
            response.setContentType("text/html;charset=UTF-8");
            // получение потока для формирования HTTP-ответа
            PrintWriter writer = response.getWriter();
            try {
                // генерация верхний части страницы
                renderResource(request, response, "PageHeader");
                // генерация формы ввода данных о новой задаче
                renderAddNewTaskForm(writer, projects);
                // генерация нижней части страницы
                renderResource(request, response, "PageFooter ");
            } finally {
                // закрытие потока HTTP-ответа
                writer.close();
            }
        } catch (Throwable e) {
            // любое исключение представить как ServletException
            throw new ServletException(e);
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException {
    }

    //</editor-fold>

    //<editor-fold desc="HTML Rendering">

    /**
     * Включение содержимого ресурса resourceName
     * в HTTP-ответ
     *
     * @param request - HTTP-запрос
     * @param response - HTTP-ответ
     * @param resourceName - имя ресурса
     */
    private void renderResource(
            HttpServletRequest request,
            HttpServletResponse response,
            String resourceName)
                throws ServletException, IOException {
        // получения диспатчера для ресурса resourceName
        RequestDispatcher requestDispatcher
                = request.getServletContext().getNamedDispatcher(resourceName);
        // включение в HTTP-ответ содержимого ресурса resourceName
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
    private void renderAddNewTaskForm(PrintWriter writer, List<Project> projects) {
        writer.println("<div>");
        // HTML-форма
        writer.println("<form method='POST'>");
        writer.println("<h2>Add New Task</h2>");
        // выпадающий список для выбора проекта
        writer.println("<b>Project&nbsp;</b>");
        writer.println("<select name='"+ PROJECT_ATTRIBUTE + "'>");
        for(Project p : projects) {
            writer.println("<option value='"
                    + p.getProjectID() + "'>"
                    + p.getName()
                    + "</option>");
        }
        writer.println("</select>");
        writer.println("&nbsp;&nbsp;");

        // поле для ввода значения количества затраченных часов
        writer.println("<b>Hours&nbsp;</b>");
        writer.println("<input type='text' name='" 
                + HOURS_ATTRIBUTE
                + "' value=''/>");
        writer.println("<br/>");

        // поле для ввода описания проделанной работы
        writer.println("<b>Task Description&nbsp;</b>");
        writer.println("<br/>");
        writer.println("<textarea name='" 
                + DESCRIPTION_ATTRIBUTE +
                "' rows='5' cols='50' /></textarea>");
        writer.println("<br/>");

        // кнопка подтверждения введенных данних
        writer.println("<input type='submit' name='save' value='Save' />");

        // кнопка отклонения введенных данних
        writer.println("<input type='submit' name='cancel' value='Cancel' />");

        writer.println("</form>");
        writer.println("</div>");
    }

    //</editor-fold>

}