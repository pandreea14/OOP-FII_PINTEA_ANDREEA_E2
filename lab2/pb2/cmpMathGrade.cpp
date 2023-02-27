#include "Globals.h"
#include "Student.h"

int cmpMathGrade(Student &x, Student &y) 
{
	if (x.getMathGrade() < y.getMathGrade())
		return -1;
	if (x.getMathGrade() == y.getMathGrade())
		return 0;
	if (x.getMathGrade() > y.getMathGrade())
		return 1;
}