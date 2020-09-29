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
//  FILE:        Heracross.cpp
//
//  DESCRIPTION:
//   This file holds the method defintions of the Heracross.h file
//   which constructs it to the properties of the Pokemon Heracross.
//   Prints data directly related to this class.
//
****************************************************************/

#include <iostream>
#include "Heracross.h"
using namespace std;

/*****************************************************************
//
//  Function name: Heracross()
//
//  DESCRIPTION:   Heracross constructor, changes variables to the
//                 correct properties
//
//  Parameters:    n/a
//
//  Return values:  n/a
//
****************************************************************/

Heracross::Heracross()
{
    type = "Bug/Fighting";
    height = 59;
    cout << "<Heracross> Constructor\n" << endl;
}

/*****************************************************************
//
//  Function name: ~Heracross()
//
//  DESCRIPTION:   Heracross deconstructor
//
//  Parameters:    n/a
//
//  Return values:  n/a
//
****************************************************************/

Heracross::~Heracross()
{
    cout << "<Heracross> Deconstructor" << endl;
}

/*****************************************************************
//
//  Function name: printData()
//
//  DESCRIPTION:   Prints the details to the Heracross class by printing
//                 all the variables stored in this class
//
//  Parameters:    n/a
//
//  Return values:  n/a
//
****************************************************************/

void Heracross::printData()
{
    cout << "Printing Heracross Data" << endl;
    cout << "Pokemon type: " << type << endl;
    cout << "Pokemon height: " << height << " inches\n"<< endl;
}
