create function free_space(@x int, @mas int)
returns int
as 
begin
return @x-@mas
end;