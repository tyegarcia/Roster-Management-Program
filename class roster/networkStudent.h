#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "student.h"

class NetworkStudent : public Student {
public:
	NetworkStudent(string studentId, string firstName, string lastName, string email, string age, int daysInCourse[], Degree type);
	~NetworkStudent();
	Degree GetDegreeProgram();
	void PrintData();
private:
	Degree degreeProgram;
};

#endif