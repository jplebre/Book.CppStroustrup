//
//  main.cpp
//  ordering numbers and strings
//
//  Created by João Pedro Lebre on 27/02/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//
//  organises input numbers and strings


#include "../../../std_lib_facilities.h"

int main()
{
    cout << "Please insert up to 3 numbers separated by spaces:\n";
    double val1;
    double val2;
    double val3;
    cin >> val1 >> val2 >> val3;
    if (val1 < val2 && val1 < val3)
    {
        cout << val1 << '\n';
        if (val2 < val3)
            cout << val2 << '\n' << val3 << '\n';
        else
            cout << val3 << '\n' << val2 << '\n';
    }
    if (val2 < val1 && val2 < val3)
    {
        cout << val2 << '\n';
        if (val1 < val3)
            cout << val1 << '\n' << val3 << '\n';
        else
            cout << val3 << '\n' << val1 << '\n';
    }
    else
    {
        cout << val3 << '\n';
        if (val1 < val2)
            cout << val1 << '\n' << val2 << '\n';
        else
            cout << val2 << '\n' << val1 << '\n';
    }
    //cout << val1 << '\n' << val2 << '\n' << val3 << '\n';
    
}

