#include "Student.h"
#include "degree.h"
#include <string>
#include <iostream>
std::string Student::getId() {
    return studentId;
}
std::string Student::getFN() {
    return firstName;
}
std::string Student::getLN() {
    return lastName;
}
std::string Student::getEmail() {
    return emailAddress;
}
int Student::getAge() {
    return age;
}
int *Student::getDays() {
    /*the array here is static because a pointer to an array in the printAverageDaysInCourse in Roster.cpp will point to
    the array returned by getdays*/
    static int days[3];
     days[0] = numOfDays[0];
     days[1] = numOfDays[1];
     days[2] = numOfDays[2];
     return days;
}
DegreeProgram Student::getProgram() {
    return degreeProgram;
}
void Student::setId(std::string ID) {
    studentId = ID;
}
void Student::setFN(std::string FN) {
    firstName = FN;
}
void Student::setLN(std::string LN) {
    lastName = LN;
}
void Student::setEmail(std::string email) {
    emailAddress = email;
}
void Student::setAge(int ageOfStudent) {
    age = ageOfStudent;
}
void Student::setDays(int day1, int day2, int day3) {
    numOfDays[0] = day1;
    numOfDays[1] = day2;
    numOfDays[2] = day3;
}
void Student::setProgram(DegreeProgram program) {
    degreeProgram = program;
}
void Student::print() {
    std::cout << studentId << '\t' << firstName << '\t' << lastName << '\t'
    << age << '\t' << "{" << numOfDays[0] << "," << numOfDays[1] << "," << numOfDays[2] << "}" << '\t';
    //switch statement here is used to turn the enumeration into the coresponding string when displaying.
    switch(degreeProgram) {
        case SECURITY: std::cout << "SECURITY";
        break;
        case NETWORK: std::cout << "NETWORK";
        break;
        case SOFTWARE: std::cout << "SOFTWARE";
        break;
    }
}




Student::Student ()  {

}

// used array in constructor for number of days as requested in the revision.
Student::Student(std::string ID, std::string FN, std::string LN, std::string email, int ageOfStudent, int days[3], DegreeProgram program)
 : studentId {ID}, firstName {FN}, lastName {LN}, emailAddress {email}, age {ageOfStudent}, degreeProgram {program} {
    for (int i{ 0 }; i < 3; i++) {
        numOfDays[i] = days[i];
    }
  }
 