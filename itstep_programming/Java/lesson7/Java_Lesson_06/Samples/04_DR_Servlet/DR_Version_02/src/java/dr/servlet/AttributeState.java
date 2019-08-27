/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package dr.servlet;

import java.util.LinkedList;
import java.util.List;

/**
 *
 * @author Альтернативний
 */
public class AttributeState {

    private String name;
    private String value;

    private List<String> validationMessages = new LinkedList<String>();

    public AttributeState() {
    }

    public AttributeState(String name, String value) {
        this.name = name;
        this.value = value;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        this.value = value;
    }

    public List<String> getValidationMessages() {
        return validationMessages;
    }

    public boolean isValid() {
        return validationMessages.isEmpty();
    }
    
}
