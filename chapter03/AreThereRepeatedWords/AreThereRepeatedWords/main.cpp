//
//  main.cpp
//  are there repeated words?
//
//  Created by João Pedro Lebre on 26/02/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//
// Crude program that sees if there are any consecutive repeated words.
//

#include "../../../std_lib_facilities.h"

int main()
{
    cout << "Please type in a phrase, followed by 'Enter':\n";
    int word_position_number = 0;
    string previous_word = " ";
    string current_word;
    while (cin>>current_word) //while it can execute cin>>current_word, it will keep going through each word in ip string
    {
        ++word_position_number;
        if (previous_word == current_word)
        {
            cout << "word in position " << word_position_number << " repeated: " << current_word <<'\n';
        }
        previous_word = current_word;
    }
}
