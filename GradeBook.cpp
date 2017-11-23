#include <iostream>
#include <iomanip>
#include "GradeBook.h"
//Note how this doesn't have to include string because it is pushed
//through the header file where you define string
using namespace std;

GradeBook::GradeBook(string name, const int gradesArray[][tests]) {
	setCourseName(name);
	//copy grades from gradesArray to grades data member so that can save it etc
	for (int student = 0; student < students; student++)
	{
		for (int test = 0; test < tests; test++)
			grades[student][test] = gradesArray[student][test];
	}
}

void GradeBook::setCourseName(string name) {
	if(name.length() <= 25)
		courseName = name;
	else {
		courseName = name.substr(0, 25);
		cout << "The course name: " << name << " was truncated down to 25 characters.\n" << endl;
	}
}

string GradeBook::getCourseName() {
	return courseName;
}

void GradeBook::displayMessage() {
	cout << "Welcome to the gradebook for: " << getCourseName() << endl;
}

//input an arbitrary number of letter grades from user, update grade counter

void GradeBook::processGrades()
{
	outputGrades(); //output grades array

	cout << "\nLowest grade is: " << getMinimum() << "\nHighest grade is " << getMaximum() << endl;

	outputBarChart();
}

int GradeBook::getMinimum()
{
	//this is a function that returns the lowest grade
	int lowGrade = 100; //assume lowest grade is 100 so that checking for what grades are less then 100 to set lowest

	for (int student = 0; student < students; student++)
	{
		for (int test = 0; test < tests; test++)
		{
			if (grades[student][test] < lowGrade)
				lowGrade = grades[student][test];
		}
	}
	return lowGrade;
}

int GradeBook::getMaximum()
{
	//this is a funciton that returns the highest grade
	int highGrade = 0;
	//loop through grades array
	for (int student = 0; student < students; student++)
	{
		for (int test = 0; test < tests; test++)
		{
			if (grades[student][test] > highGrade)
				highGrade = grades[student][test];
		}
	}
	return highGrade;
}

double GradeBook::getAverage(const int setOfGrades[], const int grades)
{
	//determine average grade of test
	int total = 0;

	//sum grades in array
	for (int grade = 0; grade < grades; grade++)
	{
		total += setOfGrades[grade];
	}

	//turn total into temporary double so can do operation
	return static_cast<double>(total) / grades;
}


void GradeBook::outputBarChart()
{
	cout << "\nGrade Distribution: " << endl;

	//stores frequency of grades in each range of 10 grades
	// size of 11 with first index at 0	
	const int frequencySize = 11;
	int frequency[frequencySize] = {};

	for (int student = 0; student < students; student++)
	{
		for (int test = 0; test < tests; test++)
			++frequency[grades[student][test] / 10];
	}
	
	for (int count = 0; count < frequencySize; count++)
	{
		//output bar labels (0-9...90-99, 100)
		if (count == 0)
			cout << "0-9: ";
		else if (count == 10)
			cout << "100: ";
		else
			cout << count * 10 << "-" << (count * 10) + 9 << ": ";
		
		for (int stars = 0; stars < frequency[count]; stars++)
			cout << '*';
		cout << endl;
	}
}

void GradeBook::outputGrades()
{
	cout << "\nThe Grades Are: \n\n";
	//align
	cout << "               ";

	//create column heading for each of the tests
	for (int test = 0; test < tests; test++)
		cout << "Test " << test + 1 << " ";

	cout << "Average" << endl;

	for (int student = 0; student < students; student++)
	{
		cout << "Student " << setw(2) << student + 1;

		for (int test = 0; test < tests; test++)
			cout << setw(8) << grades[student][test];
		//calculate a students average grade in class
		double average = getAverage(grades[student], tests);
		cout << setw(9) << fixed << setprecision(2) << average << endl;
	}
}
