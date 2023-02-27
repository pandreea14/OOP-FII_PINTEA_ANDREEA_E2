#include "Globals.h"

int cmpHistoryGrade(Student &x, Student &y)
{
	if (x.getHistoryGrade() < y.getHistoryGrade())
		return -1;
	if (x.getHistoryGrade() == y.getHistoryGrade())
		return 0;
	if (x.getHistoryGrade() > y.getHistoryGrade())
		return 1;
}