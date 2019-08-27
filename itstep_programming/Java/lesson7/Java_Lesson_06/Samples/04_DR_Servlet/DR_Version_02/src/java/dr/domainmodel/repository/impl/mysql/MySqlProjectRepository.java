package dr.domainmodel.repository.impl.mysql;

import dr.domainmodel.entities.Project;
import dr.domainmodel.repository.base.ProjectRepository;
import java.sql.ResultSet;
import java.sql.SQLException;

public class MySqlProjectRepository extends MySqlBaseRepository<Project, Integer> implements ProjectRepository {

    public MySqlProjectRepository(String dbConnectionUrl) {
        super(dbConnectionUrl);
    }

    @Override
    protected Project readEntityFromResultSet(ResultSet resultSet) throws SQLException {
        Project project = new Project();
        project.setProjectID(resultSet.getInt("ProjectID"));
        project.setName(resultSet.getString("Name"));
        return project;
    }

    @Override
    protected Integer getEntityID(Project entity) {
        return entity.getProjectID();
    }

    @Override
    protected String selectAllQuery() {
        return "SELECT * FROM Project";
    }

    @Override
    protected String selectByIDQuery(Integer id) {
        return "SELECT * FROM Project WHERE ProjectID = " + id;
    }

    @Override
    protected String updateQuery(Project entity) {
        return "UPDATE Project SET `Name`="
                + toSQLString(entity.getName())
                + " WHERE ProjectID="
                + entity.getProjectID();
    }

    @Override
    protected String deleteQuery(Integer id) {
        return "DELETE FROM Project WHERE ProjectID = " + id;
    }

    @Override
    protected String insertQuery(Project entity) {
        return "INSERT INTO Project (`Name`) VALUES (" + toSQLString(entity.getName()) + ")";
    }

    @Override
    protected String selectLastInsertedEntityIDQuery() {
        return "SELECT MAX(ProjectID) FROM Project";
    }

    @Override
    protected Integer getLastInsertedEntityIDQuery(ResultSet resultSet) throws SQLException {
        return resultSet.getInt(1);
    }

}