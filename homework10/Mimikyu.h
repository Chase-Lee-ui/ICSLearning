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
//  FILE:        Mimikyu.h
//
//  DESCRIPTION:
//   This file contains the header file to the child class Mimikyu
//   changes the printData() function to print out variables specific
//   to Mimikyu
//
****************************************************************/

#include <iostream>
#include "Pokemon.h"
using namespace std;

class Mimikyu : public Pokemon
{
public:
    Mimikyu();
    virtual ~Mimikyu();
    void printData();
};
