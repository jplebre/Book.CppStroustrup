//
//  main.cpp
//  very simple calculator
//
//  Created by João Pedro Lebre on 01/05/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//

#include "../../../std_lib_facilities.h"

int main()
{
    cout << "Hello! Welcome to your calculator! \nPlease input two numbers followed by the operator +, -, / or *: \n";
    double valueA = 0.0;
    double valueB = 0.0;
    char calculatorOperator = ' ';
    
    while ( cin >> valueA >> valueB >> calculatorOperator)
    {
        switch (calculatorOperator)
        {
            case '+':
                cout << "The sum of " << valueA << " and " << valueB << " is " << valueA+valueB << '\n';
                break;
            case '-':
                cout << "The difference of " << valueA << " and " << valueB << " is " << valueA-valueB << '\n';
                break;
            case '/':
                cout << "The division of " << valueA << " and " << valueB << " is " << valueA/valueB << '\n';
                break;
            case '*':
                cout << "The multiplication of " << valueA << " and " << valueB << " is " << valueA*valueB << '\n';
                break;
            default:
                break;
        }
    }
}

