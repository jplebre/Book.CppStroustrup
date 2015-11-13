//
//  main.cpp
//  safe and unsafe conversions experiment
//
//  Created by João Pedro Lebre on 26/02/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//
//
//  this program tests safe and unsafe conversions in C++98

#include "../../../std_lib_facilities.h"

int main()
{
    cout<<"to test safe/unsafe conversions, please enter any number followed by 'Enter'";
    double d = 0;
    while (cin>>d)        // as long as we keep inputting numbers
    {
        int i = d;        //try to squeeze a double into int
        char c = i;       //try to squeeze an int into a char
        int i2 = c;       //get the integer value of the char
        cout << "d == " << d                   // the original double
            << " i == " << i                    // converted to int
            << " i2 == " << i2                 // int value of the char
            << " char(" << c << ")\n";         // the char
    }
}

