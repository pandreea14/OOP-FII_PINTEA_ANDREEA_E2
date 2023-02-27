#include "Globals.h"
#include "Student.h"

int cmpEnglishGrade(Student &x, Student &y)
{
	if (x.getEnglishGrade() < y.getEnglishGrade())
		return -1;
	if (x.getEnglishGrade() == y.getEnglishGrade())
		return 0;
	if (x.getEnglishGrade() > y.getEnglishGrade())
		return 1;
}