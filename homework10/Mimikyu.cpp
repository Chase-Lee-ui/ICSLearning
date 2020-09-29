/*****************************************************************
//
//  NAME:        Chase Lee
//
//  HOMEWORK:    1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        May 8, 2020
//
//  FILE:        Mimikyu.cpp
//
//  DESCRIPTION:
//   This file holds the method defintions of the Mimikyu.h file
//   which constructs it to the properties of the Pokemon Mimikyu.
//   Prints data directly related to this class.
//
****************************************************************/

#include <iostream>
#include "Mimikyu.h"
using namespace std;

/*****************************************************************
//
//  Function name: Mimikyu()
//
//  DESCRIPTION:   Mimikyu constructor, changes variables to the
//                 correct properties
//
//  Parameters:    n/a
//
//  Return values:  n/a
//
****************************************************************/

Mimikyu::Mimikyu()
{
    type = "Ghost/Fairy";
    height = 20;
    cout << "<Mimikyu> Constructor\n" << endl;
}

/*****************************************************************
//
//  Function name: ~Mimikyu()
//
//  DESCRIPTION:   Mimikyu deconstructor
//
//  Parameters:    n/a
//
//  Return values:  n/a
//
****************************************************************/

Mimikyu::~Mimikyu()
{
    cout << "<Mimikyu> Deconstructor" << endl;
}

/*****************************************************************
//
//  Function name: printData()
//
//  DESCRIPTION:   Prints the details to the Mimikyu class by printing
//                 all the variables stored in this class
//
//  Parameters:    n/a
//
//  Return values:  n/a
//
****************************************************************/

void Mimikyu::printData()
{
    cout << "Printing Mimikyu Data" << endl;
    cout << "Pokemon type: " << type << endl;
    cout << "Pokemon height: " << height << " inches\n"<< endl;
}
