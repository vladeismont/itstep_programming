import React from 'react';
import './style.css';

const Modal = ({title, section, intro, buttonText, clickHandler})=>{

    return (
            <div className = {`modal modal--${section}`}>
                <h1>{title}</h1>
                <p>{intro}</p>
                <button className={`modal__button modal__button--${section}`} 
                          onClick={clickHandler}> 
                {buttonText}               
                </button>
            </div>
        
    )
}

export default Modal
