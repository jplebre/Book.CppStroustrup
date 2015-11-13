//
//  main.cpp
//  vector: integer list - temperatures
//
//  Created by João Pedro Lebre on 05/03/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//

#include "../../../std_lib_facilities.h"

int main()
{
    //create a vector and keep adding elements for each double inputed
    cout << "Please enter temperature values. To end, please enter an '.'\n";
    vector<double>temperatures;          //creates vector, data type: floating point no., no elements
    double temp;                         //initializes temp
    while (cin>>temp)                    //everytime there's an input, put that value into temp and execute block
                                         //entering a value that is not a number (temp is a double), forces loop to stop
        temperatures.push_back(temp);    //uses push_back() to put temp in temperatures
    
    //compute mean temperature
    double sum = 0;
    for (int i = 0; i < temperatures.size(); ++i) //initialized loop variable, and while it is smaller than vector length
        sum += temperatures[i];
        cout << "Average temperature: " << sum/temperatures.size() << endl;
    
    //compute media temperature:
    sort(temperatures.begin(), temperatures.end()); //sort(a,b) sorts a range starting on a and ending on b
    cout << "Median temperature: " << temperatures[temperatures.size()/2.0] << endl;
    
}

