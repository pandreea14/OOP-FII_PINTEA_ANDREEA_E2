#pragma once
class Sort
{
    int* arr;
    int count;

public:
    
    Sort(int length, int minVal, int maxVal);
    Sort();
    Sort(int* a, int length);
    Sort(int length, ...);
    Sort(char* a);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

