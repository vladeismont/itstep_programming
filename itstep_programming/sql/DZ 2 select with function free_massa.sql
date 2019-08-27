select Reisi.reis_id, marka, model, Cargo.massa, Cargo.v3_size, dbo.free_space(Cars.gryzopodjemnost,Cargo.massa) as free_massa
from Reisi inner join Cars on Reisi.car_id=Cars.car_id inner join Cargo on Reisi.cargo_id=Cargo.cargo_id
where Reisi.reis_id=1001;