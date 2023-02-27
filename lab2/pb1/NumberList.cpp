#include <iostream>
#include "NumberList.h"

void NumberList::Init()
{
	this->count = 0;
}// count will be 0

bool NumberList::Add(int x)
{
	if (this->count >= 10)
	{
		printf("prea mult");
		return false;
	}
	numbers[this->count] = x;
	this->count++;
}// adds X to the numbers list and increase the data member count.
// if count is bigger or equal to 10, the function will return false

void NumberList::Sort()
{
	for (int ind1 = 0; ind1 < this->count-1; ind1++)
	{
		for (int ind2 = ind1 + 1; ind2 < this->count; ind2++)
		{
			if (numbers[ind1] > numbers[ind2])
			{
				numbers[ind1] = numbers[ind1] + numbers[ind2];
				numbers[ind2] = numbers[ind1] - numbers[ind2];
				numbers[ind1] = numbers[ind1] - numbers[ind2];
			}
		}
	}
}
// will sort the numbers vector

void NumberList::Print()
{
	for (int ind = 0; ind < this->count; ind++)
	{
		printf("%d ", numbers[ind]);
	}
}
// will print the current vector