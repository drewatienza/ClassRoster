//
// Created by Drew Atienza on 4/12/18.
//

#pragma once

#include "student.h"

class NetworkStudent : public Student
{
private:
    Degree DegreeType = NETWORKING;
public:
    virtual Degree getDegreeProgram();
    using Student::Student;
};
