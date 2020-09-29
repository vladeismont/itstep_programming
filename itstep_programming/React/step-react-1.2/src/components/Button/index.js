import React, {Component} from 'react';
import './style.css';

export default function Button({text, clicker, section}/*props*/ ){  
    
        //const {text, clicker, section} = props;
        //console.log('props',props);
        return(        
            <button className={`button button__${section} `} onClick = {clicker}>
                {text}               
            </button> 
        )
    }
