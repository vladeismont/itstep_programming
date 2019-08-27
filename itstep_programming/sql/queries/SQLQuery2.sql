select Z.id_zakaza,Z.id_cust,Z.id_products,Z.quantity,
       P.quantity_na_discount,P.cena_kg,P.DiscountPercentage, 
	   P.cena_kg*P.DiscountPercentage/100 as skidka
	   from dbo.Zakazy as Z, dbo.Products as P
	   where Z.id_zakaza = 3 
	   and Z.id_products = P.product_id 