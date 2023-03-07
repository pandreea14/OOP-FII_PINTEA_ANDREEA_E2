
#include "Math.h";
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Math::Add(int x, int y)
{
	return x + y;
}

int Math::Add(int x, int y, int z)
{
	return x + y + z;
}

int Math::Add(double x, double y)
{
	return x + y;
}

int Math::Add(double x, double y, double z)
{
	return x + y + z;
}

int Math::Mul(int x, int y)
{
	return x * y;
}

int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}

int Math::Mul(double x, double y)
{
	return x * y;
}

int Math::Mul(double x, double y, double z)
{
	return x * y * z;
}

int Math::Add(int count, ...)
{
	int sum = 0;
	va_list vl;
	va_start(vl, count);
	for (int ind = 0; ind < count; ind++)
	{
		int val = va_arg(vl, int);
		sum += val;
	}
	va_end(vl);
	return sum;
}   

char* Math::Add(const char* x, const char* y)
{
	if (x == nullptr || y == nullptr) return nullptr;
	
	char* rez = (char*)malloc(strlen(x)+strlen(y));
	
	for (int i = 0; i < strlen(x); i++)
		rez[i] = x[i];
	for (int i = 0; i < strlen(y); i++)
		rez[i + strlen(x)] = y[i];

	rez[strlen(x) + strlen(y)] = '\0';

	return rez;
	free(rez);
}