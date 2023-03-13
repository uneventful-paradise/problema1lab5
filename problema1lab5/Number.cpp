#define _CRT_NONSTDC_NO_DEPRECATE
#include "Number.h"
#include <cstring>
#include <iostream>
Number::Number(const char* value, int base)
{
	strcpy(this->representation, value);
	this->base = base;
}

Number::~Number(){}

int Number::GetDigitsCount()
{
	return strlen(this->representation);
}

Number::Number(Number& n) {
	strcpy(this->representation, n.representation);
	this->base = n.base;
};



int Number::GetBase()
{
	return this->base;
}

int convertToDec(char a[], int size, int base)
{             
	int power = 1, ans= 0;
	for (int i = 0; i < size; ++i)
	{
		int digit = 0;
		if (base > 10 and a[size - i - 1] >= 'A' and a[size - i - 1] <= 'Z')
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
//?
void Number::SwitchBase(int newBase)
{
	int numberToC = convertToDec(this->representation, strlen(this->representation), this->base);
	convertFromDec(this->representation, newBase, numberToC);
	this->base = newBase;
}

char* stringConv(char a[], int n)
{
	int ind = 0;
	while (n != 0)
	{
		a[ind++] = n % 10;
		n /= 10;
	}
	a[ind] = NULL;
	strrev(a);
	return a;
}

//char *Number::operator+(Number n)
//{
//	int a = convertToDec(n.representation, strlen(n.representation), n.base);
//	//std::cout << a << "\n";
//	int b = convertToDec(this->representation, strlen(this->representation), this->base);
//	//std::cout << b << "\n";
//	a += b;
//	//std::cout << a << "\n";
//	this->base = std::max(this->base, n.base);
//	convertFromDec(this->representation, this->base, a);
//	//strcpy(this->representation, stringConv(this->representation, a));//crapa daca incerc sa returnez char*
//	//stringConv(this->representation, a);
//	//return this->representation; //daca vrem sa returnam direct rezultatul pentru a-l putea afisa
//	char* result = (char*)malloc(100);
//	convertFromDec(result, this->base, a);
//	return result;
//}

//char* Number::operator-(Number n)
//{
//	std::cout << "reprezentarea lui n1: " << n.representation << " " << n.base << "\n";
//	int a = convertToDec(n.representation, strlen(n.representation), n.base);
//	std::cout << "numarul a in zecimal este: " << a << "\n";
//	int b = convertToDec(this->representation, strlen(this->representation), this->base);
//	std::cout << "numarul b in zecimal este: " << b << "\n";
//	if (a > b)
//		a -= b;
//	else
//		a = b - a;
//	std::cout << "dupa scadere a este: " << a << "\n";
//	this->base = std::max(this->base, n.base);
//	char* result = (char*)malloc(100);
//	convertFromDec(result, this->base, a);
//	return result;
//}

char* operator-(Number n1, Number n2)
{
	std::cout << "reprezentarea lui n1: " << n1.representation << " " << n1.base << "\n";
	int a = convertToDec(n1.representation, strlen(n1.representation), n1.base);
	std::cout << "numarul a in zecimal este: " << a << "\n";
	int b = convertToDec(n2.representation, strlen(n2.representation), n2.base);
	std::cout << "numarul b in zecimal este: " << b << "\n";
	if (a > b)
		a -= b;
	else
		a = b - a;
	std::cout << "dupa scadere a este: " << a << "\n";
	n1.base = std::max(n1.base, n2.base);
	char* result = (char*)malloc(100);
	convertFromDec(result, n1.base, a);
	return result;
}

char* operator+(Number n1, Number n2)
{
	int a = convertToDec(n1.representation, strlen(n1.representation), n1. base);
	std::cout << "reprezentarea lui a este: " << a << "\n";
	int b = convertToDec(n2.representation, strlen(n2.representation), n2.base);
	std::cout << "reprezentarea lui b este: "<< b << "\n";
	a += b;
	std::cout << "rezultatul adunarii este: " << a << "\n";
	n1.base = std::max(n1.base, n2.base);
	convertFromDec(n1.representation, n1.base, a);
//	//strcpy(this->representation, stringConv(this->representation, a));//crapa daca incerc sa returnez char*
//	//stringConv(this->representation, a);
//	//return this->representation; //daca vrem sa returnam direct rezultatul pentru a-l putea afisa
	char* result = (char*)malloc(100);
	convertFromDec(result, n1.base, a);
	return result;
}

bool Number::operator[](int index)
{
	return (this->representation[index] & 1);
}

bool Number::operator==(Number n)
{
	return (convertToDec(this->representation, strlen(this->representation), this->base)
		== convertToDec(n.representation, strlen(n.representation), n.base));
}

bool Number::operator>(Number n)
{
	std::cout << "reprezentarea lui n1: " << n.representation << " " << n.base << "\n";
	int a = convertToDec(n.representation, strlen(n.representation), n.base);
	std::cout << "numarul a in zecimal este: " << a << "\n";
	int b = convertToDec(this->representation, strlen(this->representation), this->base);
	std::cout << "numarul b in zecimal este: " << b << "\n";
	return b > a ?  true :  false;
}

Number Number::operator--()
{
	this->representation[0] = '0';
	return (*this);
}

Number Number::operator--(int)
{
	this->representation[strlen(this->representation) - 1] = '0';
	return (*this);
}

Number Number::operator=(int value)
{
	convertFromDec(this->representation, this->base, value);	
	return (*this);
}

void Number::Print()
{
	/*printf("%s	\n%d\n", this->representation, 
		convertToDec(this->representation, strlen(this->representation), this->base));
	int numberToC = convertToDec(this->representation, strlen(this->representation), this->base);
	convertFromDec(this->representation, 16, numberToC);*/
	printf("%s\n", this->representation);
}
//add copy& move constructorsand move assignment operator
//implement the -- operator with the following syntax: 
//if used in a prefix form it will remove the first (most significant digit) from the number; 
//if used in a post-fix form it will remove the last(least significant) digit from the number;