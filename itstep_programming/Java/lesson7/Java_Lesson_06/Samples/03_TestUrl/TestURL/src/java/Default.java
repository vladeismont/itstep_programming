import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(name="Default", urlPatterns={"/Default"})
public class Default extends HttpServlet {
   
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        try {
            out.println("<u><b>URL Info</b></u>");
            out.println("<table>");
            // протокол
            out.println("<tr>");
            out.println("<td><b>getScheme()</b></td>");
            out.println("<td>" + request.getScheme() + "</td>");
            out.println("</tr>");
            // имя сервера
            out.println("<tr>");
            out.println("<td><b>getServerName()</b></td>");
            out.println("<td>" + request.getServerName() + "</td>");
            out.println("</tr>");
            // порт, который прослущивает сервер
            out.println("<tr>");
            out.println("<td><b>getServerPort()</b></td>");
            out.println("<td>" + request.getServerPort() + "</td>");
            out.println("</tr>");
            // контекстный путь Web-приложения
            out.println("<tr>");
            out.println("<td><b>getContextPath()</b></td>");
            out.println("<td>" + request.getContextPath() + "</td>");
            out.println("</tr>");
            // псевдоним Web-компонента (сервлета)
            out.println("<tr>");
            out.println("<td><b>getServletPath()</b></td>");
            out.println("<td>" + request.getServletPath() + "</td>");
            out.println("</tr>");
            // строка параметров запроса
            out.println("<tr>");
            out.println("<td><b>getQueryString()</b></td>");
            out.println("<td>" + request.getQueryString() + "</td>");
            out.println("</tr>");
            // часть URL запроса, включающая
            // контекстный путь Web-приложения
            // и псевдоним Web-компонента
            out.println("<tr>");
            out.println("<td><b>getRequestURI()</b></td>");
            out.println("<td>" + request.getRequestURI() + "</td>");
            out.println("</tr>");
            // часть URL без строки параметров запроса
            out.println("<tr>");
            out.println("<td><b>getRequestURL()</b></td>");
            out.println("<td>" + request.getRequestURL() + "</td>");
            out.println("</tr>");

            out.println("</table>");
        } finally { 
            out.close();
        }
    } 

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        processRequest(request, response);
    } 

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        processRequest(request, response);
    }

    @Override
    public String getServletInfo() {
        return "Url Test Servlet";
    }

}
