

const data = { 
    modal : 
         {   
            title : "keratin",
            intro : "expert",
            buttonText :  "закрыть",
            section : "offer"
         },
    
    
    header : {   
        logoTop : "keratin",
        logoBottom : "expert",
        heading :  "Кератиновое выпрямление волос",
        price :    "от $10 в минске",
        order :    "Получить консультацию"     

    },
    form : { 
        "section" : "modal",  
        "heading" : "Оставьте заявку и мы с Вами свяжемся",
        "intro" : "Ваши данные надежно защищены",
        inputs : [
            {   
                "value" : "",
                "item" : "Ваш телефон",
                "name":"customerPhone",
                "label":true,
                "required": "required",
                "type" : "tel",
                "placeholder": "+375 00 000 00 00",
                "hidden" : false,
                "valid" : true
            },
            {
                "value" : "",
                "item" : "Введите имя",
                "name":"customerName",
                "label":true,
                "required": "required",
                "type" : "text",
                "placeholder": "Иван Иванович",
                "hidden" : false,
                "valid" : true
            },
            {
                "value" : "",
                "item" : "Ваш Email",
                "name":"customerEmail",
                "label":true,
                "required": "required",
                "type" : "email",
                "placeholder": "some@some.com",
                "hidden" : false,
                "valid" : true
            },
            {
                "value" : "",
                "item" : "Ваше сообщение",
                "name":"customerMessage",
                "label":true,
                "required": "required",
                "type" : "textarea",
                "placeholder": "message",
                "hidden" : false,
                "valid" : true
            },
            {
                "value" : "header",
                "item" : "",
                "name":"fromSection",
                "label":true,
                "required": "required",
                "type" : "text",
                "placeholder": "",
                "hidden" : true,
                "valid" : true
            },
            {
                "value" : "jskoshelew@gmail.com",
                "item" : "",
                "name":"adminEmail",
                "label" : true,
                "required": "required",
                "type" : "email",
                "placeholder": "",
                "hidden" : true,
                "valid" : true
            },
            {
                "value" : "Отправить",
                "item" : "",
                "name":"fromSubmit",
                "label":true,
                "required": "required",
                "type" : "submit",
                "placeholder": "",
                "hidden" : false,
                "valid" : true
            }


        ]       

    },
    content : [
        {   
            "link": "offer",
            "title": "Что такое кератиновое выпрямление",
            "item": "Что это",
            "type" : "article",
            articles: [
                {
                    "text" : "This is Photoshop's version  of Lorem Ipsum. Proin gravida nibh vel velit auctor aliquet. Aenean sollicitudin, lorem quis bibendum auctor, nisi elit consequat ipsum, nec sagittis sem nibh id elit. "
                },
                {
                    "text" : "Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Mauris in erat justo. Nullam ac urna eu felis dapibus condimentum sit amet a augue. Sed non neque elit. Sed ut imperdiet nisi. "
                }
            ]     
    
        },
        {
            "link": "merits",
            "title": "Преимущества кератинового выпрямления",
            "item": "Преимущества",
            "type" : "article",
            articles: [
                {
                    "heading": "Универсальность",
                    "text" : "Процедура подходит для абсолютно всех типов волос"
                },
                {
                    "heading": "Полезность",
                    "text" : "Кератин - натуральный белок, оказывает на волосы лечебное воздействие"
                },
                {
                    "heading": "Эффективность",
                    "text" : "Волосы остаются прямыми достаточно долго - от 3 до 6 месяцев"
                },
                {
                    "heading": "Комфорт",
                    "text" : "Вы будете тратить минимум усилий на укладку"
                }
            ]   
        },
        {
            "link": "procedure",
            "title": "Этапы процедуры",
            "item": "Этапы процедуры",
            "type" : "article",
            articles: [
                {
                    "text" : "This is Photoshop's version  of Lorem Ipsum. Proin gravida nibh vel c sagittis suris vitae erat consequat auctor.This is Photoshop's version  of Lorem Ipsum. "
                },
                {
                    "text" : "This is Photoshop's version  of Lorem Ipsum. Proin gravida nibh vel c sagittis suris vitae erat consequat auctor.This is Photoshop's version  of Lorem Ipsum. "
                },
                {
                    "text" : "This is Photoshop's version  of Lorem Ipsum. Proin gravida nibh vel c sagittis suris vitae erat consequat auctor.This is Photoshop's version  of Lorem Ipsum. "
                },
                {
                    "text" : "This is Photoshop's version  of Lorem Ipsum. Proin gravida nibh vel c sagittis suris vitae erat consequat auctor.This is Photoshop's version  of Lorem Ipsum. "
                }
            ]   
    
        },
        {
            "link": "portfolio",
            "title": "Портфолио",
            "item": "Портфолио",
            "type" : "slider",
            "dotted" : false,
            "carousel" : false,            
            slides:[
                {
                    "path" : "slides1/slider11.jpg",
                    "title" : "блондинка улыбается",
                    "index" : 0,
                    "intro" : "Анна Иванова",
                    "type"  : "Brasil Cacau",
                    "statement"	: "Unlike favicon.ico or favicon.ico, %PUBLIC_URL%/favicon.ico will work correctly both with client-side routing and a non-root public URL. Learn how to configure a non-root public URL by running `npm run build`."

                },
                {
                    "path" : "slides1/slider12.jpg",
                    "title" : "блондинка улыбается",
                    "index" : 1,
                    "intro" : "Александра Иванова",
                    "type"  : "gloss",
                    "statement"	: "Unlike favicon.ico or favicon.ico, %PUBLIC_URL%/favicon.ico will work correctly both with client-side routing and a non-root public URL. Learn how to configure a non-root public URL by running `npm run build`."

                },
                {
                    "path" : "slides1/slider13.jpg",
                    "title" : "блондинка улыбается",
                    "index" : 2,
                    "intro" : "Виктория Иванова",
                    "type"  : "gold label",
                    "statement"	: "This is Photoshop's version  of Lorem Ipsum. Aenean sollicitudin, lorem quis bibendum auctor, nisi elit consequat ipsum, nec sagittis sem nibh id elit. Duis sed odio sit amet nibh vulputate cursus a sit amet mauris."

                },
                {
                    "path" : "slides1/slider14.jpg",
                    "title" : "блондинка улыбается",
                    "index" : 3,
                    "intro" : "Наталья Иванова",
                    "type"  : "Lisap ultimate",
                    "statement"	: "This is Photoshop's version  of Lorem Ipsum. Aenean sollicitudin, lorem quis bibendum auctor, nisi elit consequat ipsum, nec sagittis sem nibh id elit. Duis sed odio sit amet nibh vulputate cursus a sit amet mauris."

                },
                {
                    "path" : "slides1/slider15.jpg",
                    "title" : "блондинка улыбается",
                    "index" : 4,
                    "intro" : "Лариса Иванова",
                    "type"  : "keratin evoque",
                    "statement"	: "This is Photoshop's version  of Lorem Ipsum. Aenean sollicitudin, lorem quis bibendum auctor, nisi elit consequat ipsum, nec sagittis sem nibh id elit. Duis sed odio sit amet nibh vulputate cursus a sit amet mauris."

                },
                {
                    "path" : "slides1/slider16.jpg",
                    "title" : "блондинка улыбается",
                    "index" : 5,
                    "intro" : "Марина Иванова",
                    "type"  : "keratin boost",
                    "statement"	: "This is Photoshop's version  of Lorem Ipsum. Aenean sollicitudin, lorem quis bibendum auctor, nisi elit consequat ipsum, nec sagittis sem nibh id elit. Duis sed odio sit amet nibh vulputate cursus a sit amet mauris."

                }
                
            ]   
        },
        {
            "link": "notice",
            "title": "Отзывы клиентов",
            "item": "Отзывы",
            "type" : "carousel",
            "dotted" : true,
            "carousel" : true,            
            slides:[
                {
                    "path" : "slides2/slider11.jpg",
                    "title" : "блондинка улыбается",
                    "index" : 0,
                    "intro" : "Анна Ивановна",
                    "statement"	: "Unlike favicon.ico or favicon.ico, %PUBLIC_URL%/favicon.ico will work correctly both with client-side routing and a non-root public URL. Learn how to configure a non-root public URL by running `npm run build`."

                },
                {
                    "path" : "slides2/slider12.jpg",
                    "title" : "блондинка улыбается",
                    "index" : 1,
                    "intro" : "Александра Ивановна",
                    "statement"	: "Unlike favicon.ico or favicon.ico, %PUBLIC_URL%/favicon.ico will work correctly both with client-side routing and a non-root public URL. Learn how to configure a non-root public URL by running `npm run build`."

                },
                {
                    "path" : "slides2/slider13.jpg",
                    "title" : "блондинка улыбается",
                    "index" : 2,
                    "intro" : "Виктория Ивановна",
                    "type"  : "коллега",
                    "statement"	: "This is Photoshop's version  of Lorem Ipsum. Aenean sollicitudin, lorem quis bibendum auctor, nisi elit consequat ipsum, nec sagittis sem nibh id elit. Duis sed odio sit amet nibh vulputate cursus a sit amet mauris."

                },
                {
                    "path" : "slides2/slider14.jpg",
                    "title" : "блондинка улыбается",
                    "index" : 3,
                    "intro" : "Наталья Ивановна",
                    "type"  : "клиент",
                    "statement"	: "This is Photoshop's version  of Lorem Ipsum. Aenean sollicitudin, lorem quis bibendum auctor, nisi elit consequat ipsum, nec sagittis sem nibh id elit. Duis sed odio sit amet nibh vulputate cursus a sit amet mauris."

                },
                {
                    "path" : "slides2/slider15.jpg",
                    "title" : "блондинка улыбается",
                    "index" : 4,
                    "intro" : "Лариса Ивановна",
                    "type"  : "клиент",
                    "statement"	: "This is Photoshop's version  of Lorem Ipsum. Aenean sollicitudin, lorem quis bibendum auctor, nisi elit consequat ipsum, nec sagittis sem nibh id elit. Duis sed odio sit amet nibh vulputate cursus a sit amet mauris."

                },
                {
                    "path" : "slides2/slider16.jpg",
                    "title" : "блондинка улыбается",
                    "index" : 5,
                    "intro" : "Марина Ивановна",
                    "type"  : "коллега",
                    "statement"	: "This is Photoshop's version  of Lorem Ipsum. Aenean sollicitudin, lorem quis bibendum auctor, nisi elit consequat ipsum, nec sagittis sem nibh id elit. Duis sed odio sit amet nibh vulputate cursus a sit amet mauris."

                }                
            ]    
        },

        {
            "link": "price",
            "title": "Стоимость процедуры",
            "item": "Стоимость",
            "type" : "article",
            articles: [
                {
                    "text" : "Стоимость выпрямления зависит от таких факторов, как длина, густота волос. Мастеру необходимо также знать, повреждены ли волосы, какие  процедуры уже были проведены (окрашивания, завивки и т.д.). "
                },
                {
                    "text" : "Точную информацию о цене и ответы на другие интересующие Вас вопросы можно получить в ходе бесплатной консультации у специалиста по кератиновому выпрямлению  волос."
                }
            ]   
        }
    
    ],
    contacts : {   
        "heading" : "Остались вопросы?",
        "intro" : "Мы вам перезвоним",
        "message" : "Ваше сообщение отпривлено",
        "message2" : "C вами свяжутся наши консультанты",
        inputs : [
            {   
                "value" : "",
                "item" : "Ваш телефон",
                "name":"customerPhone",
                "label":true,
                "required": "required",
                "type" : "tel",
                "placeholder": "Ваш телефон",
                "hidden" : false,
                "valid" : true
            },
            {
                "value" : "",
                "item" : "Введите имя",
                "name":"customerName",
                "label":true,
                "required": "required",
                "type" : "text",
                "placeholder": "Ваше имя",
                "hidden" : false,
                "valid" : true
            },            
            {
                "value" : "Footer",
                "item" : "",
                "name":"fromSection",
                "label":true,
                "required": "required",
                "type" : "text",
                "placeholder": "",
                "hidden" : true,
                "valid" : true
            },
            {
                "value" : "jskoshelew@gmail.com",
                "item" : "",
                "name":"adminEmail",
                "label" : true,
                "required": "required",
                "type" : "email",
                "placeholder": "jskoshelew@gmail.com",
                "hidden" : true,
                "valid" : true
            },
            {
                "value" : "",
                "item" : "",
                "name":"fromSubmit",
                "label":true,
                "required": "required",
                "type" : "submit",
                "placeholder": "",
                "hidden" : false,
                "valid" : true
            }


        ]       

    },
    consultation : {   
        section: "consultation",
        order :  "Получить консультацию"     

    },   
    mapPoints : [
        [53.896883, 27.550809],
        [53.927331, 27.687496],
        [53.906644, 27.458462],
        [53.901037, 27.481647]
    ],
    bottomForm : {   
        "heading" : "Остались вопросы?",
        "intro" : "Мы вам перезвоним",
        inputs : [            
            {   
                "value" : "",
                "item" : "",
                "name":"customerName",
                "label":true,
                "required": "required",
                "type" : "text",
                "placeholder": "Ваше имя",
                "hidden" : false,
                "valid" : true
            },
            {   
                "value" : "",
                "item" : "",
                "name":"customerPhone",
                "label":true,
                "required": "required",
                "type" : "tel",
                "placeholder": "Ваш телефон",
                "hidden" : false,
                "valid" : true
            },            
            {
                "value" : "bottom Form",
                "item" : "",
                "name":"fromSection",
                "label":true,
                "required": "required",
                "type" : "text",
                "placeholder": "",
                "hidden" : true,
                "valid" : true
            },
            {
                "value" : "jskoshelew@gmail.com",
                "item" : "",
                "name":"adminEmail",
                "label" : true,
                "required": "required",
                "type" : "email",
                "placeholder": "",
                "hidden" : true,
                "valid" : true
            },
            {
                "value" : "Заказать звонок",
                "item" : "",
                "name":"fromSubmit",
                "label":true,
                "required": "required",
                "type" : "submit",
                "placeholder": "",
                "hidden" : false,
                "valid" : true
            }


        ]       

    },
    footer : {   
        logoTop : "keratin",
        logoBottom : "expert",
        law :  "2017 / Все права защищены",
        buttonText :    "Наверх",
        phone :    "+375 25 000 00 00",

    }


}
export default data;
