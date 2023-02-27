#include "Student.h"
#include <stdio.h>
#include <string.h>

void Student::setName(const char* input_name)
{
	this->Name = input_name;
}

void Student::setMathGrade(float input_grade)
{
	this->MathGrade = input_grade;
}

void Student::setEnglishGrade(float input_grade)
{
	this->EnglishGrade = input_grade;
}

void Student::setHistoryGrade(float input_grade)
{
	this->HistoryGrade = input_grade;
}

const char* Student::getName()
{
	return this->Name;
}

float Student::getMathGrade()
{
	return this->MathGrade;
}

float Student::getEnglishGrade()
{
	return this->EnglishGrade;
}

float Student::getHistoryGrade()
{
	return this->HistoryGrade;
}

float Student::getaverageGrade()
{
	return (this->MathGrade + this->EnglishGrade + this->HistoryGrade) / 3;
}