#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>
#include <iostream>

using namespace std;

class Student {
public:
	Student();
	Student(string studentId, string firstName, string lastName, string emailAddress, string age, int daysInCourse[], Degree type);

	// Get Functions
	string GetAge();
	string GetEmail();
	string GetLastName();
	string GetStudentId();
	string GetFirstName();
	int* GetDaysInCourse();
	virtual Degree GetDegreeProgram();


	// Set Functions
	void SetAge(string Age);
	void PrintStudentData();
	void SetEmail(string email);
	void SetLastName(string lastName);
	void SetFirstName(string firstName);
	void SetStudentId(string studentId);
	void SetDegreeProgram(string degree);
	void SetDaysToCompleteCourse(int daysInCourse[]);

private:
	// Set Class Variables
	string email;
	string age;
	string lastName;
	string firstName;
	string studentId;
	int *daysInCourse;

protected:
	Degree degreeType;

};

#endif // STUDENT