#pragma once
class Student
{
	char* Name;
	float MathGrade, EnglishGrade, HistoryGrade;
public:
	void setName(char* input_name);
	void setMathGrade(float input_grade);
	void setEnglishGrade(float input_grade);
	void setHistoryGrade(float input_grade);

	char* getName();
	float getMathGrade();
	float getEnglishGrade();
	float getHistoryGrade();
	float averageGrade();
};

