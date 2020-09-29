
/*****************************************************************
//
//  NAME:        Chase Lee
//
//  HOMEWORK:    project
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        March 17, 2020
//
//  FILE:        database.h
//
//  DESCRIPTION:
//   This is the header files for the database.c program, this also
//   includes "record.h" header file for the struct records. These
//   prototyes allow the functions to be called in the user interface.
//   This includes the descriptions of the methods
//
****************************************************************/
#include "record.h"

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   A method that allows the user to access the database
//                 This function is just a stub featuring a stub function for now
//
//  Parameters:    struct record **, int, char [ ], char [ ]. These are the accounts
//                      with their respective data such as account number, name, and
//                      mailing address
//
//  Return values:  0 : success
//
//
****************************************************************/
int addRecord (struct record **, int, char [ ],char [ ]);

/*****************************************************************
//
//  Function name: printRecord
//
//  DESCRIPTION:   A function that displays all of the records that
//                 are available in the future database
//
//  Parameters:    struct record *, int: struct record * is the memory address
//                               of the record structure, and the int is the 
//                               account number
//
//  Return values:  0 : success
//
****************************************************************/
int printRecord (struct record *, int);

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   A function that will display all records in the
//                 database that will be filled in the future
//
//  Parameters:    struct record * the memory address of a record structure
//
//  Return values:  n/a
//
****************************************************************/
void printAllRecords(struct record *);

/*****************************************************************
//
//  Function name: modifyRecord
//
//  DESCRIPTION:   A function that would modify a record in the
//                 database but is currently a stub
//
//  Parameters:    struct record *, int, char [ ]; the struture of the record
//                 pointer, account number, and memory address
//
//  Return values:  0 : success
//
****************************************************************/
int modifyRecord (struct record *, int, char [ ]);

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   This function would delete the record from a database
//                 but this is currently a stub with a debugger for now
//
//  Parameters:    struct record **, int; pointer of a struct record pointer
//                 and the account number of the record
//
//  Return values:  0 : success
//
****************************************************************/
int deleteRecord(struct record **, int);

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   Reads from a file for the database, will fill a linked
//                 list in the program with records if there are any
//
//  Parameters:    start (struct record **) : The pointer of a pointer that points to
//                                            the beginning of the linked list in the program
//                 file (char*) : The name of the file that is being read from
//
//  Return values:  0 : success
//                 -1 : the value was not found
//
****************************************************************/
int readfile(struct record **, char[]);

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   Writes the linked list of records in the current program
//                 to the name of the file that is passed to the function
//
//  Parameters:    start (struct record *) : The beginning of the records in a linked list
//                 file (char*) : The name of the text file being copied to
//
//  Return values:  0 : success
//                 -1 : could not write to the given file
//
****************************************************************/
int writefile(struct record *, char[]);

/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   Removes the linked list of records in the program
//                 before the program ends
//
//  Parameters:    start (struct record **) : Pointer to the struct record *
//                                            in the main
//  Return values: n/a
//
****************************************************************/
void cleanup(struct record **);
