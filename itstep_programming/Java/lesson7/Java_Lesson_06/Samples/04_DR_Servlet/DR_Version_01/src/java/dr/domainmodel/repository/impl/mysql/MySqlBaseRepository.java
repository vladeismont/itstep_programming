package dr.domainmodel.repository.impl.mysql;

import dr.domainmodel.repository.base.BaseRepository;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.LinkedList;
import java.util.List;
import java.util.Locale;


public abstract class MySqlBaseRepository<E, K> implements BaseRepository<E, K> {

    private final String dbConnectionUrl;

    public MySqlBaseRepository(String dbConnectionUrl) {
        this.dbConnectionUrl = dbConnectionUrl;
    }

    protected Connection createConnection() throws SQLException {
        return DriverManager.getConnection(dbConnectionUrl);
    }

    protected String toSQLString(String value) {
        return "'" + value.replace("'", "''") + "'";
    }

    protected String toSQLDatetime(Date datetime) {
        DateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        return "'" + dateFormat.format(datetime) + "'";
    }

    protected List<E> fetchResultSet(ResultSet resultSet) throws SQLException {
        List<E> r = new LinkedList<E>();
        while (resultSet.next()) {
            r.add(readEntityFromResultSet(resultSet));
        }
        return r;
    }

    protected abstract E readEntityFromResultSet(ResultSet resultSet) throws SQLException;
    protected abstract K getEntityID(E entity);
    protected abstract String selectAllQuery();
    protected abstract String selectByIDQuery(K id);
    protected abstract String updateQuery(E entity);
    protected abstract String deleteQuery(K id);
    protected abstract String insertQuery(E entity);
    protected abstract String selectLastInsertedEntityIDQuery();
    protected abstract K getLastInsertedEntityIDQuery(ResultSet resultSet) throws SQLException;
        
    @Override
    public List<E> select() throws SQLException {
        return selectByQuery(selectAllQuery());
    }

    @Override
    public E selectByID(K id) throws SQLException {
        List<E> r = selectByQuery(selectByIDQuery(id));
        if (r.size() == 1) {
            return r.get(0);
        } else if (r.size() == 0) {
            return null;
        } else {
            throw new RuntimeException();
        }
    }

    @Override
    public E update(E entity) throws SQLException {
        updateByQuery(updateQuery(entity));
        return selectByID(getEntityID(entity));
    }
    
    @Override
    public E insert(E entity) throws SQLException {
        K id = insertByQuery(insertQuery(entity));
        return selectByID(id);
    }

    @Override
    public void delete(K id) throws SQLException {
        deleteByQuery(deleteQuery(id));
    }

    protected List<E> selectByQuery(String query) throws SQLException {
        Connection connection = createConnection();
        try {
            connection.setAutoCommit(false);
            Statement statement = connection.createStatement();
            try {
                ResultSet results = statement.executeQuery(query);
                try {
                    List<E> list = fetchResultSet(results);
                    connection.commit();
                    return list;
                } finally {
                    results.close();
                }
            } finally {
                statement.close();
            }
        } catch (SQLException e) {
            connection.rollback();
            throw e;
        } finally {
            connection.close();
        }
    }

    protected void updateByQuery(String query) throws SQLException {
        Connection connection = createConnection();
        try {
            connection.setAutoCommit(false);
            Statement statement = connection.createStatement();
            try {
                statement.executeUpdate(query);
                connection.commit();
            } finally {
                statement.close();
            }
        } catch (SQLException e) {
            connection.rollback();
            throw e;
        } finally {
            connection.close();
        }
    }

    private void deleteByQuery(String query) throws SQLException {
        Connection connection = createConnection();
        try {
            connection.setAutoCommit(false);
            Statement statement = connection.createStatement();
            try {
                statement.executeUpdate(query);
                connection.commit();
            } finally {
                statement.close();
            }
        } catch (SQLException e) {
            connection.rollback();
            throw e;
        } finally {
            connection.close();
        }
    }

    private K insertByQuery(String query) throws SQLException {
        Connection connection = createConnection();
        try {
            connection.setAutoCommit(false);
            Statement statement = connection.createStatement();
            try {
                statement.executeUpdate(query);
                ResultSet keys = statement.executeQuery(selectLastInsertedEntityIDQuery());
                try {
                    keys.next();
                    K id = getLastInsertedEntityIDQuery(keys);
                    connection.commit();
                    return id;
                } finally {
                    keys.close();
                }
            } finally {
                statement.close();
            }
        } catch (SQLException e) {
            connection.rollback();
            throw e;
        } finally {
            connection.close();
        }
    }

}