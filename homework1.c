/***************************************************************************************************
//
//    NAME:        Chase Lee
//
//    HOMEWORK:    1
//
//    CLASS:       ICS212
//
//    INSTRUCTOR:  Ravi Narayan
//
//    DATE:        January 28, 2020
//
//    FILE:        homework1.c
//
//    DESCRIPTION:
//     This file contains a function that will convert inches to centimeters. The user inputs the
//     maximum centimeters to show on a table that displays columns inches, and centimeters. 
//     Inches will increment by 0.5 and there is user input validation. This file also contains
//     three functions that are not in the stdio.h library. The user_interface that prompts the
//     user, convert that converts inches to centimeters. Lastly there is the print_table that
//     prints out a formatted table of inches and centimeters that the user can see.
//
**************************************************************************************************/

#include <stdio.h>
#include <string.h>

int user_interface();
double convert(double);
void print_table(int);

int main(int argc, char *argv[])
{
    int user;

    user_interface();
    user = -1;
    while(user==-1)
    {
        scanf("%d", &user);
        if(user<=0)
        {
            printf("Error: input is not a positive number\n");
            printf("Please type in a positive integer\n");
            user = -1;
        }
        fflush(stdin);
    }
    

    print_table(user);
    return 0;
}

/******************************************************************************
//
//    Function Name: user_interface 
//
//    Description:   A user_interface that introduces and prompts the user to
//                   put in a number for the maximum amount of centimeters
//
//    Parameters:    n/a void
//
//    Return values: 0 to end function
//
******************************************************************************/

int user_interface()
{
    printf("This program converts inches to centimeters\n");
    printf("Please enter the maximum centimeters that is a positive number to show: ");
    return 0;
}

/*****************************************************************************
//
//    Function name: convert
//
//    Description:   Converts inches to centimeters using a one-line equation
//
//    Parameters:    a (double): Sent from print_table to convert inches to
//                               centimeters.
//
//    Return values: Returns given centimeters to inches
//
*****************************************************************************/
double convert(double a)
{
    a = a*2.54;
    return a;
}

/****************************************************************************
//
//    Function Name: print_table
//
//    Description:   A user interface that shows the user the converted
//                   inches to centimeters and stops at the max that was
//                   given by the user
//
//    Parameters:    b (int) : The user input that was given by the main
//                             so that the CPU knows when to stop putting out
//                             increments of 0.5
//
****************************************************************************/
void print_table(int b)
{
    double interval;
    double inches;

    printf("\tinch\t\tcm\n");
    for(interval = 0; interval <= b; interval = interval + 0.5)
        {
            inches = convert(interval);
            printf("%*.2f", 12,interval);
            printf("%*.2f\n", 14, inches);     
        }
}
