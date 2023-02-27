#include "Globals.h"

int MyCompare(Student* obj1, Student* obj2)
{
	if (obj1->getEnglishGrade() < obj2->getEnglishGrade())
		return -1;
	if (obj1->getEnglishGrade() == obj2->getEnglishGrade())
		return 0;
	if (obj1->getEnglishGrade() > obj2->getEnglishGrade())
		return 1;
}