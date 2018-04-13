//
// Created by Drew Atienza on 4/12/18.
//

#pragma once

#include "student.h"

class SecurityStudent : public Student
{
private:
    Degree DegreeType = SECURITY;
public:
    virtual Degree getDegreeProgram();
    using Student::Student;
};