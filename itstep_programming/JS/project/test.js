function test(){
	if(!window.timesRun){
	alert("first run!")
	timesRun=1
	} else{
	timesRun++
	console.log("запуск номер "+timesRun)
	}
}