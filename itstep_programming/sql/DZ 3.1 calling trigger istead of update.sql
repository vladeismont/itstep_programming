insert into Reisi values
(1001,(SELECT cargo_id from Cargo where cargo_id=101),
	(SELECT car_id from Cars where car_id=1234567890),
	(SELECT driver_id from Drivers where driver_id=1),'Minsk','Moscow');
	insert into Reisi values
(1002,(SELECT cargo_id from Cargo where cargo_id=102),
	(SELECT car_id from Cars where car_id=1342435213),
	(SELECT driver_id from Drivers where driver_id=2),'Minsk','Grodno');
	insert into Reisi values
(1003,(SELECT cargo_id from Cargo where cargo_id=103),
	(SELECT car_id from Cars where car_id=1914595151),
	(SELECT driver_id from Drivers where driver_id=3),'Borisov','Slonim');
	insert into Reisi values
(1004,(SELECT cargo_id from Cargo where cargo_id=104),
	(SELECT car_id from Cars where car_id=1914925298),
	(SELECT driver_id from Drivers where driver_id=4),'Brest','Mogilev');

update Passengers --calling update_trigger
   set lastname='game over'
   where passengers.id=37 or passengers.id=38;