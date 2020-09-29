import React from 'react';
import './style.css';

export default function Input({inputProp, section, index, value}){

    return (
            <div className = {`input-wrapper input-wrapper--${inputProp.type} ${inputProp.hidden ? "hidden" : ""}`}
                  key={index}>
                <label  htmlFor={inputProp.name} 
                        className={`label label--${inputProp.name}`}>
                    {inputProp.item} 
                </label>
                <input  onChange={(e) => (e)} 
                        required = {inputProp.required} 
                        placeholder = {inputProp.placeholder} 
                        type = {inputProp.type} 
                        name = {inputProp.name} 
                        id = {inputProp.name}
                        hidden = {inputProp.hidden} 
                        className={`input--${inputProp.name}`} 
                        key={index}>                
                </input>
            </div>
        
    )
}
