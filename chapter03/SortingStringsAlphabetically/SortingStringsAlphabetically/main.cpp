//
//  main.cpp
//  sorting strings alphabetically
//
//  Created by João Pedro Lebre on 23/02/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//

#include "../../../std_lib_facilities.h"

int main()
{
    cout << "Please enter two words:\n";
    string first;
    string second;
    cin >> first >>second;
    if (first == second) cout << "It's the same word twice!!!\n";
    if (first < second)
        cout << first << " is alphabetically before " << second <<'\n';
    if (first > second)
        cout << second << " is alphabetically before " << first <<'\n';
}

