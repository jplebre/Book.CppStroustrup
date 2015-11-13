//
//  main.cpp
//  stroustrup_ch4_drill
//
//  Created by João Pedro Lebre on 11/03/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//

#include "../../../std_lib_facilities.h"

void print(double smallest, double largest, double number_values, double lengths_sum )
{
    cout << "The smallest value is: " << smallest << '\n'
    << "The largest value is: " << largest << '\n'
    << "This is the " << number_values << " entered" << '\n'
    << "The sum of all the lengths is: " << lengths_sum << '\n';
}


int main()
{
    //Commented out because this applies for question 1-5
    /*cout<<"Please enter 2 numbers. Enter | to exit:\n";
    
    double value1 = 0;
    double value2 = 0;
    
    double smaller = 0;
    double larger = 0;
    
    while (cin >> value1 >> value2)
    {
        if (value1 > value2)
        {
            smaller = value2;
            larger = value1;
            cout << "The Smaller Value is: " << smaller << '\n' << "The Larger Value is: " << larger <<'\n';
        }
        else if (value1 < value2)
        {
            smaller = value1;
            larger = value2;
            cout << "The Smaller Value is: " << larger << '\n' << "The Larger Value is: " << smaller <<'\n';
        }
        else
            cout << "The numbers are equal\n";
    
        if (larger - smaller < 0.01)
            cout << "The numbers are almost equal\n";
    }*/
    
    //Commented out because this applies for question 6 only
    /*double temp = 0;
    double smallest = 0;
    double largest = 0;
    
    while (cin >> temp)
    {
        if (temp < smallest || smallest == 0)
            smallest = temp;
        if (temp > largest)
            largest = temp;
        
        cout << "Smallest so far: " << smallest << '\n' << "Largest so far: " << largest << '\n';
    }*/
    
    cout << "Please enter a length, followed by it unit:\n";
    
    double value1 = 0;
    string units = " ";
    double smallest = 0;
    double largest = 0;
    double lengths_sum = 0;
    double number_values = 0;
    vector<double>values_entered;
    
    while (cin >> value1 >> units)
    {
        double cm_into_m = 100;
        double in_into_cm = 2.54;
        double ft_into_cm = (12*2.54);
        
        
        if (units == "m")
        {
            ++number_values;
            lengths_sum += value1;
            
        }
        else if (units == "in")
        {
            ++number_values;
            value1 = (value1*in_into_cm)/cm_into_m;
            lengths_sum += value1;
        }
        else if (units == "cm")
        {
            ++number_values;
            value1 = value1/cm_into_m;
            lengths_sum += value1;
        }
        else if (units == "ft")
        {
            ++number_values;
            value1 = (value1*ft_into_cm)/cm_into_m;
            lengths_sum += value1;
        }
        else
            cout << "I do not recognise this value\n";
        
        
        if (value1 < smallest || smallest == 0)
            smallest = value1;
        if (value1 > largest)
            largest = value1;

        print(smallest, largest, number_values, lengths_sum);
        values_entered.push_back(value1);
        sort(values_entered.begin(), values_entered.end());
        
        for (int i = 0; i < values_entered.size(); ++i )
            cout << "All the values entered: " << values_entered[i] << '\n';
        
        
    }

}

