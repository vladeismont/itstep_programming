package dr.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Сервлет, генерирующий нижнюю часть страницы
 */
public class PageFooter extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        PrintWriter out = response.getWriter();
        out.println("</div>");
        out.println("<div id='page-footer'>");
        out.println("Reporting Software &copy; 2010");
        out.println("</div>");
        out.println("</body>");
        // нельзя закрывать поток out,
        // так как он закрывается в сервлете DayReport
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

}