//The implementation file date.cpp consisting of Data Member Function Definitions
#include <iostream>
#include <ctime>

//Including interface file
#include "employee.h"
using namespace std;

//Parametric Constructor
Employee :: Employee (string n, int a, string p, Date h, double s)
: name (n), age (a), position (p), hired_date (h), salary_rate (s)
{}

//Default Constructor
Employee :: Employee ()
: name (""), age (0), position (""), hired_date (Date ()), salary_rate (0.0)
{}

//Copy Constructor
Employee :: Employee (const Employee& emp)
: name (emp.name), age (emp.age), position (emp.position), hired_date (emp.hired_date), salary_rate (emp.salary_rate)
{}

//Destructor
Employee :: ~Employee ()
{}

//Accessors
string Employee :: getName () const
{
    return name;
}

int Employee :: getAge () const
{
    return age;
}

string Employee :: getPosition () const
{
    return position;
}

Date Employee :: getHiredDate () const
{
    return hired_date;
}

double Employee :: getSalaryRate () const
{
    return salary_rate;
}

//Mutators
void Employee :: setName (string n)
{
    name = n;
}

void Employee :: setAge (int a)
{
    age = a;
}

void Employee :: setPosition (string p)
{
    position = p;
}

void Employee :: setHiredDate (Date h)
{
    hired_date = h;
}

void Employee :: setSalaryRate (double s)
{
    salary_rate = s;
}

//To return complete Employee information
string Employee :: getEmployee () const
{
    string emp = "Name: " + name +
                 "\nAge: " + to_string(age) +
                 "\nPosition: " + position +
                 "\nHired Date: " + hired_date.getDate() +
                 "\nSalary Rate: $" + to_string(salary_rate) + "/hour" +
                 "\nDays of hired: " + to_string(this->getHiredDays()) + " days" +
                 "\nDays of working: " + to_string(this->getWorkingDays()) + " days" +
                 "\nAccumulated Salary: $" + to_string(this->getAccumulatedSalary());

    return emp;
}

//To return the number of days since the employee was hired
int Employee :: getHiredDays () const
{
    int y = hired_date.getYear();
    int m = hired_date.getMonth();
    int d = hired_date.getDay();

    time_t current_time = time(0);
    tm* ltm= localtime(&current_time);
    int currentY = 1900 + ltm->tm_year;
    int currentM = 1 + ltm->tm_mon;
    int currentD = ltm->tm_mday;

    int days [] = {31,28,31,30,31,30,31,31,30,31,30,31};

    int total_days = 0;
    total_days += (currentY - y - 1) * 365;

    int Ms = m;
    for(int i = Ms; i < 12; i++)
    {
        total_days += days[i];
    }
    total_days += days[m-1] - d;


    for(int j = 0; j < currentM-1; j++)
    {
        total_days += days[j];
    }
    total_days += currentD;

    int k = currentY;
    if(currentM >= 2)
    {
        k = currentY + 1;
    }
    if(m > 2)
    {
        y += 1;
    }

    int counter = 0;
    for(int l = y; l < k; l++)
    {
        if(l%4 == 0)
        {
            if(l%100 == 0 )
            {
                if(l&400 == 0)
                {
                    counter++;
                }
            }
            else
            {
                counter++;
            }
        }
    }
    //cout << counter << endl;
    total_days += counter;

    return total_days;
}

//To return the number of working days excluding weekends and holidays
int Employee :: getWorkingDays () const
{
    int total_days = this->getHiredDays();
    int weeks = total_days/7;
    int holidays = 0.8 * (total_days/30);

    weeks *= 2;

    total_days -= weeks;
    total_days -= holidays;

    return total_days;
}

//To return Salary since Employee was hired
double Employee :: getAccumulatedSalary () const
{
    double salary = 0;
    int workingDays = this->getWorkingDays();
    int workingHours = workingDays*8;
    salary = workingHours * salary_rate;

    return salary;
}

//To list all the employees
void Employee :: printAllEmployees (const Employee emp[])
{
    int index = 0;
    while(emp [index].getAge() != 0)
    {
        cout << emp[index].getEmployee() << endl << endl;
        index++;
    }
}

//To print name of all Employees
void Employee :: printAllNames (const Employee emp[])
{
    int index = 0;
    cout << "Name of the Employees are: " << endl;
    while(emp [index].getAge() != 0)
    {
        cout << emp[index].getName() << endl;
        index++;
    }
}

//To return Employee with highest Salary
Employee Employee :: getHighSalaryEmp (const Employee emp[])
{
    int index = 1;
    double maxSalary = emp [0].getSalaryRate();
    Employee hEmp = emp [0];
    while(emp [index].getAge() != 0)
    {
        if(emp [index].getSalaryRate() > maxSalary)
            {
                maxSalary = emp [index].getSalaryRate();
                hEmp = emp [index];
            }
        index++;
    }
    return hEmp;
}

//To return Employee with Lowest Salary
Employee Employee :: getLowSalaryEmp (const Employee emp[])
{
    int index = 1;
    double minSalary = emp [0].getSalaryRate();
    Employee lEmp = emp [0];
    while(emp [index].getAge() != 0)
    {
        if(emp [index].getSalaryRate() < minSalary)
            {
                minSalary = emp [index].getSalaryRate();
                lEmp = emp [index];
            }
        index++;
    }
    return lEmp;
}

//To find an Employee by name
int Employee :: findEmployeeIndex (string name, const Employee emp[])
{
    int index = -1;
    int i = 0;
    while(emp [i].getAge() != 0)
    {
        if(name == emp[i].getName())
        {
            cout << emp[i].getEmployee();
            return i;
            break;
        }
        i++;
    }
    cout << endl << name << " employee not found";
    return -1;
}