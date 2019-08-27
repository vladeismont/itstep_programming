/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package dr.servlet;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

/**
 * Класс, предначненний для хранения значений атрибутов HTML-формы
 * и информации о корректности представленных в ней данных
 */
public class ModelState {

    private Map<String, AttributeState> attributesStates = new HashMap<String, AttributeState>();

    public boolean isValid() {
        for(AttributeState state : attributesStates.values()) {
            if (!state.isValid()) {
                return false;
            }
        }
        return true;
    }

    public void clear() {
        attributesStates.clear();
    }

    public AttributeState get(String attributeName) {
        return attributesStates.get(attributeName);
    }

    public void put(String attributeName, AttributeState attributeState) {
        attributesStates.put(attributeName, attributeState);
    }

    public boolean is(String attributeName) {
        return attributesStates.containsKey(attributeName);
    }

    public void remove(String attributeName) {
        attributesStates.remove(attributeName);
    }

    public List<String> getValidationMessages() {
        List<String> validationMessages = new LinkedList<String>();
        for (AttributeState attributeState : attributesStates.values()) {
            validationMessages.addAll(attributeState.getValidationMessages());
        }
        return validationMessages;
    }
        
}
