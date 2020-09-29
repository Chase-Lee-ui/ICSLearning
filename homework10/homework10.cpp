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
//  FILE:        homework10.cpp
//
//  DESCRIPTION:
//   This file holds the driver file for the Pokemon and Pokemon 
//   child classes. Vector and Maps hold the addresses to derived
//   Pokemon classes.
//
****************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include "Torterra.h"
#include "Mimikyu.h"
#include "Heracross.h"
using namespace std;

void checkPokedex(Pokemon *pokemon);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   The main function which works as the driver function
//                 for the Pokemon parent class and subclasses
//
//  Parameters:    argc (int) : The amount of arguments
//                 argv (char**) : The pointer to char[]
//
//  Return values:  0 : success
//
****************************************************************/

int main(int argc, char* argv[])
{
    vector<Pokemon*> keys;
    std::map<string, Pokemon*> mapp;
    map<string, Pokemon*>::iterator access;
    Torterra tort;
    Mimikyu mimi;
    Heracross hera;
    int i, j;

    mapp["Torterra"] = &tort;
    mapp["Mimikyu"] = &mimi;
    mapp["Heracross"] = &hera;

    keys.push_back(&tort);
    keys.push_back(&mimi);
    keys.push_back(&hera);

    cout << "Opening the map container" << endl;
    for(access = mapp.begin(); access != mapp.end(); access++)
    {
        cout << access->first  << " key, accessing matching pair in the map container"<< endl;
        checkPokedex(access->second);
    }

    j = keys.size();
    cout << "Opening the vector container" << endl;
    for(i = 0; i < j; i++)
    {
        checkPokedex(keys[i]);
    }

    mapp.clear();
    keys.clear();
    keys[0] = NULL;

    return 0;
}

/*****************************************************************
//
//  Function name: checkPokedex
//
//  DESCRIPTION:   A function that accesses the function printData()
//                 in child classes. 
//
//  Parameters:    pokemon (Pokemon *) : The address of Pokemon child
//                                       classes so that printData()
//                                       can be accessed
//
//  Return values:  n/a
//
****************************************************************/

void checkPokedex(Pokemon pokemon)
{
}
