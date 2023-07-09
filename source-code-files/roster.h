#ifndef ROSTER_H
#define ROSTER_H
#include <string>
#include "Student.h"
#include "degree.h"
#pragma once

class Roster
{
	private:
  
	public:
	Student *classRosterArray[5] {nullptr, nullptr, nullptr, nullptr, nullptr};
	Roster ();
	~Roster ();
	void parse(const std::string classRoster[], int size = 5);
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void remove(std::string studentID);
	std::string getIdInLoop(int a);

};

#endif