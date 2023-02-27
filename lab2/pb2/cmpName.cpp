#include "Globals.h"
#include "Student.h"
#include <cstring>

int cmpName(Student &x, Student &y)
{
	char nameStudent1[30], nameStudent2[30];

	strcpy_s(nameStudent1, x.getName());
	strcpy_s(nameStudent2, y.getName());

	if (strcmp(nameStudent1, nameStudent2) < 0) return -1;
	else if (strcmp(nameStudent1, nameStudent2) == 0) return 0;
	else return 1;
}