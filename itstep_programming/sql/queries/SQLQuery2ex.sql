--select * from dbo.Zakaz
--where idZakaza=1;

--Update dbo.Zakaz set Amnt = kol * 
--(select cena from dbo.Product  
--  where product_id = idProd ) 
 -- where idZakaza=1 

-- select Z.idZakaza,Z.idCust,Z.idProd,Z.kol,Z.Amnt,
--   P.disc,P.kol ,
--   Z.Skidka, Z.Summa 
--   from dbo.Zakaz as Z, dbo.Product as P 
--where Z.idProd = P.product_id 
--order by idProd,idCust 

--Update dbo.Zakaz set Skidka=0 ;
--Update dbo.Zakaz set Summa = Amnt - Skidka ;

-- Update 3 1 1005 ,  4 3 1009

        select idZakaza,idCust,idProd, kol from dbo.Zakaz   
         where (idCust=1 and idProd=1005) or (idCust=3 and idProd=1009)  
		 order by idProd,idZakaza;
   
 Update dbo.Zakaz set Skidka = Amnt * disc/100  		-- select for disc from Product needed
 where (idZakaza=3 and idCust=1 and idProd=1005) or 
       (idZakaza=4 and idCust=3 and idProd=1009)  ; 

 select Z.idZakaza,Z.idCust,Z.idProd,Z.kol,Z.Amnt,
   P.disc,P.kol ,
   Z.Skidka, Z.Summa 
   from dbo.Zakaz as Z, dbo.Product as P 
where Z.idProd = P.product_id 
order by idCust,idProd,idZakaza 
--order by idZakaza,idCust,idProd 


