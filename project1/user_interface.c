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
//  FILE:        user_interface.c
//
//  DESCRIPTION:
//   This file contains the entire user interface for the banking
//   account database. This source file takes methods from database.c
//   so that it can be called in the options of the user interface.
//   Methods that ask for the user's address, name, and account number
//   are made in this program. A custom method that prints out the menu
//   of the user interface is also made here. Debug mode is also made
//   in this file which allows the programmer to identify what methods
//   are being called and their parameters.
//
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "database.h"

/*****************************************************************
//
//  Function name: printMenu
//
//  DESCRIPTION:   A userinterface function
//                 Shows the user their function on the user interface
//
//  Parameters:    n/a
//
//  Return values:  n/a
//
****************************************************************/
void printMenu();

/*****************************************************************
//
//  Function name: getAddress
//
//  DESCRIPTION:   Takes in input from the user
//                 This function sends the user's mailing address back to main
//
//  Parameters:    char add[], int arraynum; passed parameters is an empty
//                             char array and the amount of characters in the char array
//
//  Return values:  n/a
//
****************************************************************/
void getAddress (char [ ], int);

/*****************************************************************
//
//  Function name: getName
//
//  DESCRIPTION:   Gets the name of a account holder
//                 This function sends a name back to the main
//
//  Parameters:    char name[], int array num; passed parameters is an empty char array
//                              and the int for the amount of chars in the array
//
//  Return values:  n/a
//
****************************************************************/
void getName(char [ ], int);

/*****************************************************************                                      
//                                                                                                      
//  Function name: getNumber
//                                                                                                      
//  DESCRIPTION:   Gets the account number the user is looking for 
//                 This function sends a number back to main using a pointer
//
//  Parameters:    int * num: points to the memory address of the int in the main
//                               that correlates with account number
//
//  Return values:  n/a
//                                                                                                      
****************************************************************/
void getNumber(int *);
int debugmode;

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   User interface and driver for functions found in database.h and database.c
//                 This displays the choices for a database where the user puts in name, address
//                 and an account number
//
//  Parameters:    argc (int) : contains the number of arguments
//                 argv (char*) : contains the string of the arguments
//
//  Return values:  0 : success
//                 -1 : failure
//
****************************************************************/
int main(int argc, char* argv[])
{
    char name[25];
    char address[80];
    int account_number = 0;
    char user_input[1000];
    int verify, error, i;
    struct record * start = NULL;

    if(argc >= 2)
    {
        if((strcmp(argv[1], "debug")) == 0 && argc == 2)
        {
            debugmode = 1;
        }
        else
        {
            printf("./project ");
            for(i = 1; i<argc; i++)
            {
                    printf("%s ", argv[i]);
            }
            printf(": incorrect file operand\nTry './project debug'\n");
            exit(0);
        }
    }

    readfile(&start, "database.txt");
    do
    {
        printMenu();
        fgets(user_input, sizeof(user_input), stdin);
        error = sscanf(user_input, "%d", &verify);
        if((error == 0) || (error == EOF))
        {
            printf("Invalid choice, must be a number between 0 and 5\n");
            verify = -1;
        }
        
        switch(verify)
        {
            case 0:
                printf("Exiting Program.....\n");
                break;
            case 1:
                getNumber(&account_number);
                getName(name, 25);
                getAddress(address, 80);
                addRecord(&start, account_number, name, address);
                break;
            case 2:
                getNumber(&account_number);
                printRecord(start, account_number);
                break;
            case 3:
                printAllRecords(start);
                break;
            case 4:
                getNumber(&account_number);
                getAddress(address, 80);
                modifyRecord(start, account_number, address);
                break;
            case 5:
                getNumber(&account_number);
                deleteRecord(&start, account_number);
                break;
            default:
                break;
        }

    }while(verify != 0);
    writefile(start, "database.txt");
    cleanup(&start);
    return 0;
}

void printMenu()
{
        if(debugmode == 1)
        {
            printf("***********************DEBUG MODE************************\n");
            printf("Function: void printMenu()\n");
            printf("No parameters passed\n");
            printf("Prints out 6 options for the user to choose from; Adding, Printing,\n");
            printf("Printing All, Modifying, Deleting Records and exiting the program\n");
            printf("*********************************************************\n\n");
        }
        printf("Hello, Welcome to my Bank Database Application\n");
        printf("Please type a number that corresponds with your choice.\n");
        printf("1: Add Record\n");
        printf("2: Print Record\n");
        printf("3: Print All Records\n");        
        printf("4: Modify Record Address\n");
        printf("5: Delete a Record\n");
        printf("0: Exit Program\n");
}

void getAddress(char add[], int arraynum)
{
    int i;
    int error;

    if(debugmode == 1)
    {
        printf("***********************DEBUG MODE************************\n");
        printf("Function: void getAddress\n");
        printf("Parameters: char name[]; int acctno: %d\n", arraynum);
        printf("This program gets the mailing address from the user, the user can type multiple\n");
        printf("lines for their mailing address. In order for it to stop taking in input it asks\n");
        printf("the user to press the enter key twice in order to stop taking in input. Replaces\n");
        printf("the last input with a null character.\n");
        printf("*********************************************************\n\n");
    }
    
    do
    {
        error = 0;
        printf("Please type in the account address\n");
        printf("Press the enter key twice to finish\n");
        for(i = 0; i<arraynum; i++)
        {
            add[i] = fgetc(stdin);
            if(add[i] == '\n' && add[i-1] == '\n')
            {
                add[i] = '\0';
                add[i-1] = '\0';
                i = arraynum;
            }
        }
        if(add[0] == '\0' || add[0] == '\n')
        {
            printf("No leading white spaces or empty addresses\n");
            error = -1;
        }
    }while(error != 0);
}

void getName(char name[], int arraynum)
{
    int error = 0;
    int i;

    if(debugmode == 1)
    {
        printf("***********************DEBUG MODE************************\n");
        printf("Function: void getName\n");
        printf("Parameters: char name[]; int array num: %d;\n", arraynum);
        printf("An empty char array the size of the array is passed to the method. This method \n");
        printf("gets the name from the user so that it can be used in the main and the methods that\n");
        printf("the main uses.\n");
        printf("*********************************************************\n\n");
    }

    do
    {
        error = 0;
        printf("Please type in the name of the account: ");
        for(i = 0; i<arraynum; i++)
        {
            name[i] = fgetc(stdin);
            if(name[i] == '\n')
            {
                name[i] = '\0';
                i = arraynum;
            }
        }

        for(i = 0; i<arraynum; i++)
        {
            if(name[i] == '\0')
            {
                i = arraynum;
            }
            else if(isalpha(name[i]) == 0 && name[i] != '.' && name[i] != ' ')
            {
                printf("No special characters are allowed\n");
                error = -1;
                i = arraynum;
            }
        }
        if(name[0] == '\0' || name[0] == ' ')
        {
            printf("No empty fields or leading white spaces\n");
            error = -1;
        }
    }while(error != 0);
}

void getNumber(int * num)
{
    char user_input[1000];
    int tempnum = -1;
    int error;
    if(debugmode == 1)
    {
        printf("***********************DEBUG MODE************************\n");
        printf("Function: void getNumber\n");
        printf("Parameters: int * num \n");
        printf("The memory address of the account number in the main is passed to this method to\n");
        printf("get the account number of the record from the user to be used in the main and\n");
        printf("the methods it calls.\n");
        printf("*********************************************************\n\n");
    }

    do
    {
        printf("Please type in the account number: ");
        fgets(user_input, sizeof(user_input), stdin);
        error = sscanf(user_input, "%d", &tempnum);

        if(error == 0 || error == EOF)
        {
            printf("Please enter in a number\n");
            tempnum = -1;
        }
        else if(tempnum < 0)
        {
            printf("Account numbers must be a positive number\n");
        }
    }while(tempnum < 0);
    *num = tempnum;
}
