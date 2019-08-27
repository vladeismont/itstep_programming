#pragma once

class FrequencyDictionary {
	int rang;
	std::string lemma;
	std::string chastRe4i;
	double freqmil;
	double freq1, freq2, freq3, freq4, freq5, freq6;
public:
	int getrang();
	std::string getlemma();
	std::string getfreqhigh();
	std::string getchastre4i();
	double getfreqmil();
	void setRang(const int n);
	void setLemma(const std::string n);
	void setchastRe4i(const std::string n);
	void setFreqmil(const double n);
	void setFreq1(const double n);
	void setFreq2(const double n);
	void setFreq3(const double n);
	void setFreq4(const double n);
	void setFreq5(const double n);
	void setFreq6(const double n);
};