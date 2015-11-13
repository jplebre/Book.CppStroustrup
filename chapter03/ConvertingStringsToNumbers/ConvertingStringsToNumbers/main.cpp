//
//  main.cpp
//  converting strings into numbers
//
//  Created by João Pedro Lebre on 27/02/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//

#include "../../../std_lib_facilities.h"

int main()
{
    cout << "Please enter a number as a word:\n";
    string to_check = " ";
    int a = 0;
    int b = 1;
    int c = 2;
    cin >> to_check;
    if (to_check == "zero" || to_check == "one" || to_check == "two")
    {
        if (to_check == "zero")
            cout<< a << '\n';
        if (to_check == "one")
            cout << b << '\n';
        if (to_check == "two")
            cout << c << '\n';
    }
    else
        cout << "Not a number I know!\n";
    
        
    
}

