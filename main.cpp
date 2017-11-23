#include "GradeBook.h"

//in this version, arrays are incorporated to store values
//these two dimensional arrays holds multiple students with each of there respective exam scores.
int main()
{
	//array of students grades
	// note how the gradesArray was set up with the public variable students
	int gradesArray[GradeBook::students][GradeBook::tests] = {
		{87, 96, 70},
		{90, 100, 100},
		{54, 78, 92},
		{99, 98, 93},
		{46, 78, 55},
		{10, 12, 13},
		{67, 78, 77},
		{34, 86, 78},
		{89, 85, 78},
		{90, 89, 98},
	};

	//create a gradebook object with the array of students grades
	GradeBook myGradeBook("Linear Algebra", gradesArray);
	myGradeBook.displayMessage();
	myGradeBook.processGrades();
	system("pause");
}