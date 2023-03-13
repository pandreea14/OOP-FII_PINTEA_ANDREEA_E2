#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include <cstring>
#include <stdarg.h>

Sort::Sort(int numar_elemente, int minVal, int maxVal)
{
	time_t t;
	count = numar_elemente;
	arr = new int[count];
	srand((unsigned)time(&t));
	for (int i = 0; i < numar_elemente; i++)
	{
		arr[i] = minVal + rand() % (minVal - maxVal + 1);
	}
}
Sort::Sort() : arr(new int [6] {1, 2, 3, 4, 5, 6})
{
	count = 6;
}

Sort::Sort(int* v, int length)
{
	count = length;
	arr = new int[count];
	for (int i = 0; i < length; i++)
	{
		arr[i] = v[i];
	}
}
Sort::Sort(int length, ...)
{
	va_list vl;
	count = length;
	va_start(vl, count);
	arr = new int[count];
	for (int i = 0; i < count; i++)
	{
		arr[i] = va_arg(vl, int);
	}
	va_end(vl);
}
Sort::Sort(char* a)
{
	char* p;
	int numbers = 0, x = 0;
	arr = new int[strlen(a)];

	p = strtok(a, ",");
	while (p)
	{
		int power = 1;
		for (int i = 0; i < strlen(p); i++)
		{
			x = (p[i] - '0') + power * x;
			if(i==0) power *= 10;
		}

		arr[numbers++] = x;
		x = 0;

		p = strtok(NULL, ",");
	}

	count = numbers;
}

void Sort::InsertSort(bool ascendent)
{
	for (int index1 = 0; index1 < this->count; index1++)
		{
			int poz = index1;
			for (int index2 = index1 - 1; index2 >= 0; index2--)
			{
				if (arr[index2] < arr[index1])
				{
					poz = index2;
				}
			}
			int copy = arr[index1];
			for (int index2 = index1 - 1; index2 >= poz; index2--)
			{
				arr[index2 + 1] = arr[index2];
			}
			arr[poz] = copy;
		}
}

int Partition(int* arr, int start, int end)
{
	int pivot = arr[start], nr = 0;
	for (int i = start + 1; i <= end; i++) 
	{
		if (arr[i] >= pivot)
			nr++;
	}

	int pivotIndex = start + nr;
	std::swap(arr[pivotIndex], arr[start]);

	int i = start, j = end;
	while (i < pivotIndex && j > pivotIndex) 
	{
		while (arr[i] >= pivot) 
		{
			i++;
		}
		while (arr[j] < pivot) 
		{
			j--;
		}
		if (i < pivotIndex && j > pivotIndex) 
		{
			std::swap(arr[i++], arr[j--]);
		}
	}
	return pivotIndex;
}

void Quicksort(int* arr, int start, int end)
{
	if (start >= end)
		return;

	int p = Partition(arr, start, end);

	Quicksort(arr, start, p - 1);
	Quicksort(arr, p + 1, end);
}

void Sort::QuickSort(bool ascendent)
{
	Quicksort(arr, 0, count);
}

void Sort::BubbleSort(bool ascendent)
{
	bool sorted = false;
	while (!sorted)
	{
			sorted = true;
			for (int index = 1; index < this->count; index++)
			{
				if (arr[index - 1] < arr[index])
				{
					std::swap(arr[index - 1], arr[index]);
					sorted = false;
				}
			}
	}
}

void Sort::Print()
{
	for (int index = 0; index < this->count; index++)
	{
		printf(" %d ", arr[index]);
	}
}

int  Sort::GetElementsCount()
{
	return this->count;
}

int  Sort::GetElementFromIndex(int index)
{
	return arr[index];
}