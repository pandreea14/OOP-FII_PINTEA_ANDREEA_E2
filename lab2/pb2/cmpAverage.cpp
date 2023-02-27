#include "Globals.h"
#include "Student.h"

int cmpAverage(Student &x, Student &y)
{
	if (x.getaverageGrade() < y.getaverageGrade())
		return -1;
	if (x.getaverageGrade() == y.getaverageGrade())
		return 0;
	if (x.getaverageGrade() > y.getaverageGrade())
		return 1;
}