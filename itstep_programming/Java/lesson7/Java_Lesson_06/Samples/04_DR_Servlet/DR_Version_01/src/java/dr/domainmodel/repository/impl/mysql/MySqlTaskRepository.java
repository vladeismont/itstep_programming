/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package dr.domainmodel.repository.impl.mysql;

import dr.domainmodel.entities.Task;
import dr.domainmodel.repository.base.TaskRepository;
import java.math.BigDecimal;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

/**
 *
 * @author Альтернативний
 */
public class MySqlTaskRepository extends MySqlBaseRepository<Task, Integer> implements TaskRepository {

    public MySqlTaskRepository(String dbConnectionUrl) {
        super(dbConnectionUrl);
    }

    @Override
    protected Task readEntityFromResultSet(ResultSet resultSet) throws SQLException {
        Task task = new Task();
        task.setTaskID(resultSet.getInt("TaskID"));
        task.setProjectID(resultSet.getInt("ProjectID"));
        task.setReportedAt(resultSet.getTimestamp("ReportedAt"));
        task.setHours(resultSet.getBigDecimal("Hours"));
        task.setDescription(resultSet.getString("Description"));
        return task;
    }

    @Override
    protected Integer getEntityID(Task entity) {
        return entity.getTaskID();
    }

    @Override
    protected String selectAllQuery() {
        return "SELECT * FROM Task";
    }

    @Override
    protected String selectByIDQuery(Integer id) {
        return "SELECT * FROM Task WHERE TaskID = " + id;
    }

    @Override
    protected String updateQuery(Task entity) {
        return "UPDATE Task SET"
                + " ProjectID=" + entity.getProjectID() + ", "
                + " ReportedAt=" + toSQLDatetime(entity.getReportedAt()) + ", "
                + " Hours=" + entity.getHours() + ", "
                + " Description=" + toSQLString(entity.getDescription())
                + " WHERE TaskID=" + entity.getTaskID();
    }

    @Override
    protected String deleteQuery(Integer id) {
        return "DELETE FROM Task WHERE TaskID = " + id;
    }

    @Override
    protected String insertQuery(Task entity) {
        return "INSERT INTO Task "
                + " (ProjectID, ReportedAt, Hours, Description) "
                + " VALUES "
                + "("
                    + entity.getProjectID() + ", "
                    + toSQLDatetime(entity.getReportedAt()) + ", "
                    + entity.getHours() + ", "
                    + toSQLString(entity.getDescription())
                + ")";
    }

    @Override
    protected String selectLastInsertedEntityIDQuery() {
        return "SELECT MAX(ProjectID) FROM Task";
    }

    @Override
    protected Integer getLastInsertedEntityIDQuery(ResultSet resultSet) throws SQLException {
        return resultSet.getInt(1);
    }

    @Override
    public List<Task> selectByDate(Date date) throws SQLException{
        return selectByQuery(selectByDateQuery(date));
    }

    protected String selectByDateQuery(Date date) {
        DateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
        return "SELECT * FROM Task"
                + " WHERE DATE(ReportedAt) = "
                + "'" + dateFormat.format(date) + "'"
                + " ORDER BY ReportedAt DESC";
    }

}