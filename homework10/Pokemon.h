/*****************************************************************
//
//  NAME:        Chase Lee
//
//  HOMEWORK:    homework 10
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        May 8, 2020
//
//  FILE:        hw1main.c
//
//  DESCRIPTION:
//   Pokemon header file, this is the base abstract class. This will
//   pass down type and height for derived classes. The keyword virtual is added
//   to the deconstructor and printData() methods because those are
//   functions that will be used in derived classes.
//
****************************************************************/
#ifndef PKMNH
    #define PKMNH
    #include <iostream>
    using namespace std;

    class Pokemon
    {
    protected:
        string type;
        float height;

    public:
        Pokemon();
        virtual ~Pokemon() = 0;
        virtual void printData() = 0;
    };
#endif
