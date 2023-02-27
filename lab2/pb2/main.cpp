#include "Student.h"
#include "Globals.h"
#include <stdio.h>
#include <string.h>

void main()
{
	Student me, x;

	me.setName("Andreea Pintea");
	me.setEnglishGrade(10);
	me.setMathGrade(8);
	me.setHistoryGrade(2);

	x.setName("Anonim");
	x.setEnglishGrade(7.5);
	x.setMathGrade(8);
	x.setHistoryGrade(9);

	printf("Name: %s\nAverage: %d\n", me.getName(), me.getaverageGrade());
	printf("Name: %s\nAverage: %d\n", x.getName(), x.getaverageGrade());

	printf("Math grade me: %d\n", me.getMathGrade());
	printf("English grade me: %d\n", me.getEnglishGrade());
	printf("History grade me: %d\n", me.getHistoryGrade());
	printf("Math grade x: %d\n", x.getMathGrade());
	printf("English grade x: %d\n", x.getEnglishGrade());
	printf("History grade x: %d\n", x.getHistoryGrade());

	printf("Comparisons: %d, %d, %d, %d, %d", cmpName(me, x), cmpAverage(me, x), cmpMathGrade(me, x), cmpEnglishGrade(me, x), cmpHistoryGrade(me, x));
}