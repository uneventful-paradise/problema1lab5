#define _CRT_NONSTDC_NO_DEPRECATE
#include "Number.h"
#include <cstring>
#include <iostream>
Number::Number(const char* value, int base)
{
	strcpy(this->representation, value);
	this->base = base;
}

int Number::GetDigitsCount()
{
	return strlen(this->representation);
}

int convertToDec(char a[], int size, int base)
{             
	int power = 1, ans= 0;
	for (int i = 0; i < size; ++i)
	{
		int digit = 0;
		if (base >= 10 and a[size - i - 1] >= 'A' and a[size - i - 1] <= 'Z')
			digit = a[size - i - 1] - 55;
		else
		{
			digit = (a[size - i - 1] - 48);
		}
		ans += power * digit;
		power *= base;
	}
	return ans;
}
//how to convert char to int and reverse
//cum ar trebui sa fac pt char*a/ sa il returnez
void convertFromDec(char a[], int base, int numberInDec)//trebuie prin referinta cumva? sau pointer 
{
	//de ce a[] crapa la prima atribuire
	int ind = 0;
	while (numberInDec)
	{
		if(base > 10 and numberInDec % base >= 10)
			a[ind++] = (numberInDec % base) + 55;
		else a[ind++] = (numberInDec % base)+48;
		numberInDec /= base;
	}
	a[ind] = NULL;
	strrev(a);
}

void Number::Print()
{
	printf("%s\n%d\n", this->representation, 
		convertToDec(this->representation, strlen(this->representation), this->base));
	int numberToC = convertToDec(this->representation, strlen(this->representation), this->base);
	convertFromDec(this->representation, 16, numberToC);
	printf("%s\n", this->representation);
}