/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package dr.domainmodel.repository.base;

import java.sql.SQLException;
import java.util.List;

/**
 *
 * @author Альтернативний
 */
public interface BaseRepository<E, K> {

    List<E> select() throws SQLException ;
    E selectByID(K id) throws SQLException ;
    E insert(E entity) throws SQLException ;
    E update(E entity) throws SQLException ;
    void delete(K id) throws SQLException ;

}
