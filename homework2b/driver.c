/****************************************************************
//
//    Name:       Chase Lee
//
//    Homework:   2b
//
//    Class:      ICS212
//
//    Instructor: Ravi Narayan
//
//    Date:       February 4, 2020
//
//    File:       driver.c
//
//    Description:
//      Because there is no main function for either halfstring.c
//      or halfstring.h, this is the driver file so that both files
//      can be tested. This program passes arguments to the functions
//      and works out halfstring.c.
//
*****************************************************************/
#include <stdio.h>
#include "halfstring.c"


int main()
{
    char str[1000];
    char new[1000];
    char test1[] = {"John Smith"};
    char result1[1000];
    char test2[] = {"Ravi Narayan"};
    char result2[1000];
    char test3[] = {"Tetsuya Idota"};
    char result3[1000];
    char test4[] = {""};
    char result4[1000];
    char test5[] = {"     345"};
    char result5[1000];

    fgets(str, 1000, stdin);
    halfstring(str, new);

    halfstring(test1, result1);
    halfstring(test2, result2);
    halfstring(test3, result3);
    halfstring(test4, result4);
    halfstring(test5, result5);

    return 0;
}
