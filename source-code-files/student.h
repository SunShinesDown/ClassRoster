#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#pragma once

class Student
{
    private:
    std::string studentId {};
    std::string firstName {};
    std::string lastName {};
    std::string emailAddress {};
    int age {};
    int numOfDays[3];
    DegreeProgram degreeProgram {};
    

    public:
    std::string getId();
    std::string getFN();
    std::string getLN();
    std::string getEmail();
    int getAge();
    int *getDays();
    DegreeProgram getProgram();
    void setId(std::string ID);
    void setFN(std::string FN);
    void setLN(std::string LN);
    void setEmail(std::string email);
    void setAge(int ageOfStudent);
    void setDays(int day1, int day2, int day3);
    void setProgram(DegreeProgram program);
    void print();

    Student();
    Student(std::string ID, std::string FN, std::string LN, std::string email, int ageOfStudent, int days[3], DegreeProgram program);

    ~Student() {}
};

#endif