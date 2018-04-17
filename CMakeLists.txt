cmake_minimum_required(VERSION 3.9)
project(ClassRoster)

set(CMAKE_CXX_STANDARD 11)

add_executable(ClassRoster degree.h
        student.cpp student.h
        networkStudent.cpp networkStudent.h
        securityStudent.cpp securityStudent.h
        softwareStudent.cpp softwareStudent.h
        roster.cpp roster.h)