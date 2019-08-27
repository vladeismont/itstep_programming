select distinct O1.fio from dbo.View_Zan as O1
where (select ocenka  from dbo.View_Zan as O2
			where O1.fio=O2.fio and O2.datez = (select max(O4.datez) from dbo.View_Zan as O4 
													where O2.fio=O4.fio 
											   ) 
	  )
    < (select ocenka  from dbo.View_Zan as O5
			where O1.fio=O5.fio and O5.datez = (select min(O6.datez) from dbo.View_Zan as O6 
													where O5.fio=O6.fio 
											   ) 
	  )
--3. Выявить студентов, успеваемость которых упала за последнее время