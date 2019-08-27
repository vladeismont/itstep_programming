create function dbo.func_select_all(@x int)
returns table
as
return(select * from Reisi where Reisi.reis_id>@x);