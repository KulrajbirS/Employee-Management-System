#include <iostream>
using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{
    //Data Members
    private:
        int month;
        int day;
        int year;

    //Public Member Functions
    public:
        //Constructors
        Date (int d, int m, int y);
        Date ();
        Date (const Date& date);
        ~Date ();

        //Accessors
        int getDay () const;
        int getMonth () const;
        int getYear () const;

        //Mutators
        void setDay (int d);
        void setMonth (int m);
        void setYear (int y);

        //To return the Complete Date
        string getDate () const;
};

#endif