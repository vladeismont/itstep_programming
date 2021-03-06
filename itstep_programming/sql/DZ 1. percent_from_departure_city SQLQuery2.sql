USE [DTex]
GO
/****** Object:  StoredProcedure [dbo].[percent_from_Departure_City]    Script Date: 12/16/2017 11:22:46 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER procedure [dbo].[percent_from_Departure_City] -- % вывоза из города
@city nchar(100)
as
begin TRY  
   BEGIN TRANSACTION 
	declare @count_departure_city int,
	@count_reisi int,	
	@out_result DECIMAL(5,2)
	set @count_departure_city= (select count(departure_point) from Reisi where departure_point=@city);
	set @count_reisi=(select count(departure_point) from Reisi);
	set @out_result =(convert(decimal(5,2),@count_departure_city))/@count_reisi*100;

	IF EXISTS (SELECT * FROM reis_from_cities WHERE city=@city)
		UPDATE reis_from_cities SET perct=@out_result WHERE city=@city
	ELSE
		INSERT INTO reis_from_cities VALUES (@city,@out_result);

	COMMIT 
END TRY

BEGIN CATCH  
  -- Determine if an error occurred.  
  IF @@TRANCOUNT > 0  
     ROLLBACK  

  -- Return the error information.  
  DECLARE @ErrorMessage nvarchar(4000),  @ErrorSeverity int;  
  SELECT @ErrorMessage = ERROR_MESSAGE(),@ErrorSeverity = ERROR_SEVERITY();  
  RAISERROR(@ErrorMessage, @ErrorSeverity, 1);  
END CATCH;  