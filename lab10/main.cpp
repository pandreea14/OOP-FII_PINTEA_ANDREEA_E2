#include <iostream>
#include "array.h"
using namespace std;

int main() 
{
        Array<int> arr(4);
        arr += 1;
        arr += 2;
        arr += 3;
        arr += 4;
        cout << "Array size: " << arr.GetSize() << endl;
        cout << "Array capacity: " << arr.GetCapacity() << endl;
        cout << "Array size after removing element at index 2: " << arr.GetSize() << endl;
        cout << "Array elements: ";
        for (auto it : arr)
        {
            cout << it << " ";
        }
        cout << endl;
    
    return 0;
}