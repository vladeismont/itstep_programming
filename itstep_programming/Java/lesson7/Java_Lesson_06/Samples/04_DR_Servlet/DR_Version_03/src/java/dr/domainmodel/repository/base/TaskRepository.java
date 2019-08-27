/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package dr.domainmodel.repository.base;

import dr.domainmodel.entities.Task;
import java.math.BigDecimal;
import java.sql.SQLException;
import java.util.Date;
import java.util.List;

/**
 *
 * @author Альтернативний
 */
public interface TaskRepository extends BaseRepository<Task, Integer> {
    List<Task> selectByDate(Date date) throws SQLException;
    BigDecimal selectTotalHoursByDate(Date date) throws SQLException;
}
