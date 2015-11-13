//
//  main.cpp
//  Chapter: Drill
//
//  Created by João Pedro Lebre on 05/03/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//

#include "../../../std_lib_facilities.h"

int main()
{
    cout << "Please enter numbers. To compute enter ','\n";
    double temp_1 = 0;
    vector<double>temp_list;
    while (cin >> temp_1)
        temp_list.push_back(temp_1);
    sort(temp_list.begin(), temp_list.end());
    if (temp_list[0] == temp_list[1])
        cout << "The numbers are equal" << '\n';
    else
        cout << "The Smaller value is: " << temp_list[0] << '\n' << "The Larger Value is: " << temp_list[1] << '\n';
        
}

