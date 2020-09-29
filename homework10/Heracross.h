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
//  FILE:        Heracross.h
//
//  DESCRIPTION:
//   This file contains the header file to the child class Heracross
//   changes the printData() function to print out variables specific
//   to Heracross
//
****************************************************************/

#include <iostream>
#include "Pokemon.h"
using namespace std;

class Heracross : public Pokemon
{
public:
    Heracross();
    virtual ~Heracross();
    void printData();
};
