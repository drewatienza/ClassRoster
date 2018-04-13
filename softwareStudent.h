//
// Created by Drew Atienza on 4/12/18.
//

#pragma once

#include "student.h"

class SoftwareStudent : public Student
{
private:
    Degree DegreeType = SOFTWARE;
public:
    virtual Degree getDegreeProgram();
    using Student::Student;
};
