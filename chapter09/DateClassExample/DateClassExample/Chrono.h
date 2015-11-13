//
//  Chrono.h
//  Date_class_example
//
//  Created by João Pedro Lebre on 23/05/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//


namespace Chrono
{
    class Date
    {
    public:
        enum Month
        {
            jan = 1,
            feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec,
        };
        
        class Invalid {}; //to throw as exception
        
        Date(int y, Month m, int d); //check for valid date and initialize
        Date();
        //we are not adding anything else because the default copy operations are fine
        //how to make default copy instructions will be covered in later chapters
        //how to make the copy constructor private will be covered in later chapters
        
        //non-modifying operations
        int day() const { return d; }
        Month month() const { return m; }
        int year() const { return y; }
        
        //modifying operations
        void add_day(int n);
        void add_month(int n);
        void add_year(int n);
        
    private:
        int y;
        Month m;
        int d;
    };
    
    
    bool is_date(int y, Date::Month m, int d); //returns true for valid dates
    bool leapyear(int y);
    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);
    
    ostream& operator<<(ostream& os, const Date& d);
    istream& operator>>(istream& is, Date& dd);
    
}