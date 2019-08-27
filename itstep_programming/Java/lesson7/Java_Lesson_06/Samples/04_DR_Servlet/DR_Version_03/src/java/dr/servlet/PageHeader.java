package dr.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class PageHeader extends HttpServlet {

    protected String getApplicationPath(HttpServletRequest request) {
        return request.getScheme()
                + "://" + request.getServerName()
                + ":" + request.getServerPort()
                + request.getContextPath();
    }

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        out.println("<html>");
        out.println("<head>");
        out.println("<link href='" + getApplicationPath(request) + "/content/styles/style.css' rel='stylesheet' type='text/css'/>");
        out.println("<title>");
        out.println("Developer Reporting System");
        out.println("</title>");
        out.println("</head>");
        out.println("<body>");
        out.println("<div id='page-head'>");
        out.println("<h1>Developer Reporting System</h1>");
        out.println("</div>");
        out.println("<div id='page-content'>");  
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