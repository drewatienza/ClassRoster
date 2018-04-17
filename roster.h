//
// Created by Drew Atienza on 4/12/18.
//

#pragma once

#include <iostream>
#include <string>
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"

class Roster {
public:
    Student * classRosterArray[5] =
            {
                    nullptr,
                    nullptr,
                    nullptr,
                    nullptr,
                    nullptr
            };

    void add(
            string studentID,
            string firstName,
            string lastName,
            string emailAddress,
            int age,
            int daysInCourse1,
            int daysInCourse2,
            int daysInCourse3,
            Degree degreeProgram
    );
    void remove(string studentID);
    void printAll();
    void printDaysInCourse(string studentID);
    void printInvalidEmail();
    void printByDegreeProgram(int degreeProgram);
};
