import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Hello extends HttpServlet {
   
    @Override
    protected void doGet(HttpServletRequest request,
        HttpServletResponse response) throws ServletException, IOException {

        // установка типи содержимого HTTP-ответа
        response.setContentType("text/html");
        // получение потока записи в HTTP-ответ
        PrintWriter writer = response.getWriter();
        try {
            // формирование HTML-формы
            writer.println("<form method='post'>");
            writer.println("<b>Enter yout name:</b>");
            writer.println("<input type='text' name='userName' />");
            writer.println("<input type='submit' name='submit' value='Enter' />");
            writer.println("</form>");
        } finally {
            // закрытие потока HTTP-ответа
            writer.close();
        }
    }

    @Override
    protected void doPost(HttpServletRequest request,
        HttpServletResponse response) throws ServletException, IOException {

        // установка типи содержимого HTTP-ответа
        response.setContentType("text/html");
        // получение потока записи в HTTP-ответ
        PrintWriter writer = response.getWriter();
        try {
            // получаем имя, указаное пользователем,
            // из HTTP-запроса
            String userName = request.getParameter("userName");
            if (userName == null || userName.length() == 0) {
                // отображаем сообщение об ошибке
                writer.println("<div style='color:red'>Error: incorrect user name</div>");
                writer.println("<form method='get'>");
                writer.println("<input type='submit' value='Try Again' />");
                writer.println("</form>");
            } else {
                // отображаем приветствие пользователя
                writer.println("Hello <b>" + userName + "</b>");
                writer.println("<form method='get'>");
                writer.println("<input type='submit' value='Back' />");
                writer.println("</form>");
            }
        } finally {
            // закрытие потока HTTP-ответа
            writer.close();
        }
    }

}
