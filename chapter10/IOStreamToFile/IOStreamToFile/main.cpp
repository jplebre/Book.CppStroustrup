//
//  main.cpp
//  input_output_stream_file_example
//
//  Created by João Pedro Lebre on 22/07/2014.
//  Copyright (c) 2014 jplebre. All rights reserved.
//

#include "../../../std_lib_facilities.h"


struct Readings
{
    int hour;
    double temperature;
    Readings(int h, double t): hour(h), temperature(t){}
};


int main()
{
    cout<< "Please Input name of file to open: \n";
    string name;
    cin>>name;
    ifstream fileIStream(name.c_str());
    if(!fileIStream)
        error("Cannot open file " + name);
    
    cout << "Please enter name of file to write to: \n";
    cin>>name;
    ofstream fileOStream(name.c_str());
    if(!fileOStream)
        error("cannot open destination file" + name);
    
    vector<Readings>temperatures;
    int hour;
    double temperature;
    while (fileIStream>>hour>>temperature)
    {
        if(hour<0 || 23<hour)
            error("Hour is out of range");
        temperatures.push_back(Readings(hour,temperature));
    }
    
    for (int i = 0; i<temperatures.size(); ++i)
    {
        fileOStream << '(' << temperatures[i].hour << ',' << temperatures[i].temperature << ")\n";
    }
}

