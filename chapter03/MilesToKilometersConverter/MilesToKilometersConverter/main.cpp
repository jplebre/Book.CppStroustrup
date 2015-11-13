//
//  main.cpp
//  miles to kilometers converter
//
//  Created by João Pedro Lebre on 27/02/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//
//  Miles to Kilometers converter

#include "../../../std_lib_facilities.h"

int main()
{
    cout<<"Please input the number of miles to convert to kilometers:\n";
    double miles = 0;
    cin>> miles;
    double kilometers = 0;
    kilometers = miles*1.609;
    cout<< kilometers <<'\n';
}

