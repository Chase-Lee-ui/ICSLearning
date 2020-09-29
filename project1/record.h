/*****************************************************************
//
//  NAME:        Chase Lee
//
//  HOMEWORK:    3B
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        February 16, 2020
//
//  FILE:        record.h
//
//  DESCRIPTION:
//   This file contains the structure of a record, it holds the layout
//   for account number, name, mailing address, and points to a record
//   pointer.
//
****************************************************************/
struct record
{
    int                accountno;
    char               name[25];
    char               address[80];
    struct record*     next;
};
