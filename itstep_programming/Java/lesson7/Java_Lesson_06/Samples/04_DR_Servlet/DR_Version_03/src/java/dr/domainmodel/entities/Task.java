/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package dr.domainmodel.entities;

import java.math.BigDecimal;
import java.util.Date;

/**
 *
 * @author Альтернативний
 */
public class Task {
    private Integer taskID;
    private Integer projectID;
    private Date reportedAt;
    private BigDecimal hours;
    private String description;

    public Task() {
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public BigDecimal getHours() {
        return hours;
    }

    public void setHours(BigDecimal hours) {
        this.hours = hours;
    }

    public Integer getProjectID() {
        return projectID;
    }

    public void setProjectID(Integer projectID) {
        this.projectID = projectID;
    }

    public Date getReportedAt() {
        return reportedAt;
    }

    public void setReportedAt(Date reportedAt) {
        this.reportedAt = reportedAt;
    }

    public Integer getTaskID() {
        return taskID;
    }

    public void setTaskID(Integer taskID) {
        this.taskID = taskID;
    }

}
