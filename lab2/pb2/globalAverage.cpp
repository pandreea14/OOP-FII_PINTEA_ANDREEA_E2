#include "Globals.h"

int MyCompare(Student* obj1, Student* obj2)
{
	if (obj1->getaverageGrade() < obj2->getaverageGrade())
		return -1;
	if (obj1->getaverageGrade() == obj2->getaverageGrade())
		return 0;
	if (obj1->getaverageGrade() > obj2->getaverageGrade())
		return 1;
}