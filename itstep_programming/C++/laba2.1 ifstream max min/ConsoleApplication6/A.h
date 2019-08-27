#pragma once
class A
{
	int value;
public:
	int getValue() const;
	void setValue(int x);
	/*A();
	~A();*/
};
inline int A::getValue()const{
	return value;
}
inline void A::setValue(int x){
	value = x;
}