import React, {Component} from 'react';
import './style.css';

export default function Article(props){  
    
        const {heading, text, section} = props;
        //console.log('props',props);
        return(        
            
            <article className={`article__wrapper ${section}__wrapper `}>
                <h5 className={`article__heading ${section}__heading `}>
                    {heading}
                </h5>
                <p className={`article__paragraph ${section}__paragraph `}>
                    {text}
                </p>
            </article>

            
        )
    }
