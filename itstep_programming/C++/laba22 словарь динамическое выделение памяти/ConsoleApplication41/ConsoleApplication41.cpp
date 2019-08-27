// ConsoleApplication41.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header.h"
std::string freqhigh (FrequencyDictionary *obj) {
	return obj[0].getfreqhigh();
}
std::string freqlow(FrequencyDictionary *obj, const int n) {
	return obj[n-1].getfreqhigh();
}
int main()
{
	std::ifstream in;
	in.open("dictionary.txt");
	if (!in.is_open()) {
		std::cout << "File not found" << std::endl;
		return 1; //exit(1);
	}
	size_t f = 0;
	while (!in.eof()) {
		std::string str;
		std::getline(in, str);
		++f;
	}
	in.close();
	FrequencyDictionary* obj = new FrequencyDictionary[f];
	std::ifstream in1;
	in1.open("dictionary.txt");
	size_t i = 0;
	int n;
	while (in1 >> n) {
		if (n == NULL)break;
		obj[i].setRang(n);
		std::string str;
		in1 >> str;
		obj[i].setLemma(str);
		in1 >> str;
		obj[i].setchastRe4i(str);
		double freqmil;
		in1 >> freqmil;
		obj[i].setFreqmil(freqmil);
		in1 >> freqmil;
		obj[i].setFreq1(freqmil);
		in1 >> freqmil;
		obj[i].setFreq2(freqmil);
		in1 >> freqmil;
		obj[i].setFreq3(freqmil);
		in1 >> freqmil;
		obj[i].setFreq4(freqmil);
		in1 >> freqmil;
		obj[i].setFreq5(freqmil);
		in1 >> freqmil;
		obj[i].setFreq6(freqmil);
		++i;
	}
	in1.close();
	
	std::ofstream fout("output.txt");
	if (!fout.is_open()) // если файл небыл открыт 
	{
		std::cout << "Файл не может быть открыт или создан\n";
		return 1;
	}
	
	fout << "самое часто употребляемое слово: " << freqhigh(obj) << std::endl;
	fout << "самое редкое употребляемое слово: " << freqlow(obj,f) << std::endl;
	for (size_t i = 0; i < f; ++i) {
		if ("и" == obj[i].getlemma()) {
			fout << obj[i].getrang() << " " << obj[i].getlemma() << std::endl;
			break;
		}
	}
	for (size_t i = 100; i < 1000; ++i) {
		fout << obj[i].getlemma() << " ";
	}
	fout << std::endl << std::endl;
	for (size_t i = 0; i < f; ++i) {
		if (obj[i].getchastre4i() == "s") {
			if (obj[i].getfreqmil() > 1000) {
				fout << obj[i].getlemma() << " ";
			}
		}
	}
	fout << std::endl << std::endl;


	fout.close();
	delete[] obj;
	system("pause");
    return 0;
}

