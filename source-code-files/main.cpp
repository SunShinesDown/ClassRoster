#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Roster.h"
#include "Student.h"
#include "degree.h"
using namespace std;

int main() {
	const string studentData[] = 
	{"A1,John,Smith,John1989@g ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Alireza,Barzegar,alireza.barzegar222@gmail.com,22,53,30,55,SOFTWARE"};
	cout << "C867-Scripting & Programming: Applications\nLanguage: C++\nStudentID: 010057350\nName: Alireza Barzegar Aliabadi\n" << endl;
	Roster classRoster;
	classRoster.parse(studentData);
	cout << "Displaying all students: " << endl;
	classRoster.printAll();
	cout << endl;
	cout << "Displaying invalid emails: " << endl;
	cout << endl;
	classRoster.printInvalidEmails();
	cout << endl;
	cout << "Average number of days in course for each student:\n" << endl;
/*the for loop below prints the average days in course for every Student in the classRosterArray by using 
the number of the current loop iteration as the parameter for getIdInLoop method to get the Student Id that's needed 
as the parameter for the printAverageDaysInCourse.*/
	for (int i{ 0 }; i < 5; i++) {
		classRoster.printAverageDaysInCourse(classRoster.getIdInLoop(i));
}  
	cout << endl;
	cout << "Showing students in degree program: SOFTWARE\n" << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;
	cout << "Removing A3" << endl;
	classRoster.remove("A3");
	cout << endl;
	classRoster.printAll();
	cout << endl;
	cout << "Removing A3 again:" << endl;
	cout << endl;
	classRoster.remove("A3");
	cout << endl;
	cout << "DONE.";
	return 0;
}