select firstname, lastname, numPhones
from People

Select    AVG(Cast(numPhones as Float)) as average
From    People

select firstname, lastname, numPhones
from People
where numPhones<(select avg(cast(numPhones as float)) from People)

select phone
from Phones
where phone=REVERSE(phone)