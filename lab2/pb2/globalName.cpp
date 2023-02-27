#include "Globals.h"
#include <cstring>

int MyCompare(Student* obj1, Student* obj2)
{
	char nameStudent1[30], nameStudent2[30];

	strcpy_s(nameStudent1, obj1->getName());
	strcpy_s(nameStudent2, obj2->getName());

	return strcmp(nameStudent1, nameStudent2);
}