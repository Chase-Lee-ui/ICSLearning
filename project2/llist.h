/*****************************************************************
//
//  NAME:        Chase Lee
//
//  HOMEWORK:    project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        April 19, 2020
//
//  FILE:        llist.h
//
//  DESCRIPTION:
//   This file contains the function headers of all of the variables
//   and functions that will be used in a database program and will be
//   defined in llist.cpp
//
****************************************************************/

#include "record.h"
class llist
{
private:
    record *    start;
    char        filename[16];
    int         readfile();
    int         writefile();
    record *    reverse(record * );
    void        cleanup();

public:
    llist();
    llist(char[]);
    llist(const llist&);
    ~llist();
    int addRecord(int, char [ ],char [ ]);
    int printRecord(int);
    int modifyRecord(int, char [ ]);
    int deleteRecord(int);
    void reverse();
    friend std::ostream& operator<<(std::ostream& os, const llist& list);
    llist& operator=(const llist &list);
};
