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
//  FILE:        Torterra.cpp
//
//  DESCRIPTION:
//   This file holds the method defintions of the Torterra.h file
//   which constructs it to the properties of the Pokemon Torterra.
//   Prints data directly related to this class.
//
****************************************************************/

#include <iostream>
#include "Torterra.h"
using namespace std;

/*****************************************************************
//
//  Function name: Torterra()
//
//  DESCRIPTION:   Torterra constructor, changes variables to the
//                 correct properties
//
//  Parameters:    n/a
//
//  Return values:  n/a
//
****************************************************************/

Torterra::Torterra()
{
    type = "Grass/Ground";
    height = 87;
    cout << "<Torterra> Constructor\n" << endl;
}

/*****************************************************************
//
//  Function name: ~Torterra()
//
//  DESCRIPTION:   Torterra deconstructor
//
//  Parameters:    n/a
//
//  Return values:  n/a
//
****************************************************************/

Torterra::~Torterra()
{
    cout << "<Torterra> Deconstructor" << endl;
}

/*****************************************************************
//
//  Function name: printData()
//
//  DESCRIPTION:   Prints the details to the Torterra class by printing
//                 all the variables stored in this class
//
//  Parameters:    n/a
//
//  Return values:  n/a
//
****************************************************************/

void Torterra::printData()
{
    cout << "Printing Torterra Data" << endl;
    cout << "Pokemon type: " << type << endl;
    cout << "Pokemon height: " << height << " inches\n"<< endl;
}
