
/*****************************************************************
//
//  NAME:        Chase Lee
//
//  HOMEWORK:    5
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        March 3, 2020
//
//  FILE:        driver.c
//
//  DESCRIPTION:
//   This file is the driver for functions found in iofunctions.c and iofunctions.h
//   this tests whether the I/O read/write functions work, doing test cases displaying
//   that the functions do work.
****************************************************************/
#include <stdio.h>
#include <string.h>
#include "iofunctions.h"

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Displays the test cases for running the iofunctions.c
//                 file commands readfile and writefile
//
//  Parameters:    argc ( int ) : the amount of arguments passed, generally unused in the driver
//                 argv ( char * ) : the argument in string form
//
//  Return values:  0 : success
//
****************************************************************/

int main(int argc, char* argv[])
{
    struct record bankone[5];
    int newacctno = 123;
    char nam[10] = "cha";
    char addres[80] = "add";
    int numcustomers;
    int i;

    printf("**************************************************************************\n");
    printf("Case 0: File does not exist; Using readfile to find a file that does not exist\n");
    if(readfile(bankone, &numcustomers, "/tmp/doesntexist.txt") == -1)
    {
    printf("Called readfile to find doesntexist.txt file, but it does not exist\n");
    }
    else
    {
    printf("Exists\n");
    }
    printf("**************************************************************************\n");
    printf("Case 1: Nothing stored in bankone but calls the I/O Functions\n");
    writefile(bankone, numcustomers, "/tmp/case1.txt");
    readfile(bankone, &numcustomers, "/tmp/case1.txt");
    printf("**************************************************************************\n");

    numcustomers = 1;
    printf("Case 2: Filling in one account with 123, 'nami' and 'kalihi' in the respective fields\n");
    bankone[0].accountno = newacctno;
    strcpy(bankone[0].name, "nami");
    strcpy(bankone[0].address, "kalihi");
    writefile(bankone, numcustomers, "/tmp/case2.txt");

    printf("Filling the first record with 0, 'no', and 'none'\n");
    bankone[0].accountno = 0;
    strcpy(bankone[0].name, "no");
    strcpy(bankone[0].address, "none");
    
    printf("Reading the file\n");
    readfile(bankone, &numcustomers, "/tmp/case2.txt");
    printf("Account 1 Account Number: %d\n", bankone[0].accountno);
    printf("Account 1 Name: %s\n", bankone[0].name);
    printf("Account 1 Address: %s\n", bankone[0].address);
    printf("**************************************************************************\n");

    numcustomers = 5;
    printf("Case 3: Fully filling the records.\n");
    printf("Storing 123, cha, and add to the respective fields\n");
    printf("After every loop, 'newacctno' is increased, 'nam' gains an a and 'addres' gains a d\n");
    for(i = 0; i<numcustomers; i++)
    {
        bankone[i].accountno = newacctno;
        strcpy(bankone[i].name, nam);
        strcpy(bankone[i].address, addres);

        newacctno++;
        nam[3+i] = 'a';
        addres[3+i] = 'd';
    }

    printf("Writing the data stored in bankone into a temporary file called hw4.txt\n");
    writefile(bankone, numcustomers, "/tmp/hw4.txt");

    printf("Clearing the currently stored fields by making all account numbers 0, bankone name and address to a and b\n");
    for(i = 0; i<numcustomers; i++)
    {
        bankone[i].accountno = 0;
        strcpy(bankone[i].name, "a");
        strcpy(bankone[i].address, "b");
    }

    printf("Reading the temporary file called hw4.txt\n");
    readfile(bankone, &numcustomers, "/tmp/hw4.txt");
    printf("_________________________________________________________________________\n");
    for(i = 0; i<numcustomers; i++)
    {
        printf("Account %d Account Number: %d\n", i+1, bankone[i].accountno);
        printf("Account %d Name: %s\n", i+1, bankone[i].name);
        printf("Account %d Address: %s\n", i+1, bankone[i].address);
        printf("_________________________________________________________________________\n");
    }
    printf("**************************************************************************\n");

    return 0;
}
