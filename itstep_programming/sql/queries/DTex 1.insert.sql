insert into Drivers values
(1,'Sergey','Kremen',10),
(2,'Dmitriy','Len',5),
(3,'Igor','Kyznecov',25),
(4,'John','Cena',2);

insert into Cars values
(1234567890,'Opel','Nocta',20000,90),
(1342435213,'Daf','95',12000,54),
(1914595151,'Reno','Magnum',15000,68),
(1914925298,'Opel','Viec',14000,72);

insert into Cargo values
(101,'metall','rami',50,8000),
(102,'TV','ngparjnmaefo',54,5000),
(103,'PC','aliexpress',51,4000),
(104,'shini','belza',52,6000);

insert into Reisi values
(1001,(SELECT cargo_id from Cargo where cargo_id=101),
	(SELECT car_id from Cars where car_id=1234567890),
	(SELECT driver_id from Drivers where driver_id=1),'Minsk','Moscow'),
(1002,(SELECT cargo_id from Cargo where cargo_id=102),
	(SELECT car_id from Cars where car_id=1342435213),
	(SELECT driver_id from Drivers where driver_id=2),'Minsk','Grodno'),
(1003,(SELECT cargo_id from Cargo where cargo_id=103),
	(SELECT car_id from Cars where car_id=1914595151),
	(SELECT driver_id from Drivers where driver_id=3),'Borisov','Slonim'),
(1004,(SELECT cargo_id from Cargo where cargo_id=104),
	(SELECT car_id from Cars where car_id=1914925298),
	(SELECT driver_id from Drivers where driver_id=4),'Brest','Mogilev');