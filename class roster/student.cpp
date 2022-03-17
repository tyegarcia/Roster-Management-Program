#include "student.h"
#include <iostream>

using namespace std;

// Begin class contructor
Student::Student() {
	studentId = "";
	firstName = "";
	lastName = "";
	email = "";
	age = ""; 
	this->daysInCourse = new int[3];
}

Student::Student(string studentId, string firstName, string lastName, string email, string age, int daysInCourse[], Degree type) {
	this->age = age;
	this->email = email;
	this->lastName = lastName;
	this->studentId = studentId;
	this->firstName = firstName;
	this->daysInCourse = new int[3];
	for (int i = 0; i < 3; i++) this->daysInCourse[i] = daysInCourse[i];
}

// Methods to get Student Data

string Student::GetAge() {
	return studentAge;
}
string Student::GetEmail() {
	return emailAddress;
}
string Student::GetLastName() {
	return lastName;
}
string Student::GetStudentId() {
	return studentId;
}
string Student::GetFirstName() {
	return firstName;
}
int* Student::GetDaysInCourse() { 
	return daysInCourse;
}
Degree Student::GetDegreeProgram() {
	return degreeType; 
}

//	Methods to set Student Data
void Student::SetAge(string studentAge) {
	this->studentAge = studentAge;
	return;
}
void Student::SetEmail(string emailAddress) {
	this->emailAddress = emailAddress;
	return;
}
void Student::SetLastName(string lastName) {
	this->lastName = lastName;
	return;
}
void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
	return;
}
void Student::SetStudentId(string studentId) {
	this->studentId = studentId;
	return;
}
void Student::SetDaysToCompleteCourse(int daysInCourse[]) {
	for (int i = 0; i < 3; i++){
		this->daysInCourse[i] = daysInCourse[i];
	} 
}

void Student::PrintStudentData(){
	int *tempdays = GetDaysInCourse();
	cout << "First Name: " << GetFirstName() << "\t Last Name: " << GetLastName() << "\t Age: " << GetStudentAge() << "\t daysInCourse: " << "{" << tempdays[0] << ", " << tempdays[1] << ", " << tempdays[2] << "}" << " Degree Program: " << GetDegreeProgram() << "." << endl;
}
