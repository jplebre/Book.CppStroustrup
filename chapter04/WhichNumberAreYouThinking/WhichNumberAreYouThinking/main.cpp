//
//  main.cpp
//  which number are you thinking
//
//  Created by João Pedro Lebre on 12/03/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//

#include "../../../std_lib_facilities.h"


int main()
{
    cout << "Think of a number between 1 and 100.\n";
    
    int lowerbound = 1;
    int upperbound = 100;
    
    string answer = " ";
    
    //almost working need to terminate the program and to make the division not include number 50
    while (lowerbound != upperbound)
    {
        int middlepoint = (upperbound-lowerbound)/2 + lowerbound;
        cout << "Is the number you are thinking smaller than " << middlepoint << " ?\nEnter Y for Yes, N for No\n";
        cin >> answer;
        if (answer == "Y" || answer == "y")
        {
            cout << "Entered Yes\n";
            upperbound = middlepoint;
        }
        else if (answer == "N" || answer == "n")
        {
            cout << "Entered No\n";
            lowerbound = middlepoint+1;
        }
        else
            cout << "Sorry I don't understand.\nPlease enter Y for Yes, N for No\n";
        
        //cout << lowerbound << middlepoint << upperbound;
    }
    
    cout << "The answer is: " << lowerbound-1 << '\n';
    
}

