#include "Roster.h"
#include "degree.h"
#include <string>
#include <vector>
#include <iostream>
#include "Student.h"
using namespace std;


Roster::Roster () {  

}
/*the parse method below goes through array in main to parse each element in the array and using 
the separated info adds it as an Student object on the heap in the array of pointers classRosterArray.*/
void Roster::parse(const std::string studentData[],int size) {  
    for(int i {0}; i < size; i++) {
        string Id {};
        string Fn {};
        string Ln {};
        string Email {};
        //the string age and the string array days below temporary since it will pushed back into the parsed vector that is of string type.
        string age {};
        string Days[3];
        DegreeProgram program {};
        /*the int array and variable below will hold the days and age that will will be converted from string to int
        to have the correct type when used to add students to the array*/
        int daysAsInteger[3];
        int ageAsInteger{};
    /*the parsed vector is used to hold the parsed parts of string 
     so they can be used later as parameters in the add method*/
        vector <string> parsed {};
        unsigned int punctPos {0};
        int punctCounter {0};
        for(unsigned int u {0}, counter {1}; u < studentData[i].size(); u++, counter++) {
            if (ispunct(studentData[i].at(u))) {
            // below is how the info between commas up to the degree program is stored in the vector
                if (studentData[i].at(u) == ',') {
                    parsed.push_back(studentData[i].substr(punctPos, counter - (punctCounter + 1)));
                    punctPos = u + 1;
                    punctCounter = counter;
                }
            }
            // below is how the degree program is stored in the vector
            if (u == studentData[i].size() - 1) {
            parsed.push_back(studentData[i].substr(punctPos, counter - punctCounter ));
            }
        }
    //below is how the info in the vector is assigned to the right fields for use in the add method.
        Id = parsed.at(0);
        Fn = parsed.at(1);
        Ln = parsed.at(2);
        Email = parsed.at(3);
        
        age = parsed.at(4);
        Days[0] = parsed.at(5);
        Days[1] = parsed.at(6);
        Days[2] = parsed.at(7);
        //here the days in course and the age for a student are coverted from string to int
        daysAsInteger[0] = stoi(Days[0]);
        daysAsInteger[1] = stoi(Days[1]);
        daysAsInteger[2] = stoi(Days[2]);
        ageAsInteger = stoi(age);
    
        if (parsed.at(8) == "SECURITY") {
        program = SECURITY;
        }
        else if (parsed.at(8) == "NETWORK") {
        program = NETWORK;
        }
        else if(parsed.at(8) == "SOFTWARE") {
        program = SOFTWARE;
        }
    /* here the add method below uses the stored info through parsing to create a new Student on the heap 
    using the next nullptr in the classRosterArray.*/
        Roster::add(Id, Fn, Ln, Email, ageAsInteger, daysAsInteger[0], daysAsInteger[1], daysAsInteger[2], program);


    }
}
/* the add method below  to loops through classRosterArray in order and uses the parameters to create a new 
Student on the heap and assign it to the pointer in if it's not pointing to another Student.
this is used inside the parse function.*/
void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
    int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
    int daysArray[3];
    daysArray[0] = daysInCourse1;
    daysArray[1] = daysInCourse2;
    daysArray[2] = daysInCourse3;
    for(size_t i {0}; i < 5; i++) {
        if(classRosterArray[i] == nullptr) {
            classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeprogram);
            break;
        }
    }

}
/* the remove method below loops through the classRosterArray and for every pointer that's not pointing to nullptr,
 it checks to see if the Student object id matches the one provided in the parameter. If so, the pointer is assigned 
 nullptr so that the Student object would be removed*/
void Roster::remove(string studentID){
    bool Idfound {false};
    int Pos {};
    for(int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr) {
            if(classRosterArray[i]->getId() == studentID) {
            Idfound = true;
            Pos = i;
            break;
            }
        }

    }
    if(Idfound == true) {
        classRosterArray[Pos] = nullptr;
    }

    else if (Idfound == false) {
     cout << "A student with the ID: " << studentID << " was not found." << endl;
    }
}


/*the printAll method below loops through the classRosterArray and for every Student object 
it prints their info to the commandline using the print method of the Student class*/
void Roster::printAll() {
    for(size_t i {0}; i < 5; i++) {
        if(classRosterArray[i] != nullptr) {
        classRosterArray[i]->print();
        cout << endl;
        }
    }
}
/*the method below loops through the classRosterArray and for each pointer that's not a null pointer it checks to see if 
the Student pointed to has an Id matching the one provided in parameter. if so, it gets the days in courses for 
that Student and takes their average*/
void Roster::printAverageDaysInCourse(string studentID) {
    bool exists {false};
    for(size_t i {0}; i < 5; i++) {
        if (classRosterArray[i] != nullptr) {
            if(classRosterArray[i]->getId() == studentID) {
                exists = true;
            //a pointer is used to get the array of days since the Student object is on the heap.
                int *daysPtr = classRosterArray[i]->getDays();
                int daysInCourse1 = daysPtr[0];
                int daysInCourse2 = daysPtr[1];
                int daysInCourse3 = daysPtr[2];
                int avg = (daysInCourse1 + daysInCourse2 + daysInCourse3) / 3;
                cout << "Student ID: " << studentID << ", average number of days in course is: " << avg << endl;
            }
        }
    }
    if(exists == false) {
    cout << "The student with the ID: " << studentID << " was not found." << endl;
    }

}
/*the method below loops through classRosterArray and for every pointer in the classRosterArray that's not a null pointer
it checks to see if the email of field of the Student object is a valid email or not*/
void Roster::printInvalidEmails() {
    for (int i {0}; i < 5; i++) {
        if (classRosterArray[i] != nullptr) {
            string Email {classRosterArray[i]->getEmail()};
       /*the if statement below finds @ and . in the email field of the Student object and also makes sure no space is found. 
       if @ or . is not found or space is found in the email string, then the email is displayed as invalid*/
            if(Email.find("@") == string::npos || Email.find(".") == string::npos || Email.find(" ") != string::npos) {
                cout << Email << " - is invalid." << endl;
            }
        }
    }
}
/*the method below loops through the classRosterArray and for every pointer that's not a null pointer, it checks to 
see if the degreeProgram provided in the parameter matches the the degreeprogram for the Student object pointed to. 
if so, it displays the info for that Student using the print method of the Student class*/
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (size_t i{ 0 }; i < 5; i++) {
        if (classRosterArray[i] != nullptr) {
            if (classRosterArray[i]->getProgram() == degreeProgram) {
                classRosterArray[i]->print();
                cout << endl;
            }
        }
    }
}

/*the method below is used to get a string student id as a parameter to printAverageDaysInCourse in the main function.*/
std::string Roster::getIdInLoop(int a) {
   return classRosterArray[a]->getId();   
}

Roster::~Roster () {
    //to delete every pointer created for the Roster class object in the classRosterArray when the destructor is called.
    for(size_t i {0}; i < 5; i++) {
        delete classRosterArray[i];
    }
}