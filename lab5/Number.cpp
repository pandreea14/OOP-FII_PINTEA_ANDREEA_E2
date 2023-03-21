#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>

int convertCharToInt(const char* string, int index)
{
	if ((string[index] - '0') <= 9) return (string[index] - '0');
	else
	{
		if (string[index] == 65) return 10;
		if (string[index] == 66) return 11;
		if (string[index] == 67) return 12;
		if (string[index] == 68) return 13;
		if (string[index] == 69) return 14;
		if (string[index] == 70) return 15;
	}
}
char convertIntToChar(int value)
{
	if (value <= 9) return (value + '0');
	else
	{
		if (value == 10) return 'A';
		if (value == 11) return 'B';
		if (value == 12) return 'C';
		if (value == 13) return 'D';
		if (value == 14) return 'E';
		if (value == 15) return 'F';
	}
}
void chgBase10ToX(int nr, int base, int& rez)
{
	if (nr == 0) return;
	chgBase10ToX(nr / base, base, rez);
	rez = rez + (nr % base);
	rez *= 10;
}
char* base16(int nr, int base, char* string)
{
	int index = 0;
	while (nr % base)
	{
		string[index++] = convertIntToChar(nr % base);
		nr /= base;
	}
	string[index] = '\0';
	_strrev(string);
	return string;
}

Number::Number()
{
	this->stringNumber = nullptr;
	this->integerNumber =  0;
	this->base = -1;
}
Number::Number(const char* string, int base)
{
	this->stringNumber = new char[strlen(string) + 1];
	memcpy(this->stringNumber, string, strlen(string) + 1);
	this->integerNumber = atoi(this->stringNumber);
	/*
	this->integerNumber = 0;
	int power = 1, digit;
	for (int index = strlen(string) - 1; index >= 0; index--)
	{
		digit = convertCharToInt(string, index);
		this->integerNumber = this->integerNumber + power * digit;
		power *= 10;
	}
	SwitchBase(10);
	*/
	this->base = base;
}
Number::Number(char* value)
{
	//memcpy(this->stringNumber, value, strlen(value) + 1);
	this->stringNumber = value;
	this->base = GetBase();
	this->integerNumber = 0;
	int power = 1, digit;
	for (int index = strlen(value) - 1; index >= 0; index--)
	{
		digit = convertCharToInt(value, index);
		this->integerNumber = this->integerNumber + power * digit;
		power *= 10;
	}
}
Number::Number(int value)
{
	this->base = GetBase();
	this->integerNumber = value;
	int length = GetDigitsCount();
	this->stringNumber = new char[length + 1];
	/*
	for (int index = GetDigitsCount(); index >= 0; index--)
	{
		this->stringNumber[index] = value % 10;
		value /= 10;
	}*/
}
Number::~Number()
{
	if (stringNumber != nullptr) 
	{ 
		printf("DTOR => Obj:%d,Text:%s\n", this->integerNumber, this->stringNumber); 
		delete this->stringNumber; 
	}
	else 
	{ 
		printf("DTOR => Obj:%d (nothing to delete)\n", integerNumber); 
	}
	this->integerNumber = 0;
	this->base = -1;
}
Number::Number(const Number& value) //copy constructor
{
	this->integerNumber = value.integerNumber;
	this->stringNumber = value.stringNumber;
	//strcpy(this->stringNumber, value.stringNumber);
	this->base = value.base;
}
Number::Number(Number&& value) noexcept //move constructor
{
	this->stringNumber = value.stringNumber;
	this->integerNumber = value.integerNumber;
	this->base = value.base;
	delete value.stringNumber;
	value.stringNumber = nullptr;
}
Number& Number::operator= (Number&& value) noexcept
{
	this->stringNumber = value.stringNumber;
	this->integerNumber = value.integerNumber;
	this->base = value.base;
	//memcpy(this->stringNumber, value.stringNumber, strlen(value.stringNumber) + 1);
	return (*this);
}
Number Number::operator= (const char* value)
{
	memcpy(this->stringNumber, value, strlen(value) + 1);
	this->integerNumber = atoi(this->stringNumber);
	this->base = 10;
	return Number(this->stringNumber);
}

Number operator+ (Number value1, Number value2)
{
	int sum;
	char* string = new char[100];
	if (value1.base == value2.base)
	{
		sum = value1.integerNumber + value2.integerNumber;
		sprintf(string, "%d", sum);
		return Number(string);
	}
	else
	{
		int base, result = 0;
		if (value1.base > value2.base) base = value1.base;
		else base = value2.base;
		//printf("baza este %d\n", base);
		value1.SwitchBase(10);
		//printf("value1 este %d\n", value1.integerNumber);

		value2.SwitchBase(10);
		//printf("value2 este %d\n", value2.integerNumber);

		sum = value1.integerNumber + value2.integerNumber;
		//printf("rezultatul final in baza %d este %d\n", 10, sum);

		string = base16(sum, base, string);
		
		//printf("rezultatul final in baza %d este %s\n", base, string);

		return Number(string);
	}
}
Number operator+= (Number value1, Number value2)
{
	char* string = new char[100];
	int sum;
	if (value1.base == value2.base)
	{
		sum = value1.integerNumber + value2.integerNumber;
		sprintf(string, "%d", sum);
		return Number(string);
	}
	else
	{
		int base, result;
		if (value1.base > value2.base) base = value1.base;
		else base = value2.base;
		//printf("baza este %d\n", base);
		value1.SwitchBase(10);
		//printf("value1 este %d\n", value1.integerNumber);

		value2.SwitchBase(10);
		//printf("value2 este %d\n", value2.integerNumber);

		sum = value1.integerNumber + value2.integerNumber;
		//printf("rezultatul final in baza %d este %d\n", 10, sum);

		string = base16(sum, base, string);
		
		//printf("rezultatul final in baza %d este %s\n", base, string);

		return Number(string);
	}
}
Number operator- (Number value1,Number value2)
{
	int dif;
	char* string = new char[100];

	if (value1.GetBase() == value2.GetBase())
	{
		dif = value1.integerNumber + value2.integerNumber;
		sprintf(string, "%d", dif);
		return Number(string);
	}
	else
	{
		int base, result;
		if (value1.GetBase() > value2.GetBase()) base = value1.GetBase();
		else base = value2.GetBase();
		value1.SwitchBase(10);
		value2.SwitchBase(10);
		dif = value1.integerNumber - value2.integerNumber;
		if(base<=10) chgBase10ToX(dif, base, result);
		string = base16(dif, base, string);
		//printf("rezultatul final in baza %d este %d\n", base, result);
		return Number(string);
	}
}
char Number::operator[] (int index)
{
	if (index >= 0 && index < GetDigitsCount())
	{
		return this->stringNumber[index];
	}
	return -1;
}
bool Number::operator > (Number& value)
{
	if (this->base == value.base)
	{
		if (strcmp(this->stringNumber, value.stringNumber) == 1)
			return true;
		return false;
	}
	else
	{
		value.SwitchBase(this->base);
		if (strcmp(this->stringNumber, value.stringNumber) == 1)
			return true;
		return false;
	}
}
void Number::operator--() 
{
	printf("Operatorul -- apelat in format prefixat\n");
	int newNumber = 0, power = 1;
	while (this->integerNumber > 9)
	{
		newNumber = newNumber + this->integerNumber % 10 * power;
		power *= 10;
		this->integerNumber /= 10;
	}
	this->integerNumber = newNumber;
}
void Number::operator--(int numar) 
{
	printf("Operatorul -- apelat in format postfixat\n");
	this->integerNumber /= 10;
}
int convertToBase10(char* string, int currentBase)
{
	int rez = 0, power = 1, value;
	for(int index=strlen(string)-1; index>=0; index--)
	{
		value = convertCharToInt(string, index);
		rez += value * power;
		power *= currentBase;
		value /= 10;
	}
	return rez;
}
void Number::SwitchBase(int newBase)
{
	int numberInBase10;
	int result = 0;
	if (this->base != 10)
	{
		numberInBase10 = convertToBase10(this->stringNumber, this->base);
	}
	else
	{
		numberInBase10 = this->integerNumber;
	}
	chgBase10ToX(numberInBase10, newBase, result);
	this->integerNumber = result / 10;

}
void Number::Print()
{
	printf("%d\n", this->integerNumber);
}
int Number::GetDigitsCount()
{
	int length = 0, val=this->integerNumber;
	while(val)
	{
		length++;
		val /= 10;
	}
	return length;
}
int Number::GetBase()
{
	if (this->base != -1) return this->base;
	else return 10;
}