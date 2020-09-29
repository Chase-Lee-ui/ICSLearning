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
//  FILE:        user-interface.cpp
//
//  DESCRIPTION:
//   This file contains the code for a user-interface for a database
//   it takes in input from the user then it will run functions defined
//   in this file and in the llist.cpp file.
//
****************************************************************/

#ifndef header
    #include <iostream>
    #include <cstring>
    #include "llist.h"
    using namespace std;

    void printmenu();
    void getAddress(char [], int);
    void getName(char [], int);
    void getNumber(int *);
#endif

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   A main function that runs the user-interface of
//                 a database program and takes in input to run functions
//
//  Parameters:    argc (int) : contains the number of arguments
//                 argv (char**) : contains the name of the argument
//
//  Return values:  0 : success
//
****************************************************************/

int main(int argc, char* argv[])
{
    llist list;
    char name[25];
    char address[80];
    int account_number = 0;
    int verify;
    llist newl(list);
    llist newl2 = newl;

    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: int main(int argc, char* argv[])\n";
        cout << "int argc: " << argc << "char* argv[]\n";
        cout << "This is the main function for the user to do input based on instruction\n";
        cout << "*********************************************************\n\n";
    #endif


    cout << "Hello, welcome to my Bank Database Application\n";
    do
    {
        printmenu();
        cin >> verify;
        if(cin.fail() || verify < 0 || verify > 6)
        {
            cout << "Invalid input, please type in a positive integer: ";
            cin.clear();
            cin.ignore(1000, '\n');
            verify = -1;
        }

        switch(verify)
        {
            case 0:
                cout << "Exiting Program....\n";
                break;
            case 1:
                getNumber(&account_number);
                getName(name, 25);
                getAddress(address, 80);
                list.addRecord(account_number, name, address);
                break;
            case 2:
                getNumber(&account_number);
                list.printRecord(account_number);
                break;
            case 3:
                cout << list;
                break;
            case 4:
                getNumber(&account_number);
                getAddress(address, 80);
                list.modifyRecord(account_number, address);
                break;
            case 5:
                getNumber(&account_number);
                list.deleteRecord(account_number);
                break;
            case 6:
                list.reverse();
                break;
            default:
                break;
        }
    }while(verify != 0);

    return 0;
}

/*****************************************************************
//
//  Function name: printmenu
//
//  DESCRIPTION:   A userinterface function that displays the options to the user
//
//  Parameters:    n/a
//
//  Return values:  n/a
//
****************************************************************/

void printmenu()
{

    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: void printmenu()\n";
        cout << "No paramters passed to this function\n";
        cout << "This function is the user-interface of the program\n";
        cout << "*********************************************************\n\n";
    #endif

    cout << "Please type a number that corresponds with your choice.\n";
    cout << "1: Add Record\n";
    cout << "2: Print Record\n";
    cout << "3: Print All Records\n";
    cout << "4: Modify Record Address\n";
    cout << "5: Delete a Record\n";
    cout << "6: Reverse\n";
    cout << "0: Exit Program\n";
}

/*****************************************************************
//
//  Function name: getAddress
//
//  DESCRIPTION:   A function to take in an address from a user to be run
//                 in database functions
//
//  Parameters:    add (char *) : The address of the record
//                 arraynum (int) : The size of the array
//
//  Return values:  n/a
//
****************************************************************/

void getAddress(char add[], int arraynum)
{
    int error, i;

    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: void getAddress(char add[], int arraynum)\n";
        cout << "char add[]: " << add << "int arraynum: " << arraynum << "\n";
        cout << "This function gets the address from the user\n";
        cout << "*********************************************************\n\n";
    #endif

    do
    {
        error = 0;
        cout << "Please type in the account address\n";
        cout << "Press the enter key twice once you're done\n";
        cin.ignore();
        for(i = 0; i<arraynum; i++)
        {
            add[i] = cin.get();
            if(add[i] == '\n' && add[i-1] == '\n')
            {
                add[i] = '\0';
                add[i-1] = '\0';
                i = arraynum;
            }
        }
        
        
        if(add[0] == '\0' || add[0] == '\n')
        {
            cout << "No leading white spaces or empty addresses\n";
            error = -1;
        }
    }while(error != 0);
}

/*****************************************************************
//
//  Function name: getName
//
//  DESCRIPTION:   A function that takes in the name of an account
//
//  Parameters:    name (char *) : The name of the account
//                 arraynum (int) : The size of the array
//
//  Return values:  n/a
//
****************************************************************/

void getName(char name[], int arraynum)
{
    int error;
    int i;

    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: void getName(char name[], int arraynum)\n";
        cout << "char name[]: " << name << "int arraynum: " << arraynum << "\n";
        cout << "This function gets the address from the user\n";
        cout << "*********************************************************\n\n";
    #endif
    
    do
    {
        error = 0;
        cin.ignore();
        cout << "Please type in the name of the account: ";
        cin.get(name, arraynum);
        for(i = 0; i<arraynum; i++)
        {
            if(name[i] == '\0')
            {
                i = arraynum;
            }
            else if(isalpha(name[i]) == 0 && name[i] != '.' && name[i] != ' ')
            {
                cout << "No special characters are allowed\n";
                error = -1;
                i = arraynum;
            }
        }

        if(name[0] == '\0' || name[0] == ' ')
        {
            cout << "No empty fields or leading white spaces\n";
            error = -1;
        }
    }while(error != 0);
}

/*****************************************************************
//
//  Function name: getNumber
//
//  DESCRIPTION:   A function that takes in the account number of an account
//
//  Parameters:    num (int *) : The pointer to the int variable in main for 
//
//  Return values:  n/a
//
****************************************************************/

void getNumber(int * num)
{
    int user_num;

    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: void getNumber(int * num)\n";
        cout << "int * num\n";
        cout << "This function gets the address from the user\n";
        cout << "*********************************************************\n\n";
    #endif

    do
    {
        cout << "Please type in the account number: ";
        cin >> user_num;
        if(cin.fail() || user_num <= 0)
        {
            cout << "Invalid input, please type in a positive integer: ";
            cin.ignore();
            cin.ignore(1000, '\n');
        }
    }while(!cin || user_num <= 0);

    (*num) = user_num;
}
