//
// Created by Drew Atienza on 4/12/18.
//

#include "student.h"

string Student::getStudentId() {
    return StudentId;
}
string Student::getFirstName() {
    return FirstName;
}
string Student::getLastName() {
    return LastName;
}
string Student::getEmail() {
    return Email;
}
int Student::getAge() {
    return Age;
}
int* Student::getDaysInCourse() {
    return DaysInCourse;
}
Degree Student::getDegreeType() {
    return Degree();
}
Degree Student::getDegreeProgram() {
    return SOFTWARE;
}

void Student::setStudentId(string studentId) {
    StudentId = studentId;
}
void Student::setFirstName(string firstName) {
    FirstName = firstName;
}
void Student::setLastName(string lastName) {
    LastName = lastName;
}
void Student::setEmail(string email) {
    Email = email;
}
void Student::setAge(int age) {
    Age = age;
}
void Student::setDaysInCourse(int * daysInCourse) {
    for(int i = 0; i < 3; i++) {
        DaysInCourse[i] = daysInCourse[i]
    }
}
void Student::setDegreeType(Degree degreeType) {
    DegreeType = degreeType;
}

Student::Student(
        string studentId,
        string firstName,
        string lastName,
        string email,
        int age,
        int daysInCourse[3],
        Degree degreeType
)
{
    setStudentId(studentId);
    setFirstName(firstName);
    setLastName(lastName);
    setEmail(email);
    setAge(age);
    setDaysInCourse(daysInCourse);
    setDegreeType(degreeType);
}

Student::~Student()
{
}
