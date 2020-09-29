import React, {Component} from 'react';
import Input from '../Input';


import './style.css';
import Button from '../Button';

export default function Form(props){
   
        const {section, heading, intro, inputs, clickHandler} = props;       
        
        const Inputs = inputs.map((inputProp, index) => <Input inputProp = {inputProp}
            section = {section} 
            index = {index}
            key = {index}
            value = {inputProp.value} 
            />);

        return(        
            <React.Fragment >
                <h2 className = {`${section}__heading`}>
                  {heading}
                </h2>
                <p className = {`${section}__intro`}>
                  {intro}
                </p>
                <Button text = "закрыть" clicker = {clickHandler} section="form"/>
                <form className = {`${section}__form form`}>
                    
                    {Inputs}
                </form>                
            </React.Fragment> 
        )
    }
        
    
    
    

    

    // handleInputChange(e, index) {
    //     let type = e.target.type;        
    //     let value = e.target.value;
    //     let inputPropsValid = this.state.inputPropsValid;
    //     let inputPropsValue = this.state.inputPropsValue;
    //     let Valid = false;
    //     switch(type) {
    //         case 'email':
    //             Valid = !!(value.match(/(http(s)?:\/\/.)?(www\.)?[-a-zA-Z0-9@:%_\+~#=]{2,256}\.[a-z]{2,6}\b([-a-zA-Z0-9@:%_\+.~#?&//=]*)/g));
    //         break;            
    //         case 'textarea':
    //             Valid = !!(value.match(/^[0-9+\(\)#\.\s\/ext-]+$/g));
    //         break;
    //         case 'text':
    //             Valid = !!(value.match(/([a-zA-Z]*)/g));
    //         break;
    //         case 'tel':
    //             Valid = !!(value.match(/^[0-9+\(\)#\.\s\/ext-]+$/g));
    //         break;              
    //         default:
    //         break;
    //     }        
    //     inputPropsValid[index] = Valid;
    //     inputPropsValue[index] = value;
    //     this.setState({inputPropsValid, inputPropsValue});        
    // }
    
    // handleSubmit(e) {
    //     e.preventDefault();        
    //     if(this.state.inputPropsValid.every((value) => value)){
    //         alert(this.state.inputPropsValue)
    //     }
    //     this.props.formToggle();        
    // }

    // clearInput(index) {        
    //     let inputPropsValue = this.state.inputPropsValue;
    //     let inputPropsValid = this.state.inputPropsValid;
    //     inputPropsValue[index]="";
    //     inputPropsValid[index]=false;
    //     this.setState({inputPropsValid, inputPropsValue});        
    // }

