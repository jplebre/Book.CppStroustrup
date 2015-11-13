//
//  main.cpp
//  reading and storing variables
//
//  Created by João Pedro Lebre on 22/02/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//

//prompts user to input his name, then outputs greeting

#include "../../../std_lib_facilities.h"

int main()
{
    int function_one();
    {
        cout << "Please enter your first name, followed by 'enter':\n"; //user prompt
        string first_name; //initializes object name (aka variable) first_name, of type string
        cin >> first_name; //reads input chars into first_name
        cout << "Hello " << first_name << "!\n";
    }
    int function_two();
    {
        cout<< "Please enter your first name and age, followed by 'enter':\n";
        string first_name;
        int age;
        cin >> first_name;
        cin >> age;
        cout << "You are " << first_name << ", age: " << age ;
    }
}
    

