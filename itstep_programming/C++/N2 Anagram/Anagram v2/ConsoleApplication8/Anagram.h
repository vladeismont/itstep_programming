#pragma once
#include "iostream"
class Anagram
{
public:

int check_anagram(char a[], char b[]){
	int first[91] = { 0 }, second[91] = { 0 }, c = 0;
	if(strlen(a)==0||strlen(b)==0)return 4;
	while (a[c] != '\0'){
		first[a[c] - ' ']++;
		c++;
		}
	c = 0;
	while (b[c] != '\0'){
		second[b[c] - ' ']++;
		c++;
		}
	for (c = 0; c<91; c++){
	if (first[c] != second[c])
		return 0;
		}
	return 1;
	}
Anagram();
~Anagram();
};

