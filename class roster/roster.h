#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

#include "roster.h"
#include "student.h"

class Roster {
public:
	Roster(int maxSize);
	
	void ParseStudentId(string studentInformation);
	//required functions E(3)(a-f)
	void add(string studentID, string firstName, string lastName, string email, int age, int firstDaysInCourse, int secondDaysInCourse, int thirdDaysInCourse, Degree type);
	void remove(string studentId);
	void printAll();
	void printAverageDaysInCourse(string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degreeProgram);
private:
	int lastIndex;
	int maxSize;
	Student **students;
	string studentId;
	string firstName;
	string lastName;
	string email;
	string age;
	int *daysInCourse;
	string degreeType;
};

#endif