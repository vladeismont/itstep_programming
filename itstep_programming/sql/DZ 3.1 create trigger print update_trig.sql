create trigger update_trigger on Passengers
instead of update
as
begin
 print 'calling update_trigger';
end;