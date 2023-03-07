#include "Math.h";
#include <stdio.h>
#include <iostream>

int main()
{
	Math a;
	printf("The sum of 2 integers is %d\n", a.Add(5, 2));
	printf("The sum of 3 integers is %d\n", a.Add(76, 2, 2));
	printf("The sum of 2 double variables is %d\n", a.Add(3.2f, 6.8f));
	printf("The sum of 3 double variables is %d\n", a.Add(2.2f, 1.0f, 7.8f));
	printf("The multiplication of 2 integers is %d\n", a.Mul(5, 2));
	printf("The multiplication of 3 integers is %d\n", a.Mul(5, 2, 3));
	printf("The multiplication of 2 double variables is %d\n", a.Mul(2.1f, 4.3f));
	printf("The multiplication of 3 double variables is %d\n", a.Mul(5.1f, 2.2f, 3.1f));
	printf("The sum using a variadic method is %d\n", a.Add(5, 1, 2, 3, 4, 5));
	printf("The concatenation is %s\n", a.Add("abc", "ps"));

	return 0;
}