#include "securityStudent.h"

SecurityStudent::SecurityStudent(string studentId, string firstName, string lastName, string email, string age, int daysInCourse[], Degree type) 
	: Student(studentId, firstName, lastName, email, age, daysInCourse, type) {
	degreeProgram = type;
	degreeType = degreeProgram;
}

SecurityStudent::~SecurityStudent() {
	cout << "Security Student destructor called" << endl;
}

Degree SecurityStudent::GetDegreeProgram(){
	return degreeProgram;
}

void SecurityStudent::PrintData() {
	int *tempdays = GetDaysInCourse(); //temp holder for daysInCourse
	cout << "First Name: " << GetFirstName() << "\tLast Name: " << GetLastName();
	cout << "\t Age: " << GetStudentAge() << "\t daysInCourse: ";
	cout << "{" << tempdays[0] << ", " << tempdays[1] << ", " << tempdays[2] << "}";
	cout << " Degree Program: Security." << endl;
	return;
}