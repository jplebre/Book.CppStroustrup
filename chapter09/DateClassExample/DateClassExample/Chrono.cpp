//
//  main.cpp
//  Date_class_example
//
//  Created by João Pedro Lebre on 23/05/2014.
//  Copyright (c) 2014 João Pedro Lebre. All rights reserved.
//

#include "Chrono.h"


namespace Chrono
{
    //member fucntion definitions:
    Date::Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd)
    {
        if (!is_date(yy,mm,dd)) throw Invalid();
        //constructor assigns arguments into y, m, and d;
        //also checks if date is valid, else it throws error
    }
    
    
    const Date& default_date()
    {
        static Date dd(2001, Date::jan, 1); //default date is start of 21st century
        return dd;
        //because we are using static, dd is only created once
    }
    
    
    Date::Date()
        : y(default_date().year()),
            m(default_date().month()),
            d(default_date().day())
    {
    } //constructor for default date (if no arguments are entered)
    
    void Date::add_day(int n)
    {
        //..
    }
    
    void Date::add_month(int n)
    {
        //..
    }
    
    void Date::add_year(int n)
    {
        if (m==feb && d==29 && !leapyear(y+n)) //leapyear check
        {
            m = mar;
            d = 1;
        }
        
        y += n;
    }
    
    
    
    //helper functions
    bool is_date(int y, Date::Month m, int d)
    {
        //assume that y is valid
        if (d<=0) return false;
        if (m<Date::jan || Date::dec < m) return false;
        
        int days_in_month = 31; //used as default as most months have 31 days
        
        switch (m)
        {
            case Date::feb:
                days_in_month = (leapyear(y)) ? 29 : 28; //for feb, if leapyear use 29, else use 28
                break;
            case Date::apr: case Date::jun: case Date::sep: case Date::nov:
                days_in_month = 30; //all the remaining months have only 30days
                break;
        }
        
        if (days_in_month <d) return false;
        
        return true; //if all checks pass, return true
    }
    
    bool leapyear(int y)
    {
        //exercise 10
    }
    
    bool operator==(const Date& a, const Date& b)
    {
        return a.year() == b.year()
        && a.month() == b.month()
        && a.day() == b.day();
    }
    
    bool operator!=(const Date& a, const Date& b)
    {
        return !(a==b);
    }
    
    
    ostream& operator<<(ostream& os, const Date& d)
    {
        return os << '(' << d.year()
        << ',' << d.month()
        << ',' << d.day() << ')';
    }
    
    istream& operator>>(istream& is, Date& dd)
    {
        int y, m, d;
        char ch1, ch2, ch3, ch4;
        is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
        if (!is) return is;
        if(ch1!='(' || ch2!= ',' || ch3 != ',' || ch4 != ')') //check for format errors
        {
            is.clear(ios_base::failbit);
            return is;
        }
        
        dd = Date(y, Date::Month (m), d); //update Date dd
        
        return is;
    }
    
    enum Day
    {
        sunday, monday, tuesday, wednesday, thursday, friday, saturday
    };
    
    Day day_of_week(const Date& d)
    {
        //...
    }
    
    Date next_sunday(const Date& d)
    {
        //...
    }
    
    Date next_weekday(const Date& d)
    {
        //...
    }
    
}