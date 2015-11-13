//
//  main.cpp
//  arithmetic exercise
//
//  Created by João Pedro Lebre on 27/02/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//

#include "../../../std_lib_facilities.h"

int main()
{
    cout<< "Please Enter 2 values:\n";
    double val1 = 0;
    double val2 = 0;
    cin>> val1;
    cin>> val2;
    if (val1 < val2)
        cout << "Largest " << val2 << '\n' << "Smallest " << val1 << '\n';
    else
        cout << "Largest " << val1 << '\n' << "Smallest " << val2 << '\n';
    cout << "Sum " << val1+val2 << '\n';
    cout << "Difference " << val1-val2 << '\n';
    cout << "Product " << val1*val2 << '\n';
    cout << "Ratio " << val1/val2 << '\n';
}

