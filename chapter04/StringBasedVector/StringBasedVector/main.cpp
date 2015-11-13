//
//  main.cpp
//  vector - string based vector:simple dictionary
//
//  Created by João Pedro Lebre on 05/03/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//

#include "../../../std_lib_facilities.h"

int main()
{
    cout << "To add to the dictionary, add a list of words or a sentence. To end typing, press CTRL+D\n";
    vector<string>dictionary;     //initializes a vector with no elements
    string temp;
    while (cin>>temp)             //to break this loop, cntrl+d - for UNIX systems - needs to be used.
        dictionary.push_back(temp);
    cout << "Number of words on dictionary: " << dictionary.size() << endl;
    
    sort(dictionary.begin(),dictionary.end()); //sorts words alphabetically through the vector
    
    for (int i=0; i < dictionary.size(); ++i) //this loop runs through all the words on the dictionary, then stops
        if (i == 0 || dictionary[i-1] != dictionary[i]) //unless it's the first word on the dictionary,
                                                        //check if the word is not a duplicate for the previous word
            cout << dictionary[i] << '\n';                 
}

