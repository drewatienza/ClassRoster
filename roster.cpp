//
// Created by Drew Atienza on 4/12/18.
//

#include "roster.h"
#include <sstream>
#include <iostream>

using namespace std;

int main() {
    cout << "WGU C867 Scripting and Programming - Applications" << endl;
    cout << "Programming Language Used: C++" << endl;
    cout << "Student ID: 000818483" << endl;
    cout << "Andrew Atienza" << endl;
    cout << endl;

    Roster classRoster;

    const string studentData[] =
            {
                    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                    "A3,Jack,Napoli,The_layer99yahoo.com,19,20,40,33,SOFTWARE",
                    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                    "A5,Andrew,Atienza,aatien1@wgu.edu,39,15,12,24,SOFTWARE"
            };

    for(int i = 0; i < sizeof(studentData) / sizeof(studentData[i]); i++) {
        Degree studentDegree;
        string input = studentData[i];
        string insert[9];
        istringstream ss(input);
        string temp;

        int a = 0;
        while(getline(ss, temp, ',')) {
            insert[a] = temp;
            a += 1;
            if(insert[8] == "SECURITY") {
                studentDegree = SECURITY;
            } else if (insert[8] == "NETWORK") {
                studentDegree = NETWORKING;
            } else {
                studentDegree = SOFTWARE;
            }
        }

        classRoster.add(
                insert[0],
                insert[1],
                insert[2],
                insert[3],
                std::stoi(insert[4]),
                std::stoi(insert[5]),
                std::stoi(insert[6]),
                std::stoi(insert[7]),
                studentDegree
        );
    }

    classRoster.printAll();
    cout << endl;

    classRoster.printInvalidEmail();
    cout << endl;

    for(int i = 0; i < sizeof(classRoster.classRosterArray) / sizeof(classRoster.classRosterArray[i]); i++) {
        classRoster.printDaysInCourse(classRoster.classRosterArray[i] -> getStudentId());
    }
    cout << endl;

    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    classRoster.remove("A3");
    cout << endl;
    classRoster.remove("A3");
    cout << endl;
}

void Roster::add(
        string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        Degree degreeProgram
){
    int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

    for(int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if(classRosterArray[i] == nullptr) {
            if(degreeProgram == SECURITY) {
                classRosterArray[i] = new SecurityStudent(
                        studentID,
                        firstName,
                        lastName,
                        emailAddress,
                        age,
                        days,degreeProgram
                );
            } else if (degreeProgram == NETWORKING) {
                classRosterArray[i] = new NetworkStudent(
                        studentID,
                        firstName,
                        lastName,
                        emailAddress,
                        age,
                        days,degreeProgram
                );
            } else {
                classRosterArray[i] = new SoftwareStudent(
                        studentID,
                        firstName,
                        lastName,
                        emailAddress,
                        age,
                        days,degreeProgram
                );
            }
            break;
        }
    }
}

void Roster::remove(string studentID) {
    bool findId = false;
    for(int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if(classRosterArray[i] != nullptr) {
            if(classRosterArray[i] -> getStudentId() == studentID) {
                classRosterArray[i] = nullptr;
                findId = true;
            }
        }
    }
    if(findId == true) {
        cout << "Student ID " << studentID << " has now been removed." << endl;
    } else {
        cout << "Student ID " << studentID << " cannot be removed because that student ID does not exist." << endl;
    }
}

void Roster::printAll() {
    for(int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        classRosterArray[i] -> print();
    }
}

void Roster::printDaysInCourse(string studentID) {
    int totalDays = 0;
    for(int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if(classRosterArray[i] != nullptr) {
            if(classRosterArray[i] -> getStudentId() == studentID) {
                int* daysInCourse = classRosterArray[i] -> getDaysInCourse();
                for(int j = 0; j < 3; j++) {
                    totalDays = totalDays + daysInCourse[j];
                }
                int averageDays = totalDays/3;

                cout << "Student " << classRosterArray[i] -> getStudentId() << " has spent a total of " << totalDays
                     << " days in his/her courses averaging " << averageDays << " days per course." << endl;
            }
        }
    }
}

void Roster::printInvalidEmail() {
    for(int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        string checkEmail = classRosterArray[i] -> getEmail();

        size_t at = checkEmail.find('@');
        size_t space = checkEmail.find(' ');
        if(at != string::npos) {
            size_t dot = checkEmail.find('.', at + 1);
            if(dot != string::npos) {
                if(space != string::npos) {
                    cout << checkEmail << " is invalid.  Email address cannot have a space between characters." << endl;
                }
            } else {
                cout << checkEmail << " is invalid.  Email address is missing . symbol after the @ sign." << endl;
            }
        } else {
            cout << checkEmail << " is invalid.  Email address is missing @ symbol." << endl;
        }
    }
}

void Roster::printByDegreeProgram(int degreeProgram) {
    for(int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if(classRosterArray[i] -> getDegreeProgram() == degreeProgram) {
            classRosterArray[i] -> print();
        }
    }
}