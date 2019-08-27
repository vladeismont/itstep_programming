import java.io.*;
import javax.servlet.*;

/*
* Compiler command line:
* javac HelloServlet.java -classpath "C:\Program Files\Apache Software Foundation\Tomcat 5.5\common\lib\servlet-api.jar"
*/

public class HelloServlet extends GenericServlet {

	@Override
	public void service(ServletRequest request, 
			ServletResponse response) throws ServletException, IOException {
		// ���������� ��� ����������� ������
		response.setContentType("text/html");
		// ������� ����� ������
		PrintWriter writer = response.getWriter();
		try {
			// ���������� ����� � ����� ������
			writer.println("<b>Hello from servlet</b>");
		} finally {
			// ��������� ����� ������
			writer.close();
		}		
	}		
}