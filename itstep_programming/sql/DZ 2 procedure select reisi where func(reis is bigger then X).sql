alter procedure select_Reisi(@id int)
as
begin
	select * from dbo.func_select_all(@id)
end;