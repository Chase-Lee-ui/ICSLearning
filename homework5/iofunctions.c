/*****************************************************************
//
//  NAME:        iofunctions.c
//
//  HOMEWORK:    5
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        March 3, 2020
//
//  FILE:        iofunctions.c
//
//  DESCRIPTION:
//   This is the function definition of the readfile and writefile functions for iofunctions.h
//   readfile reads a file given to it by the main which will be called by driver.c
//   writefile writes to a file given to it by the main which will be called by driver.c
****************************************************************/
#include <stdio.h>
#include <string.h>
#include "iofunctions.h"

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   An I/O function that reads a text file that holds
//                 record information and writes it to the record given by the main
//
//  Parameters:    accarray ( struct record [] ) : Contains the record that
//                               readfile will be storing the fields found in the text file
//                 numcust ( int * ) : Contains the address to the integer that holds the
//                               number of customers
//                 filename ( char [] ) : Holds the string that is the file name that will be read
//  Return values:  0 : success
//                 -1 : text file was not found or could not read
//
****************************************************************/
int readfile( struct record accarray[ ], int* numcust, char filename[ ] )
{
    FILE *fp;
    char c;
    char buffer[1000];
    int acctno;
    int i = 0;
    int rval = 0;
    
    fp = fopen(filename, "r");

    if(fp)
    {
        while(c != EOF || i < *(numcust))
        {
           fscanf(fp, "%d", &acctno);
           accarray[i].accountno = acctno;

           fscanf(fp, "%s", buffer);
           strcpy(accarray[i].name, buffer);

           fscanf(fp, "%s", buffer);
           strcpy(accarray[i].address, buffer);

           c = fgetc(fp);
           i++;
        }
        fclose(fp);
    }
    else
    {
        rval = -1;
    }
    return rval;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   An I/O Function that writes to a file given by filename[]
//                 it formats the record given by main to be put into a text file
//
//  Parameters:    accarray ( struct record [] ) : Starting point of the record given
//                               by the main
//                 numcust ( int ) : the number of records that will be written into the file
//                 filename ( char [ ] ) : the name of the textfile that is being written to
//  Return values:  0 : Success
//                 -1 : File could not be created
//
****************************************************************/
int writefile( struct record accarray[ ], int numcust, char filename[ ] )
{
    FILE *fp;
    int i;

    fp = fopen(filename, "w");
    for(i = 0; i<numcust; i++)
    {
        fprintf(fp, "%d\n", accarray[i].accountno);
        fputc(10, fp);
        fputs(accarray[i].name, fp);
        fputc(10, fp);
        fputs(accarray[i].address, fp);
        fputc(10, fp);
    }
    fclose(fp);
    return 0;
}
