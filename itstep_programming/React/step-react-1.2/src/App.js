import React, {Component} from 'react';
//import CSSModules from 'react-css-modules';
//import  { BrowserRouter, Route, Switch } from 'react-router-dom';
//import 'normalize.css';
import styles from "./App.css";
import data from './data'
import Form from './components/Form';
import Button from './components/Button';
import Articles from './components/Articles';
import Article from './components/Article';
import Modal from './components/Modal';



//const FourOhFour = () => <h1>404</h1>;
const {modal, header, form, namebox, content, contacts, consultation, mapPoints, bottomForm, footer} = data;

const {logoTop, logoBottom, heading, price, order}=header;
// const logoTop=header.logoTop; 5 раз


class App extends Component{
    constructor(props){
        super(props)
        this.state = {
           formOpen: false,
           modalOpen: false
        }
        this.formButtonClick = this.formButtonClick.bind(this)
       
    }
    
    render(){      
        const newForm = this.state.formOpen && 
        <section className = "modal-section"> <Form {...form} clickHandler={this.formButtonClick}/> </section> 
        
        const newModal = this.state.modalOpen && 
        <Modal {...modal} clickHandler={this.modalButtonClick}/>

        const articleSections = content.map((item,index)=>(item.type=="article")?
        <Articles{...item} key={index}/>
        :<div>Тут будет слайдер</div>)    

        return(
            <React.Fragment>

                <header className="header">
                    <div className="logo__wrapper">
                        <div className="logo__top">
                        {/* header.logo__top */}
                            {logoTop}
                        </div>
                        <div className="logo__bottom">
                            {logoBottom}
                        </div>
                    </div>
                    <h1 className="header_heading">
                        {heading}
                    </h1>
                    <p className="header_offer">
                        {price}
                    </p>
                </header>

                <Button text={order} clicker={this.formButtonClick} section="main"/>
                {articleSections}
                {newForm}

                <Button text="открыть модальное окно" clicker={this.modalButtonClick} section="form"/>

                {newModal}                
                {/* <Article {...content[1].articles[0]} section="test"/> */}
                <Articles {...content[1]} section="test"/> 

            </React.Fragment> 
        )
    }
    
    formButtonClick = () =>  {this.setState({formOpen: !this.state.formOpen })}

    modalButtonClick = () =>  {this.setState({modalOpen: !this.state.modalOpen })}
}

export default App;

//export default CSSModules(App, styles);
// const {header, form, content, contacts, consultation, mapPoints, bottomForm, footer} = data;
    // const Sections = content.map((contentProp, index) =>
    //     <section id = {`${contentProp.link}`} className = {`${contentProp.link}`} key={index}>
    //         {(contentProp.type === "article") ? <Article {...contentProp}/>  : ((contentProp.type === "carousel") ?
    // <Carousel {...contentProp}/> : <PartSlider />/{...contentProp}/>)}    
    //     </section> 
    // )

// eslint-disable-next-line
{/* <Header  {...header} form = {form} content = {content}/>
<BrowserRouter>    
    <div className='app'>
    <Switch>
        < Route exact path = "/" component = { Article } /> 
        < Route path = "/search" component = { Search } />
        < Route path = "/about" component = { About } />
        < Route  component = { FourOhFour } /> 
        </Switch>       
    </div>
</BrowserRouter>
{ Sections }
<Consultation {...consultation} {...form}/>
<MapSection points = {mapPoints}/>                
<section className = "bottom-form">
    <Form form = {bottomForm} formToggle = {f=>f} section="bottom-form"/>
</section>
<footer id="footer" className="footer">
    <Footer {...footer}/>
</footer>  */}
