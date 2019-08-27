/**
 * Created by st on 10.10.2018.
 */
var  list={
    test1:"value1",
    test2:"value2",
    test3:"value3",
    test4:{test5:"value5"}
};
var ul = document.getElementById("test1ul");
for(var i in list){

    if(typeof list[i]=="object"){
        var nul=list[i],
            newUl = document.createElement('ul');
        ul.appendChild(newUl);
        for(j in nul){
            func(newUl, nul,j);
        }
    }
    else {
        func(ul, list,i);
    }
}
/*navigator,
screen,
location*/
function func(container, list,i){
    let info = document.createElement("li");
    info.innerText = list[i];
    container.appendChild(info);
}
document.getElementById("bom").innerHTML =
    "Page location is " + window.location.href;

Date.prototype.daysInMonth = function() {
    return 32 - new Date(this.getFullYear(), this.getMonth(), 32).getDate();
};
var date1 = new Date();
console.log(date1.daysInMonth());


document.getElementById("count").innerHTML =
    "days count " + date1.daysInMonth();

document.getElementById("count").innerHTML +=
    ". current day is " + date1.getDay();



var enumDayCh=['0','1','2',"3","4","5","6"];
var enumDayInt=["mon","tue","wed","thu","fri","sat","sun"];


var divCalendar = document.getElementById("calendar");

var ObjCurrentDay=date1.getDay();
var objCurrentMonth=function () {

    this.id=date1.daysInMonth();
}
var objCurMonth=new objCurrentMonth();
function myFunction() {
    divCalendar.innerHTML='';


    console.log(objCurMonth.id);
    for(var k=1; k<=objCurMonth.id;++k ){
        let infoDay = document.createElement("div");
        infoDay.innerHTML=k;
        divCalendar.appendChild(infoDay);
    }

}
function increaseMonth() {
    id+=1;
    let date2=new Date(2018,id);
    objCurMonth.id=date2.daysInMonth();
    console.log(objCurMonth.id);
    myFunction();

}
function dencreaseMonth() {
    id-=1;
    let date2=new Date(2018,id);
    objCurMonth.id=date2.daysInMonth();
    console.log(objCurMonth.id);
    myFunction();
}
var id=date1.getMonth();

objCurrentMonth();
myFunction();

for(var i = 0; i < 10; i++) {
    console.log('+i='+i);
}

for(var l = 0; l < 10; l++) {
    console.log('l='+l);
    setTimeout(function() {
        console.log('The l number is ' + l);
    },100);
}
console.log('last l='+l);
console.log('for cycle using let increment');
for(let m = 0; m < 10; m++) {
    console.log('m='+m);
    setTimeout(function() {
        console.log('The m number is ' + m);
    },1000);
}
