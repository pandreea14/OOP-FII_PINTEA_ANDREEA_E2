#pragma once
class Number
{
	char * stringNumber;
	int integerNumber;
	int base;
	
public:   
	Number();
	Number(char* value);
	Number(int value);
	Number(const char * value, int base); // where base is between 2 and 16   
	~Number();

	Number(const Number& value); //copy constructor
	Number(Number&& value) noexcept; //move constructor

	Number& operator= (Number&& value) noexcept;
	Number operator= (const char* value);

	friend Number operator+(Number value1, Number value2);
	friend Number operator+=(Number value1, Number value2);
	friend Number operator-(Number value1, Number value2);
	bool operator > (Number& value);
	char operator [](int index);

	void operator--();
	void operator--(int numar);

	void SwitchBase(int newBase);   
	void Print();   
	int  GetDigitsCount(); // returns the number of digits for the current number   
	int  GetBase(); // returns the current base
};

