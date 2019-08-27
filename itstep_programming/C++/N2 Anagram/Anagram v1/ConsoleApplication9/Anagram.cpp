#include "Anagram.h"



Anagram::Anagram()
{
}
bool Anagram::isAnagram(char str1[], char str2[]) {
	if (strlen(str1) != strlen(str2))return 0;
	for (int i = 0; i < strlen(str1) - 1; i++) {
		for (int j = 0; j < strlen(str1) - i - 1; j++) {
			if ((int)str1[j] > (int)str1[j + 1]) {
				// меняем элементы местами
				char temp = str1[j];
				str1[j] = str1[j + 1];
				str1[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < strlen(str2) - 1; i++) {
		for (int j = 0; j < strlen(str2) - i - 1; j++) {
			if (str2[j] > str2[j + 1]) {
				// меняем элементы местами
				char temp = str2[j];
				str2[j] = str2[j + 1];
				str2[j + 1] = temp;
			}
		}
	}
	if(strcmp(str1,str2))return 0;
	else return 1;
};
Anagram::~Anagram()
{
}
