import React from 'react';
import Article from '../Article';




export default function Articles({link, title, item, type, articles}){ //articles = link, title, item, type, articles
        console.log(articles)

        const articleItems = articles.map((prop, index) =>
            // <li className="article__list-item" key={index}>
            //     <h4 className="article__list-item-heading">{prop.heading}</h4>                      
            //     <p className="article__list-text">{prop.text} </p>
            // </li>
            <Article {...prop} key={index} section={link}/>
        )
        return (
            <section id="link"  className={`article__list ${link}__article--list`}>
            
                <h5   className={`article__heading ${link}__article--heading`}>
                    {title}
                </h5>
                {articleItems}
            </section>
        )

    }
