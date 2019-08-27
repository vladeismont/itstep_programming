#pragma once
class CrosswordSolver
{
public:
	CrosswordSolver();
	~CrosswordSolver();
	void getAllWithLen(const int n);
	void getAllWithInit(const char c);
	void findByMask(const std::string s);
	void getAnagrams(std::string s);
};

