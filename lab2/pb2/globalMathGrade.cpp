#include "Globals.h"

int MyCompare(Student* obj1, Student* obj2) 
{
	if (obj1->getMathGrade() < obj2->getMathGrade())
		return -1;
	if (obj1->getMathGrade() == obj2->getMathGrade())
		return 0;
	if (obj1->getMathGrade() > obj2->getMathGrade())
		return 1;
}