//
//  main.cpp
//  drill 1
//
//  Created by João Pedro Lebre on 26/02/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//

#include "../../../std_lib_facilities.h"

int main()
{
    cout<<"Please enter the name of the person you want to write to, followed by 'Enter':\n";
    string first_name;
    cin>> first_name;
    cout<< "Dear " << first_name << ",\n";
    cout<<"Miss you.\n";
    cout<<"Please enter the first name of your cat:\n";
    string cat_name;
    cin>> cat_name;
    cout<<"did you feed " << cat_name << " before you left this morning?\n";
    cout<<"Please input Y for 'Yes' or N for 'N'\n";
    char food = 0;
    cin>> food;
    if (food == 89)
        cout<<"Good, I won't feed him then!\n";
    else (food == 78);
        cout<<"Ok I'll feed him now then!\n";
    cout<<"How old is the cat again?\n";
    cout<<"Please enter cat's age in numbers:\n";
    int cat_age = 0;
    cin>> cat_age;
    if (cat_age<= 0 || cat_age > 100)
        simple_error("You're Kidding!");
    else
        cout<<"I thought he was " << ++cat_age << " !\n";
    cout<<"See you soon x x\n";
    return 0;
}

