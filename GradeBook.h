#pragma once
//below are the header files, note how there is the #endif file added at the end
#ifndef GB_H
#define GB_H

#include <string>
using namespace std;

class GradeBook
{
public:
	//constants
	static const int students = 10; //note how this is public data
	static const int tests = 3;

	GradeBook(string, const int [][tests]); //constructor that initializes the course name and array of grades

	void setCourseName(string name); //This sets the course name 
	string getCourseName(); //this returns the name of the course
	void displayMessage(); // this displays a welcome message
	void processGrades();
	int getMinimum();
	int getMaximum();
	double getAverage(const int [], const int);
	void outputBarChart();
	void outputGrades();

private:
	string courseName;
	int grades[students][tests];
};

#endif /*GB_H*/