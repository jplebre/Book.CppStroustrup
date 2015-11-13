//
//  main.cpp
//  while loop test 1
//
//  Created by João Pedro Lebre on 01/03/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//
//  This program outputs a list of characters and their ascii values
//  Program (loop) terminates upon reaching letter z

#include "../../../std_lib_facilities.h"

int main()
{
    int i = 97;
    char incremental = 0;
    while (i <= 122)
    {
        incremental = i;
        cout << incremental << '\t' << i << '\n';
        ++i;
    }
}

