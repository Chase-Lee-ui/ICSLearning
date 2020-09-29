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
//  FILE:        record.h
//
//  DESCRIPTION:
//   This file contains the specifications for the structure of a
//   record that will be used in user-interface.cpp and llist.cpp
//
****************************************************************/

struct record {
    int accountno;
    char name[25];
    char address[80];
    struct record* next;
};
