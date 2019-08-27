import javax.servlet.AsyncContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.IOException;
import java.util.Enumeration;

@WebServlet(value = "/HelloWorld", asyncSupported = true)
public class HelloWorld extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //super.doGet(req, resp);
        /*String s="<html>"+
                "<header><title>This is title</title></header>"+
                "<body>"+
                "Hello from HelloWorld servlet!"+
                "</body>"+
                "</html>";
        resp.getWriter().write(s);
        String one = req.getParameter("one");
        System.out.println(one);*/
        String one = req.getParameter("one");
        one=one==null?"":one.replaceAll("<","&lt").replaceAll(">","&gt");
        String s="<html>"+
                "<head></head>"+
                "<body>"+"one= "+one+
                "<form action='HelloWorld' method='post'>"+
                "<textarea name='one'></textarea>"+
                "<input type='submit' name='submit'/>"+
                "</form>"+
                "</body>"+
                "</html>";
        resp.getWriter().write(s);
        /*Enumeration<String> headerNames = req.getHeaderNames();
        while(headerNames.hasMoreElements()){
            String ss = headerNames.nextElement();
            System.out.println(ss+" = "+ req.getHeader(ss));
        }*/
        Cookie[] cookies =req.getCookies();
        for(Cookie cookie: cookies ){
            System.out.println(cookie.getName());
            System.out.println(cookie.getValue());
        }
        Cookie cookie=new Cookie("first","cookie");
        resp.addCookie(cookie);

        HttpSession session = req.getSession(true);
        Enumeration<String> attributeNames = session.getAttributeNames();
        while(attributeNames.hasMoreElements()){
            String attributeName=attributeNames.nextElement();
            System.out.println(attributeName+" = "+session.getAttribute(attributeName));
        }
        session.setAttribute("one","object");
        System.out.println(session.getMaxInactiveInterval());
        session.removeAttribute("one");

        AsyncContext asyncContext=req.getAsyncContext();
        asyncContext.start(new Runnable(){
            @Override
            public void run() {
                //await event
            }
        });

    }

    @Override
    public void init() throws ServletException {
        //super.init();
        System.out.println("initialization");
        //some arguments
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //super.doPost(req, resp);

        doGet(req, resp);
    }
}
