#include "stdafx.h"
#include "Header.h"
#include <fstream>

int FrequencyDictionary::getrang()
{
	return rang;
}

std::string FrequencyDictionary::getlemma()
{
	return lemma;
}

std::string FrequencyDictionary::getfreqhigh()
{
	return lemma;
}

std::string FrequencyDictionary::getchastre4i()
{
	return chastRe4i;
}

double FrequencyDictionary::getfreqmil()
{
	return freqmil;
}

void FrequencyDictionary::setRang(const int n)
{
	rang = n;
}

void FrequencyDictionary::setLemma(const std::string n)
{
	lemma = n;
}

void FrequencyDictionary::setchastRe4i(const std::string n)
{
	chastRe4i = n;
}

void FrequencyDictionary::setFreqmil(const double n)
{
	freqmil = n;
}

void FrequencyDictionary::setFreq1(const double n)
{
	freq1 = n;
}

void FrequencyDictionary::setFreq2(const double n)
{
	freq2 = n;
}

void FrequencyDictionary::setFreq3(const double n)
{
	freq3 = n;
}

void FrequencyDictionary::setFreq4(const double n)
{
	freq4 = n;
}

void FrequencyDictionary::setFreq5(const double n)
{
	freq5 = n;
}

void FrequencyDictionary::setFreq6(const double n)
{
	freq6 = n;
}
