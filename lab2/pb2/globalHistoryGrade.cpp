#include "Globals.h"

int MyCompare(Student* obj1, Student* obj2)
{
	if (obj1->getHistoryGrade() < obj2->getHistoryGrade())
		return -1;
	if (obj1->getHistoryGrade() == obj2->getHistoryGrade())
		return 0;
	if (obj1->getHistoryGrade() > obj2->getHistoryGrade())
		return 1;
}