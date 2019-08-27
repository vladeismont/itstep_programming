#include "stdafx.h"
#include "CrosswordSolver.h"

bool isAnagram(std::string str1, std::string str2) {
	if (str1.length() != str2.length())return 0;
	for (size_t i = 0; i < str1.length() - 1; i++) {
		for (size_t j = 0; j < str1.length() - i - 1; j++) {
			if ((size_t)str1[j] >(size_t)str1[j + 1]) {
				// меняем элементы местами
				char temp = str1[j];
				str1[j] = str1[j + 1];
				str1[j + 1] = temp;
			}
		}
	}
	for (size_t i = 0; i < str2.length() - 1; i++) {
		for (size_t j = 0; j < str2.length() - i - 1; j++) {
			if (str2[j] > str2[j + 1]) {
				// меняем элементы местами
				char temp = str2[j];
				str2[j] = str2[j + 1];
				str2[j + 1] = temp;
			}
		}
	}		
	if (str1 == str2)return 1;	// or sort()
	else return 0;
};

CrosswordSolver::CrosswordSolver()
{
}


CrosswordSolver::~CrosswordSolver()
{
}

void CrosswordSolver::getAllWithLen(const int n){
	std::ifstream in;
	in.open("Lopatin_dictionary.txt");
	if (!in.is_open()) {
		std::cout << "File not found" << std::endl;
		return ; //exit(1);
	}
	std::ofstream fout("output getAllWithLen.txt");
	if (!fout.is_open()) // если файл небыл открыт 
	{
		std::cout << "file не может быть открыт или создан\n";
		return;
	}
	std::string str;
	while (in >> str){
		if (str.length() == n){
			fout << str << std::endl;
		}
	}
	in.close();
	fout.close();
}

void CrosswordSolver::getAllWithInit(const char c){
	std::ifstream in;
	in.open("Lopatin_dictionary.txt");
	if (!in.is_open()) {
		std::cout << "File not found" << std::endl;
		return; //exit(1);
	}

	std::ofstream fout("output getAllWithInit.txt");
	if (!fout.is_open()) // если файл небыл открыт 
	{
		std::cout << "file не может быть открыт или создан\n";
		return;
	}
	std::string str;
	while (in >> str){
		if (str[0]==c){
			fout << str << std::endl;
		}
	}
	in.close();
	fout.close();
}

void CrosswordSolver::findByMask(const std::string s){
	std::ifstream in;
	in.open("Lopatin_dictionary.txt");
	if (!in.is_open()) {
		std::cout << "File not found" << std::endl;
		return; //exit(1);
	}
	
	std::vector<std::string> mystr;
	std::vector<std::string> mystr1;
	std::string str;
	std::string tmp;	// for *ооружен*		//use npos
	if (s[0] == '*' && s[s.length() - 1] == '*'){
		for (int i = 0; i < s.length(); ++i) tmp += s[i + 1];
	}
	else
		if (s[0] == '*'){
			for (int i = 0; i < s.length(); ++i) tmp += s[i + 1];
		}
		if (s[s.length() - 1] == '*'){
			for (int i = 0; i < s.length() - 1; ++i) tmp += s[i + 1];
		}
		else{
			tmp = s;
		}

	while (in >> str){
		size_t i = str.length();
		int f = 0;
		for (size_t j = 0; j<i; ++j){
			if (tmp[j] == str[j] || tmp[j] == '?'){
				f++;
			}
			else
				break;
		}
		if (f == tmp.length() && s.length()==str.length()){
			mystr.push_back(str);
		}
		size_t pos = str.find(tmp);
		if (pos != std::string::npos)
			mystr1.push_back(str);
	}
	if (mystr.size() < 20){
		std::vector<std::string>::size_type sz = mystr.size();
		for (unsigned i = 0; i < sz; ++i){
			std::cout << mystr[i] << std::endl;
		}
	}
	else{
		std::vector<std::string>::size_type sz = mystr.size();
		std::ofstream fout("output findByMask.txt");
		if (!fout.is_open()) // если файл небыл открыт 
		{
			std::cout << "file не может быть открыт или создан\n";
			return;
		}
		for (unsigned i = 0; i < sz; ++i){
			fout << mystr[i] << std::endl;
		}
		fout.close();
	}
	if (mystr1.size() < 20){
		std::vector<std::string>::size_type sz = mystr1.size();
		for (unsigned i = 0; i < sz; ++i){
			std::cout << mystr1[i] << std::endl;
		}
	}
	else{
		std::vector<std::string>::size_type sz = mystr1.size();
		std::ofstream fout1("output findByMask1.txt");
		if (!fout1.is_open()) // если файл небыл открыт 
		{
			std::cout << "file не может быть открыт или создан\n";
			return;
		}
		for (unsigned i = 0; i < sz; ++i){
			fout1 << mystr1[i] << std::endl;
		}
		fout1.close();
	}
	in.close();
}

void CrosswordSolver::getAnagrams(std::string s){
	std::ifstream in;
	in.open("Lopatin_dictionary.txt");
	if (!in.is_open()) {
		std::cout << "File not found" << std::endl;
		return; //exit(1);
	}
	std::ofstream fout("output getAnagrams.txt");
	if (!fout.is_open()) // если файл небыл открыт 
	{
		std::cout << "file не может быть открыт или создан\n";
		return;
	}
	std::string str;
	while (in >> str){
		if (isAnagram(str, s)){
			fout << str << std::endl;
		}
	}
	in.close();
	fout.close();
}