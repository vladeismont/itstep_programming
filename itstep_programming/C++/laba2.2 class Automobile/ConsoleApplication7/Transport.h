#pragma once
class Transport
{
public:
	
	Transport();
	virtual~Transport();
	virtual void move() = 0;
};

