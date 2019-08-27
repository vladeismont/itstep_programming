/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package dr.domainmodel.entities;

/**
 *
 * @author Альтернативний
 */
public class Project {
    
    private Integer projectID;
    private String name;

    public Project() {

    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Integer getProjectID() {
        return projectID;
    }

    public void setProjectID(Integer projectID) {
        this.projectID = projectID;
    }
    
}
