//
// Created by Drew Atienza on 4/12/18.
//

#pragma once

#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

class Student {
private:
    int Age, DaysInCourse[3];
    string StudentId, FirstName, LastName, Email;
    Degree DegreeType;

public:
    string getStudentId();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int *getDaysInCourse();
    Degree getDegreeType();

    void setStudentId(string);
    void setFirstName(string);
    void setLastName(string);
    void setEmail(string);
    void setAge(int);
    void setDaysInCourse(int[3]);
    void setDegreeType(Degree);

    virtual void print();
    virtual Degree getDegreeProgram();
};
