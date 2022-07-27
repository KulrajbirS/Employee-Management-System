#include <iostream>
#include "date.h"
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
    //Data Members
    private:
        string name;
        int age;
        string position;
        Date hired_date;
        double salary_rate;

    //Public Member Functions
    public:
        //Constructors
        Employee (string n, int a, string p, Date h, double s);
        Employee ();
        Employee (const Employee& emp);
        ~Employee ();

        //Accessors
        string getName () const;
        int getAge () const;
        string getPosition () const;
        Date getHiredDate () const;
        double getSalaryRate () const;

        //Mutators
        void setName (string n);
        void setAge (int a);
        void setPosition (string p);
        void setHiredDate (Date h);
        void setSalaryRate (double s);

        //To return complete Employee information
        string getEmployee () const;

        //To return the number of days since the employee was hired
        int getHiredDays () const;

        //To return the number of working days excluding weekends and holidays
        int getWorkingDays () const;

        //To return Salary since Employee was hired
        double getAccumulatedSalary () const;

        //To list all the employees
        static void printAllEmployees (const Employee emp[]);

        //To print name of all Employees
        static void printAllNames (const Employee emp[]);

        //To return Employee with highest Salary
        static Employee getHighSalaryEmp (const Employee emp[]);

        //To return Employee with lowest Salary
        static Employee getLowSalaryEmp (const Employee emp[]);

        //TO find an Employee by name
        static int findEmployeeIndex (string name, const Employee emp[]);
};

#endif