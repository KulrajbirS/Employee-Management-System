//The implementation file date.cpp consisting of Data Member Function Definitions
#include <iostream>

//Including interface file
#include "date.h"
using namespace std;

//Parametric Constructor
Date :: Date (int d, int m, int y)
: day (d), month (m), year(y)
{}

//Default Constructor
Date :: Date ()
: day (1), month (1), year(1900)
{}

//Copy Constructor
Date :: Date (const Date& date)
: day (date.day), month (date.month), year (date.year)
{}

//Destructor
Date :: ~Date ()
{}

//Accessors
int Date :: getDay () const
{
    return day;
}

int Date :: getMonth () const
{
    return month;
}

int Date :: getYear () const
{
    return year;
}

//Mutators
void Date :: setDay (int d)
{
    day = d;
}

void Date :: setMonth (int m)
{
    month = m;
}

void Date :: setYear (int y)
{
    year = y;
}

//To return the Complete Date
string Date :: getDate () const
{
    int m = this->getMonth() - 1;
    string Month[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    string dateString = Month[m] + " " + to_string(this->getDay()) + ", " + to_string(this->getYear());
    
    return dateString;
}