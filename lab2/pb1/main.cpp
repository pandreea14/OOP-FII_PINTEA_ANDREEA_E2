#include "NumberList.h"
using namespace std;

void main()
{
	NumberList a;
	a.Init();
	a.Add(12);
	a.Add(3);
	a.Add(9);
	a.Sort();
	a.Print();
}