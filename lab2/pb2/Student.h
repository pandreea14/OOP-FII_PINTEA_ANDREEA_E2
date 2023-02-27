#pragma once
class Student
{
private:
	const char* Name;
	float MathGrade, EnglishGrade, HistoryGrade;
public:
	void setName(const char* input_name);
	void setMathGrade(float input_grade);
	void setEnglishGrade(float input_grade);
	void setHistoryGrade(float input_grade);

	const char* getName();
	float getMathGrade();
	float getEnglishGrade();
	float getHistoryGrade();
	float getaverageGrade();
};

