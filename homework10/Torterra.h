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
//  FILE:        Torterra.h
//
//  DESCRIPTION:
//   This file contains the header file to the child class Torterra
//   changes the printData() function to print out variables specific
//   to Torterra
//
****************************************************************/

#include <iostream>
#include "Pokemon.h"
using namespace std;

class Torterra : public Pokemon
{
public:
    Torterra();
    virtual ~Torterra();
    void printData();
};
