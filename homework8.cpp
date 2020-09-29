/*****************************************************************
//
//  NAME:        Chase Lee
//
//  HOMEWORK:    homework8
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        April 4, 2020
//
//  FILE:        homework8.cpp
//
//  DESCRIPTION:
//    This is a c++ file that converts inches to centimeters at
//    every 0.5 interval, the user tells the program the maximum
//    inch and the program displays every 0.5 inch interval to that
//    maximum inch
//
****************************************************************/

#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

void convertc(double, double &);
void print_table(int);
int user_interface();

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   This is the main function that calls methods
//                 for the program's functions.
//
//  Parameters:    argc (int) : contains the number of arguments
//                 argv (char*) : contains the string argument
//
//  Return values:  0 : success
//
****************************************************************/

int main(int argc, char* argv[])
{
    print_table(user_interface());

    return 0;
}

/*****************************************************************
//
//  Function name: user_interface
//
//  DESCRIPTION:   A userinterface function
//                 This orientates the user to the program and recieves input for the program
//
//  Parameters:    n/a
//
//  Return values: user_num : integer value of the maximum integer for the program
//
****************************************************************/

int user_interface()
{
    int user_num;

    cout << "This program converts inches to centimeters\n";
    cout << "Please enter the maximum centimeters that is a positive number to show: ";

    do
    {
        cin >> user_num;
        if(cin.fail() || user_num <= 0)
        {
            cout << "Invalid input, please type in a positive integer: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }while(!cin || user_num <= 0);

    return user_num;
}

/*****************************************************************
//
//  Function name: convertc
//
//  DESCRIPTION:   Converts inches to centimeters
//
//  Parameters:    interval (double) : The interval of 0.5 inch to be converted
//                 rinches (double&) : The reference to the converted
//                                     centimeter value
//
//  Return values:  n/a
//
****************************************************************/

void convertc(double interval, double& rinches)
{
    interval *= 2.54;
    rinches = interval;
}

/*****************************************************************
//
//  Function name: getinput
//
//  DESCRIPTION:   A userinterface function
//                 This function obtains the values of the ... from the user
//
//  Parameters:    max (int) : the max inch to be converted to centimeters
//
//  Return values:  n/a
//
****************************************************************/

void print_table(int max)
{
    double interval;
    double inches;
    double& rinches = inches;

    cout << "\tinch\t\tcm\n";
    for(interval = 0; interval <= max; interval += 0.5)
    {
        convertc(interval, rinches);
        std::cout << std::fixed << std::setprecision(2) << std::right << std::setw(12) << interval << "\t";
        std::cout << std::fixed << std::setprecision(2) << std::right << std::setw(10) << rinches << "\n";
    }
}
