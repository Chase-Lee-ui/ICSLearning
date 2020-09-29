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
//  FILE:        llist.cpp
//
//  DESCRIPTION:
//   This file contains the function definitions of a linked list for
//   a database program that will be run in user-interface.cpp
//   it holds private and public functions that are in llist.h
//
****************************************************************/

#ifndef header
    #include <iostream>
    #include <fstream>
    #include <cstring>
    #include "llist.h"
    using namespace std;
#endif

/*****************************************************************
//
//  Function name: llist()
//
//  DESCRIPTION:   A constructor function for the class llist
//
//  Parameters:    n/a
//
//  Return values:  n/a
//
****************************************************************/

llist::llist()
{
    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: llist:llist()\n";
        cout << "No actual parameters passed to this function\n";
        cout << "This is a constructor function for the llist class\n";
        cout << "*********************************************************\n\n";
    #endif
    start = NULL;
    strcpy(filename, "database.txt");
    readfile();
}

/*****************************************************************
//
//  Function name: llist(char file*)
//
//  DESCRIPTION:   A constructor function that takes in a filename
//                 that will be read if it exists.
//
//  Parameters:    file (char *) : Name of the file
//
//  Return values:  n/a
//
****************************************************************/

llist::llist(char file[])
{
    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: llist:llist(char file[])\n";
        cout << "char file[] " << file << "\n";
        cout << "This is a constructor function for the llist class\n";
        cout << "*********************************************************\n\n";
    #endif
    strcpy(filename, file);
    readfile();
}

/*****************************************************************
//
//  Function name: llist(const llist& list)
//
//  DESCRIPTION:   A constructor function that takes in another llist
//                 and copy it under this llist under new addresses
//
//  Parameters:    list (const llist& list) : llist being referenced
//
//  Return values:  n/a
//
****************************************************************/

llist::llist(const llist& list)
{
    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: llist:llist(const llist& list)\n";
        cout << "const llist& list\n";
        cout << "This copies the records stored in list into addresses under this class\n";
        cout << "*********************************************************\n\n";
    #endif
    start = list.start;
    strcpy(filename, list.filename);
    writefile();
    start = NULL;
    readfile();
}

/*****************************************************************
//
//  Function name: operator=(const llist& list)
//
//  DESCRIPTION:   Overloads the assignment operator and copies all
//                 the records in list into this class under new
//                 addresses
//
//  Parameters:    list (const llist&) : list being referenced
//
//  Return values:  this : the list that will be copied into the 
//                  new class object
//
****************************************************************/

llist& llist::operator=(const llist& list)
{
    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: llist::operator=(const llist& list)\n";
        cout << "const llist& list\n";
        cout << "This overloads the assignment operator to the records given by list\n";
        cout << "And then puts it in addresses under this class\n";
        cout << "*********************************************************\n\n";
    #endif
    start = list.start;
    strcpy(filename, list.filename);
    writefile();
    start = NULL;
    readfile();
    return *this;
}

/*****************************************************************
//
//  Function name: ~llist()
//
//  DESCRIPTION:   A deconstructor variable that cleans up all the pointers
//                 used in the program and stores them in a file
//
//  Parameters:    n/a
//
//  Return values:  n/a
//
****************************************************************/

llist::~llist()
{
    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: llist:~llist()\n";
        cout << "No actual parameters passed to this function\n";
        printf("This is a constructor function for the llist class\n");
        printf("*********************************************************\n\n");
    #endif

    writefile();
    cleanup();
}

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   A function th
//
//  Parameters:    count (int) : contains the number of arguments
//                               which will be processed
//
//  Return values:  0 : success
//                 -1 : the value was not found
//
****************************************************************/

int llist::addRecord(int uaccountno, char uname[], char uaddress[])
{
    int endresult = -1;
    struct record * temp = start;
    struct record * newrec = new record();

    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: int llist::addRecord(int uaccountno, char uname[], char uaddress[])\n";
        cout << "int uaccountno: " << uaccountno << "; char uname[ ]: " << uname << "; char uaddress[ ]: " << uaddress << ";\n";
        cout << "This function adds a record to the linked list in the program\n";
        cout << "*********************************************************\n\n";
    #endif

    if(start == NULL)
    {
        start = newrec;
        (*newrec).accountno = uaccountno;
        strcpy((*newrec).name, uname);
        strcpy((*newrec).address, uaddress);
        (*newrec).next = NULL;
        endresult = 0;
    }
    else
    {
        while((*temp).next != NULL)
        {
            temp = (*temp).next;
        }
        (*temp).next = newrec;
        (*newrec).accountno = uaccountno;
        strcpy((*newrec).name, uname);
        strcpy((*newrec).address, uaddress);
        (*newrec).next = NULL;
        endresult = 0;
    }
    return endresult;
}

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
//                  -1 : Record was not found
//
****************************************************************/

int llist::printRecord(int uaccountno)
{
    int returnval = -1;
    struct record * temp = start;

    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: int llist::printRecord(int uaccountno)\n";
        cout << "int acctno: " << uaccountno << "\n";
        cout << "This function prints out all records containing the given accountno\n";
        cout << "*********************************************************\n\n";
    #endif

    while(temp != NULL)
    {
        if((*temp).accountno == uaccountno)
        {
            cout << "Account: " << (*temp).accountno << "\n";
            cout << "Name: " << (*temp).name << "\n";
            cout << "Address: " << (*temp).address << "\n";
            returnval = 0;
        }
        temp = (*temp).next;
    }

    if(returnval == -1)
    {
        cout << "No account found\n";
    }
    return returnval;
}

/*****************************************************************
//
//  Function name: operator<<
//
//  DESCRIPTION:   A function that will display all records in the
//                 database that will be filled in the future
//
//  Parameters:    os (std::ostream&) : ostream variable for cout
//                 list (const llist&) : a constant class llist
//
//  Return values:  os : formatted cout printing account no., name, and address
//
****************************************************************/

std::ostream& operator<<(std::ostream& os, const llist& list)
{
    struct record * next = list.start;

    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: operator<<(std::ostream& os, const llist& list)\n";
        cout << "std::ostream& os, const llist& list\n";
        cout << "This function overloads the << operator to print out all records in the linhked list\n";
        cout << "*********************************************************\n\n";
    #endif

    while(next != NULL)
    {
         os << "Account Number: " << (*next).accountno << "\n" << "Name: " << (*next).name << "\n" << "Address: " << (*next).address << "\n";
         next = (*next).next;
    }

    return os;
}

/*****************************************************************
//
//  Function name: modifyRecord
//
//  DESCRIPTION:   A function that would modify a record in the
//                 database but is currently a stub
//
//  Parameters:    uaccount (int) : User inputted account number
//                 uaddress (char *) : Address of the account given by user
//
//  Return values:  0 : success
//                  -1 : Record was not found
//
****************************************************************/

int llist::modifyRecord(int uaccountno, char uaddress[])
{
    int returnval = -1;
    struct record * temp = start;
    
    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: int llist::modifyRecord(int uaccountno, char uaddress[])\n";
        cout << "int acctno: " << uaccountno << "; char uaddress[]: " << uaddress << "\n";
        cout << "This function modifies the address of all records holding the given account number\n";
        cout << "and replaces it with the given address\n";
        cout << "*********************************************************\n\n";
    #endif

    while(temp != NULL)
    {
        if(uaccountno == (*temp).accountno)
        {
            strcpy((*temp).address, uaddress);
            returnval = 0;
        }
        temp = (*temp).next;
    }
    
    if(returnval == -1)
    {
        cout << "No account found to modify\n";
    }

    return returnval;
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   This function would delete the record from a database
//                 but this is currently a stub with a debugger for now
//
//  Parameters:    uaccount (int) : The account number
//
//  Return values:  0 : success
//                  -1 : Record not found
//
****************************************************************/

int llist::deleteRecord(int uaccountno)
{
    int returnval = -1;
    struct record * temp;
    struct record * erase;

    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: int llist::deleteRecord(int uaccountno)\n";
        cout << "int acctno: " << uaccountno << "\n";
        cout << "This function prints out all records containing the given accountno\n";
        cout << "*********************************************************\n\n";
    #endif

    while((*start).accountno == uaccountno)
    {
        erase = start;
        start = (*start).next;
        (*erase).next = NULL;
        delete(erase);
        returnval = 0;
    }

    temp = start;
    while((*temp).next != NULL)
    {
        erase = (*temp).next;
        if((*erase).accountno == uaccountno)
        {
            (*temp).next = (*erase).next;
            (*erase).next = NULL;
            delete(erase);
            returnval = 0;
        }
        else
        {
            temp = (*temp).next;
        }
    }
    
    if(returnval == -1)
    {
        cout << "No record found to delete\n";
    }
    return returnval;
}

/*****************************************************************
//
//  Function name: reverse()
//
//  DESCRIPTION:   Reverses the linked list that is in the current program
//
//  Parameters:    n/a
//
//  Return values:  n/a
//
****************************************************************/

void llist::reverse()
{
    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: void llist::reverse()\n";
        cout << "No parameters passed to this function\n";
        cout << "This is the public function to reverse the linkedlist of records\n";
        cout << "*********************************************************\n\n";
    #endif
    reverse(start);
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   Reads from a file for the database, will fill a linked
//                 list in the program with records if there are any
//
//  Parameters:    n/a
//
//  Return values:  0 : success
//                 -1 : Failed to read file
//
****************************************************************/

int llist::readfile()
{
    int accountno;
    char name[1000];
    char add[1000];
    ifstream fp;
    char c = '\0';
    int i;

    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: int llist::readfile()\n";
        cout << "No paramters passed to this function\n";
        cout << "This function reads a file named privately in the classes\n";
        cout << "*********************************************************\n\n";
    #endif

    fp.open(filename, ios::in);
    
    c = fp.get();
    while(c != EOF)
    {
        fp >> accountno;
        c = fp.get();
        for(i = 0; i<1000; i++)
        {
            name[i] = fp.get();
            if(name[i] == '\n')
            {
                name[i] = '\0';
                i = 1000;
            }
        }
        for(i = 0; i<1000; i++)
        {
            add[i] = fp.get();
            if(add[i] == '\n' && add[i-1] == '\n')
            {
                add[i] = '\0';
                add[i-1] = '\0';
                i = 1000;
            }
        }
        addRecord(accountno, name, add);
        c = fp.get();
    }

    fp.close();

    return 0;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   Writes the linked list of records in the current program
//                 to the name of the file that is passed to the function
//
//  Parameters:    n/a
//
//  Return values:  0 : success
//                 -1 : could not write to the given file
//
****************************************************************/

int llist::writefile()
{
    struct record * temp = start;
    int accountno;
    char name[3000];
    char add[3000];
    ofstream fp;

    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: int llist::writefile()\n";
        cout << "No paramters passed to this function\n";
        cout << "This function writes to a file named privately in the classes\n";
        cout << "*********************************************************\n\n";
    #endif

    fp.open(filename, ios::out);

    while(temp != NULL)
    {
        fp << "\n";
        accountno = (*temp).accountno;
        fp << accountno << endl;
        strcpy(name, (*temp).name);
        fp << name << endl;
        strcpy(add, (*temp).address);
        fp << add << endl;
        fp << "\n";
        temp = (*temp).next;
    }
    fp.close();
    return 0;
}

record * llist::reverse(record * starter)
{
    struct record * hold;

    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: int llist::reverse(record * starter)\n";
        cout << "record * starter\n";
        cout << "This is a function called recursivly to reverse the order of the linked list\n";
        cout << "*********************************************************\n\n";
    #endif

    if((*starter).next == NULL)
    {
        start = starter;
    }
    else
    {
        hold = reverse((*starter).next);
        (*hold).next = starter;
        (*starter).next = NULL;
    }

    return starter;
}

/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   Removes the linked list of records in the program
//                 before the program ends
//
//  Parameters:    n/a
//
//  Return values: n/a
//
****************************************************************/

void llist::cleanup() 
{
    #ifdef debug
        cout << "***********************DEBUG MODE************************\n";
        cout << "Function: int llist::cleanup()\n";
        cout << "No paramters passed to this function\n";
        cout << "This function cleans up the pointers used in the program\n";
        cout << "*********************************************************\n\n";
    #endif

    struct record * erase = NULL;

    while(start != NULL)
    {
        erase = start;
        start = (*start).next;
        (*erase).next = NULL;
        delete erase;
    }

}
