alter TRIGGER dbo.insert_reis_message
ON dbo.Reisi
after INSERT -- for Тоже самое
AS
BEGIN try
begin transaction
 insert into Passengers values('Ivan','Petrov'); --creating 4 ivan petrov
   --declare @str nchar(122);
   --select @str='Prinyat novij reis v '
   --+(select destination_point from Reisi where Reisi.reis_id = (select max(reis_id)from Reisi));
   --print @str;
   commit
END try
BEGIN CATCH   
  IF @@TRANCOUNT > 0  
     ROLLBACK   
  DECLARE @ErrorMessage nvarchar(4000),  @ErrorSeverity int;  
  SELECT @ErrorMessage = ERROR_MESSAGE(),@ErrorSeverity = ERROR_SEVERITY();  
  RAISERROR(@ErrorMessage, @ErrorSeverity, 1);  
END CATCH;