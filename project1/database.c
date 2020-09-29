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
//  FILE:        database.c
//
//  DESCRIPTION:
//   This file contains the stubs for the database functions. All
//   methods contain a debugger so when debug is called from 
//   command line arguments it is activated and shown.
//
****************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "database.h"
int debugmode;

int addRecord (struct record ** start, int uaccountno, char uname[ ],char uaddress[ ])
{
    int endresult = -1;
    struct record * new = malloc(sizeof(struct record));
    struct record * temp = (*start);
    
    if(debugmode == 1)
    {
        printf("***********************DEBUG MODE************************\n");
        printf("Function: int addRecord\n");
        printf("struct record ** precords; int acctno: %d; char name[ ]: %s; char address[ ]: %s;", uaccountno, uname, uaddress);
        printf("This function is a stub, it will return 0, it also contains a debugmode\n");
        printf("*********************************************************\n\n");
    }
    
    if((*start) == NULL)
    {
        (*start) = new;
        (*new).accountno = uaccountno;
        strcpy((*new).name, uname);
        strcpy((*new).address, uaddress);
        (*new).next = NULL;
        endresult = 0;
    }
    else
    {
        while((*temp).next != NULL)
        {
            temp = (*temp).next;
        }
        (*temp).next = new;
        (*new).accountno = uaccountno;
        strcpy((*new).name, uname);
        strcpy((*new).address, uaddress);
        (*new).next = NULL;
        endresult = 0;
    }
    return endresult;
}

int printRecord (struct record * records, int acctno)
{
    int returnval = -1;
    struct record * temp = records;

    if(debugmode == 1)
    {
        printf("***********************DEBUG MODE************************\n");
        printf("Function: int printRecord\n");
        printf("struct record * records; int acctno: %d;\n", acctno);
        printf("This function is a stub, it will return 0, it also contains a debugmode\n");
        printf("*********************************************************\n\n");
    }

    while(temp != NULL)
    {
        if((*temp).accountno == acctno)
        {
            printf("Account: %d\n", (*temp).accountno);
            printf("Name: %s\n", (*temp).name);
            printf("Address: %s\n", (*temp).address);
            returnval = 0;
        }
        temp = (*temp).next;
    }

    if(returnval == -1)
    {
        printf("No account found\n");
    }
    return returnval;
}

void printAllRecords(struct record * records)
{
    struct record * temp;
    if(debugmode == 1)
    {
        printf("***********************DEBUG MODE************************\n");
        printf("Function: void printAllRecords\n");
        printf("struct record * records\n");
        printf("This function is a stub, it will return 0, it also contains a debugmode\n");
        printf("*********************************************************\n\n");
    }
    temp = records;
    while(temp != NULL)
    {
        printf("Account #%d\n", (*temp).accountno);
        printf("Name: %s\n", (*temp).name);
        printf("Address: %s\n", (*temp).address);
        temp = (*temp).next;
    }
}

int modifyRecord (struct record * records, int uaccountno, char uaddress[ ])
{
    int returnval = -1;
    struct record * temp = records;
    if(debugmode == 1)
    {
        printf("***********************DEBUG MODE************************\n\n");
        printf("Function: int modifyRecord\n");
        printf("struct record * records, int acctno: %d, char address [ ]: %s\n", uaccountno, uaddress);
        printf("This function is a stub, it will return 0, it also contains a debugmode\n");
        printf("*********************************************************\n\n");
    }

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
        printf("No account found to modify\n");
    }
    return returnval;
}

int deleteRecord(struct record ** start, int uaccountno)
{
    int returnval = -1;
    struct record * temp;
    struct record * erase;

    if(debugmode == 1)
    {
        printf("***********************DEBUG MODE************************\n");
        printf("Function: int deleteRecord\n");
        printf("struct record ** start; int uaccountno %d;\n", uaccountno);
        printf("This function is a stub, it will return 0, it also contains a debugmode\n");
        printf("*********************************************************\n\n");
    }
    
    while((**start).accountno == uaccountno && (*start) != NULL)
    {
        erase = (*start);
        (*start) = (**start).next;
        free(erase);
        returnval = 0;
    }

    temp = (*start);
    while((*temp).next != NULL)
    {
        erase = (*temp).next;
        if((*erase).accountno == uaccountno)
        {
            (*temp).next = (*erase).next;
            free(erase);
            returnval = 0;
        }
        else
        {
            temp = (*temp).next;
        }
    }


    if(returnval == -1)
    {
        printf("No record found to delete\n");
    }
    return returnval;
}

int readfile(struct record ** start, char file[])
{
    FILE *fp;
    char c = '\0';
    struct record * rec = (*start);
    char name[1000];
    char address[1000];
    int acctno;
    int rval = 0;
    int i;

    if(debugmode == 1)
    {
        printf("***********************DEBUG MODE************************\n");
        printf("Function: int readfile\n"); 
        printf("struct record ** start; char file[] %s;\n", file);
        printf("This function reads from the file given to it\n");
        printf("*********************************************************\n\n");
    }

    if((fp = fopen(file, "r")))
    {
        c = fgetc(fp);
        while(c != EOF)
        {
            fscanf(fp, "%d", &acctno);
            fgetc(fp);
            for(i = 0; i<sizeof((*rec).name); i++)
            {
                name[i] = fgetc(fp);
                if(name[i] == '\n')
                {
                    name[i] = '\0';
                    i = sizeof((*rec).name);
                }
            }
            for(i = 0; i<sizeof((*rec).address); i++)
            {
                address[i] = fgetc(fp);
                if(address[i] == '\n' && address[i-1] == '\n')
                {
                    address[i] = '\0';
                    address[i-1] = '\0';
                    i = sizeof((*rec).address);
                }
            }
            addRecord(start, acctno, name, address);
            c = fgetc(fp);
        }
        fclose(fp);
    }
    else
    {
        rval = -1;
    }
    return rval;
}

int writefile(struct record * start, char file[])
{
    FILE *fp;
    struct record * rec = start;

    if(debugmode == 1)                                                                                  
    { 
    printf("***********************DEBUG MODE************************\n");                              
    printf("Function: int writefile\n");                                                             
    printf("struct record * start; char file[] %s\n", file);
    printf("This is the writefile that writes to a file the list of linked records\n");   
    printf("*********************************************************\n\n");
    }
    
    fp = fopen(file, "w");
    while(rec != NULL)
    {
        fputc(10, fp);
        fprintf(fp, "%d\n", (*rec).accountno);
        fputs((*rec).name, fp);
        fputc(10, fp);
        fputs((*rec).address, fp);
        fputc(10, fp);
        fputc(10, fp);
        rec = (*rec).next;
    }
    fclose(fp);
    return 0;
}


void cleanup(struct record ** start)
{
    struct record * temp = (*start);
    struct record * erase = NULL;

    if(debugmode == 1)
    {                                                                                                   
    printf("***********************DEBUG MODE************************\n");                              
    printf("Function: void cleanup\n");                                                             
    printf("struct record ** start;\n");
    printf("This cleans up the program of any linked list pointers and addresses\n"); 
    printf("*********************************************************\n\n");
    } 

    while(temp != NULL)
    {
        erase = temp;
        temp = (*temp).next;
        (*erase).next = NULL;
        free(erase);
    }
}

