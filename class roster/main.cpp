#include "student.h"
#include "roster.h"

int main(){
    int maxSize = 5;
	
	cout << endl << "My Name" << endl << endl;
	
	Roster* myRoster = new Roster(maxSize); 

	myRoster->printInvalidEmails();
    myRoster->printAll();

	for (int i = 0; i < maxSize; ++i) { 
		ostringstream obj;
		obj << "A" << i+1;
		myRoster->printAverageDaysInCourse(obj.str()); 
	}

	myRoster->printByDegreeProgram(SOFTWARE);

	myRoster->remove("A3");
	myRoster->remove("A3");

	char var_exit = 'a';
	while (var_exit != 'q') {
		

		cout << "\nenter 'q' to quit...";
		cin >> var_exit;
		cout << endl;
	}
    return 0;
}