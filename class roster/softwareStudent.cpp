#include "softwareStudent.h"

SoftwareStudent::SoftwareStudent(string studentId, string firstName, string lastName, string email, string age, int daysInCourse[], Degree type)
	: Student(studentId, firstName, lastName, email, age, daysInCourse, type) {
	degreeProgram = type;
	degreeType = degreeProgram;
}

SoftwareStudent::~SoftwareStudent() {
	cout << "SoftwareStudent destructor called" << endl;
}

Degree SoftwareStudent::GetDegreeProgram() {
	return degreeProgram;
}

void SoftwareStudent::PrintData() {
	int *tempdays = GetDaysInCourse(); //temp holder for daysInCourse
	cout << "First Name: " << GetFirstName() << "\tLast Name: " << GetLastName();
	cout << "\t Age: " << GetStudentAge() << "\t daysInCourse: ";
	cout << "{" << tempdays[0] << ", " << tempdays[1] << ", " << tempdays[2] << "}";
	cout << " Degree Program: Software." << endl;
	return;
}