/****** Скрипт для команды SelectTopNRows из среды SSMS  ******/
select O.fio,O.ocenka , R.datez
from dbo.Raspisanie as R, dbo.Ocenky as O 
where O.idzan = R.idzan and O.gruppa = R.gruppa
  
order by fio,datez