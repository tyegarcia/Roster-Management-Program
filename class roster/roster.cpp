#include "roster.h"

Roster::Roster(int maxSize) {
	const string studentData[] = { 
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY"		,
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK"	,
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE"		,
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY"		,
		"A5,Tye,Garcia,tye@wgu.edu,31,15,31,45,SOFTWARE"
	};

	this->lastIndex = -1;
	this->maxSize = maxSize;
	this->students = new Student*[maxSize]; // create new pointer array to hold student objects

	for (int i = 0; i < maxSize; ++i) {
		
		ParseStudentId(studentData[i]);
		if (degreeType == "SECURITY") {
			students[i] = new SecurityStudent(studentId, firstName, lastName, email, age, daysInCourse, SECURITY);
			++lastIndex;
		}
		else if (degreeType == "NETWORK") {
			students[i] = new NetworkStudent(studentId, firstName, lastName, email, age, daysInCourse, NETWORKING);
			++lastIndex;
		}
		else if (degreeType == "SOFTWARE") {
			students[i] = new SoftwareStudent(studentId, firstName, lastName, email, age, daysInCourse, SOFTWARE);
			++lastIndex;
		}
		else {
			cout << "Degree Type assigned is improper." << endl;
		}
	}
}

Roster::~Roster() {
	cout << "Roster destructor called" << endl;
	delete[] students;
}

void Roster::ParseStudentId(string studentData) {
	stringstream studentSS(studentData);
	vector<string> studentDataVector;
	
	for (int i = 0; i < 9; ++i) {	//parse string
		string substr;
		getline(studentSS, substr, ',');
		studentDataVector.push_back(substr);
	}
	
	studentId   = studentDataVector.at(0);	//set to data members
	firstName   = studentDataVector.at(1);
	lastName    = studentDataVector.at(2);
	email       = studentDataVector.at(3);
	age         = studentDataVector.at(4);
	this->daysInCourse = new int[3];
	for (int i = 0; i < 3; ++i) this->daysInCourse[i] = stoi(studentDataVector.at(i+5));
	degreeType  = studentDataVector.at(8);
	return;
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int firstDaysInCourse, int secondDaysInCourse, int thirdDaysInCourse, Degree type) {
	this->daysInCourse = new int[3];
	this->daysInCourse[0] = firstDaysInCourse;
	this->daysInCourse[1] = secondDaysInCourse;
	this->daysInCourse[2] = thirdDaysInCourse;
	this->age = to_string(age);
	

	Student **tempStudents = new Student*[maxSize];
	for (int i = 0; i < maxSize; i++) tempStudents[i] = students[i];
	delete[] students;
	students = new Student*[++maxSize];
	for (int i = 0; i < maxSize - 1; i++) students[i] = tempStudents[i];

	if (type == SECURITY) {
		students[lastIndex + 1] = new SecurityStudent(studentID, firstName, lastName, emailAddress, this->age, daysInCourse, SECURITY);
		++lastIndex;
	}
	else if (type == NETWORKING) {
		students[lastIndex + 1] = new NetworkStudent(studentID, firstName, lastName, emailAddress, this->age, daysInCourse, NETWORKING);
		++lastIndex;
	}
	else if (type == SOFTWARE) {
		students[lastIndex + 1] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, this->age, daysInCourse, SOFTWARE);
		++lastIndex;
	}
	else {
		cout << "Improper or unassigned degree type" << endl;
		return;
	}
	cout << endl << "Student added." << endl;
	return;
}

void Roster::remove(string studentID) {
	cout << endl;
	for (int i = 0; i < maxSize; ++i) {
		if (students[i]->GetStudentId() == studentID) {
			cout << "Deleting: " << students[i]->GetStudentId() << endl;
			for (; i < maxSize - 1; ++i) students[i] = students[i + 1];
			--maxSize;
			return;
		}
	}
	cout << "Error: Student not found..." << endl;
	return;
}

void Roster::printAll() {
	cout << endl;
	int i = 0;
	for (int i = 0; i < maxSize; ++i) {
		cout << i + 1 << "   ";
		students[i]->PrintData();
	}

	return;
}

void Roster::printInvalidEmails() {
	cout << endl << "\nPrint invalid emails: \n" << endl;
	for (int i = 0; i < maxSize; ++i) {
		string email = students[i]->GetEmailAddress();
		int positionAtSign = email.find('@');
		int periodAfterAtSign = email.find('.', positionAtSign);
		if (periodAfterAtSign == -1) cout << "\t" << email << endl;
		else if(email.find(' ') != -1) cout << "\t" << email << endl;
	}
	cout << endl;
	return;
}

void Roster::printAverageDaysInCourse(string studentID) {
	cout << endl;
	for (int i = 0; i < maxSize; ++i) {
		if (students[i]->GetStudentId() == studentID) {
			cout << "Student ID: " << students[i]->GetStudentId();
			int *tempDays = students[i]->GetDaysInCourse();
			int avgDays = 0;
			for (int j = 0; j < 3; ++j) {
				avgDays += tempDays[j];
			}
			cout << "\tAverage number of days: " << avgDays / 3 << endl << endl;
			return;
		}
	}
}

void Roster::printByDegreeProgram(Degree degreeProgram) {
	int numberMatches = 0;
	for (int i = 0; i < maxSize; ++i) {
		if (students[i]->GetDegreeProgram() == degreeProgram) {
			++numberMatches;
			cout << numberMatches << "   ";
			students[i]->PrintData();
		}
	}
	return;
}

int main() {
	int maxSize = 5;
	
	cout << endl << "C867 Scripting and Programming\t C++    #000000000   Tye Garcia" << endl << endl;
	
	Roster* classRoster = new Roster(maxSize);   //create classRoster, add each student to classRoster

	classRoster->printAll();

	classRoster->printInvalidEmails();

	for (int i = 0; i < maxSize; ++i) { //loop through printAverageDaysInCourse("A1")
		ostringstream idOSS;
		idOSS << "A" << i+1;
		classRoster->printAverageDaysInCourse(idOSS.str()); 
	}

	classRoster->printByDegreeProgram(SOFTWARE);

	classRoster->remove("A3");
	classRoster->remove("A3");

	char exitSign = 'a';
	while (exitSign != 'q') {
		

		cout << "\nenter 'q' to quit...";
		cin >> exitSign;
		cout << endl << endl;
	}
	
	return 0;
}
