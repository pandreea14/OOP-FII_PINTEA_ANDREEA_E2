#include "Sort.h"
#include <stdio.h>

int main()
{

	Sort c1(10, 10, 100);
	int v[5] = { 1, 2, 3, 4, 5 };
	Sort c2(v, 5);
	Sort c3(6, 1, 2, 3, 4, 5, 6);//variadic
	char c[] = "12,14,56,78";
	Sort c4(c);
	Sort c5;

	c1.BubbleSort();
	c1.Print();
	printf("\n");

	c2.QuickSort();
	c2.Print();
	printf("\n");

	c3.InsertSort();
	c3.Print();
	printf("\n");

	c4.QuickSort();
	c4.Print();
	printf("\n");

	c5.BubbleSort();
	c5.Print();
	printf("\n");

	return 0;
}