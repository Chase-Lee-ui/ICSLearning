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
//  FILE:        Pokemon.cpp
//
//  DESCRIPTION:
//    This file holds the constructor and deconstructor for the Pokemon
//    class and the template for the printData() function that will be
//    used in 3 child classes
//
****************************************************************/

#include <iostream>
#include <string>
#include "Pokemon.h"
using namespace std;

/*****************************************************************
//
//  Function name: Pokemon()
//
//  DESCRIPTION:   Pokemon class constructor that prints out Pokemon
//                 Constructor
//
//  Parameters:    n/a
//
//  Return values:  n/a
//
****************************************************************/

Pokemon::Pokemon()
{
    cout << "<Pokemon> Constructor" << endl;
}

/*****************************************************************
//
//  Function name: ~Pokemon()
//
//  DESCRIPTION:   Pokemon class deconstructor that prints out Pokemon
//                 Deonstructor
//
//  Parameters:    n/a
//
//  Return values:  n/a
//
****************************************************************/

Pokemon::~Pokemon()
{
    cout << "<Pokemon> Deconstructor\n" << endl;
}

/*****************************************************************
//
//  Function name: printData()
//
//  DESCRIPTION:   Pure virtual method, only purpose is to be used in subclasses
//
//  Parameters:    n/a
//
//  Return values:  n/a
//
****************************************************************/

void Pokemon::printData()
{
    cout << "Not to be displayed because this is true virtual function" << endl;
}
