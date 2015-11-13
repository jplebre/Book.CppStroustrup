//
//  main.cpp
//  exercises with operators
//
//  Created by João Pedro Lebre on 22/02/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//

#include "../../../std_lib_facilities.h"

int main()
{
    cout << "Please enter a floating-point value:";
    double n;
    cin >> n;
    cout << "n == " << n
        << "\nn+1 == " << n+1
        << "\nThree times n == " << n*3
        << "\nTwice n == " << n+n
        << "\nn squared == " << n*n
        << "\nHalf of n == " <<n/2
        << "\nsquare root of n == " << sqrt(n)
    <<endl; //another name for newline ("end of line")
    
}

