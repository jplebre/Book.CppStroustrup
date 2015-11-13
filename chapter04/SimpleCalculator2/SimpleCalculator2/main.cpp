//
//  main.cpp
//  very simple calculator v2
//
//  Created by João Pedro Lebre on 01/05/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//

#include "../../../std_lib_facilities.h"

int main()
{
    cout << "Input any number from 0 to 9:\n";
    
    vector<string>numbers1(10);
    numbers1[0] = "zero";
    numbers1[1] = "one";
    numbers1[2] = "two";
    numbers1[3] = "three";
    numbers1[4] = "four";
    numbers1[5] = "five";
    numbers1[6] = "six";
    numbers1[7] = "seven";
    numbers1[8] = "eight";
    numbers1[9] = "nine";
    
    vector<string>numbers2(10);
    numbers2[0] = "0";
    numbers2[1] = "1";
    numbers2[2] = "2";
    numbers2[3] = "3";
    numbers2[4] = "4";
    numbers2[5] = "5";
    numbers2[6] = "6";
    numbers2[7] = "7";
    numbers2[8] = "8";
    numbers2[9] = "9";
    
    
    string userInput = "";
    
    while (cin >> userInput)
    {        
        for (int i = 0; i< numbers1.size(); i++)
            if (numbers1[i] == userInput)
                cout << numbers1[i];
            else if (numbers2[i] == userInput)
                cout << numbers2[i];
    }
}