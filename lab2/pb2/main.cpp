#include "Student.h"
#include <stdio.h>
#include <string.h>

void main()
{
	Student s;

	s.setName("Andreea");
	s.setEnglishGrade(8);
	s.setMathGrade(5);
	s.setHistoryGrade(9);

	printf("Name %s: \n", s.getName());
	printf("Math grade %d: \n", s.getMathGrade());
	printf("English grade %d: \n", s.getEnglishGrade());
	printf("History grade %d: \n", s.getHistoryGrade());
}