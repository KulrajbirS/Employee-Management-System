//The application file app.cpp uses the Point Objects
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
//Including interface and implementation file
#include "employee.h"
#include "employee.cpp"
#include "date.h"
#include "date.cpp"

using namespace std;

int main ()
{
    //Variable Declaration
    string empInfo;
    Employee emps [30];
    string infoDate [3];
    string infoEmp [5];
    int index = 0;
    int iEmp = 0;
    int iDate = 0;
    int pos = 0;
    double salary;
    Date hire;
    string info_component;

    cout << "C-Brother's Employee Management System" << endl;

    //Initializing and Opening the File
    ifstream infile;
    infile.open ("employees.txt");

    cout << "Reading \"employees.txt\" file ..." << endl;
    while(getline(infile, empInfo))
    {
        //Splits the String line into separate components and stores in the Array
        while(iEmp < 5)
        {
            pos = empInfo.find(",");
            info_component = empInfo.substr(0, pos);
            infoEmp [iEmp] = info_component;
            empInfo.erase(0, empInfo.find(",") + 2);
            iEmp++;
        }

        //Splits the Date components and stores it in an array
        while(iDate < 3)
        {
            pos = infoEmp[3].find("-");
            info_component = infoEmp[3].substr(0, pos);
            infoDate [iDate] = info_component;
            infoEmp[3].erase(0, infoEmp[3].find("-") + 1);
            iDate++;
        }

        
        if(infoEmp[0] != "")
        {
            //Stores the dat components in a date variable
            hire.setDay(stoi(infoDate[1]));
            hire.setMonth(stoi(infoDate[0]));
            hire.setYear(stoi(infoDate[2]));

            //Updates the Employee Information in the already created Employee Array
            emps [index].setName(infoEmp[0]);
            emps [index].setAge(stoi(infoEmp[1]));
            emps [index].setPosition(infoEmp[2]);
            emps [index].setHiredDate(hire);
            emps [index].setSalaryRate(stof(infoEmp[4]));
        }

        index++;
        iEmp = 0;
        iDate = 0;
    }

    //File Closing
    infile.close();
    cout << "Ready!" << endl;

    //Declaration of the variables used in the Menu Process
    string answer = "y";
    string modify, newName, newPosition, newFName, newLName, newDateString, fname, lname, ename;
    ofstream ofile;
    double newSalaryRate;
    Employee highEmp, lowEmp;
    int newAge, newDay, newMonth, newYear, m_choice, choice;
    Date newDate;

    while(answer == "y")
    {
        //Printing out the options for the menu
        cout << "Choose one of the following options:" << endl;
        cout << "1. Print all employees\' information" << endl;
        cout << "2. Print all employees\' names" << endl;
        cout << "3. Find the employee with the highest salary rate" << endl;
        cout << "4. Find the employee with the lowest salary rate" << endl;
        cout << "5. Search an employee" << endl;
        cout << "6. Add a new employee" << endl;
        cout << "Your choice: ";
        cin >> choice;

        //Selecting function based on the choice of the user
        switch (choice)
        {
        case 1:
            //Printing the complete information of all employees
            Employee :: printAllEmployees(emps);
            break;
        case 2:
            //Printing the name of all employees
            Employee :: printAllNames(emps);
            break;
            
        case 3:
            //Printing the name of the Employee with Highest Salary
            highEmp = Employee :: getHighSalaryEmp(emps);
            cout << "Employee with Highest Salary Rate is " + highEmp.getName() << endl;
            break;
            
        case 4:
            //Printing the name of the Employee with Lowest Salary
            lowEmp = Employee :: getLowSalaryEmp(emps);
            cout << "Employee with Lowest Salary Rate is " + lowEmp.getName() << endl;
            break;

        case 5:
            //Gets the Name as Input from the user
            cout << "Type the employee\'s first name: ";
            cin >> fname;
            cout << "Type the employee\'s last name: ";
            cin >> lname;
            ename = fname + " " + lname;

            //Find the index of the Employee entered by the user
            index = Employee :: findEmployeeIndex(ename, emps);

            //If the employee exist, the segment of code executes
            if(index > -1)
            {
                //Asking user to modify Information
                cout << endl << "Would you like to modify this employee\'s information? (Y/N) ";
                cin >> modify;
                modify = tolower(modify[0]);

                //Executes if user says yes to modify
                while(modify == "y")
                {
                    //Printing out the options of fields to change
                    cout << "Which field would you like to modify?" << endl;
                    cout << "1. Name" << endl;
                    cout << "2. Age" << endl;
                    cout << "3. Position" << endl;
                    cout << "4. Hired Date" << endl;
                    cout << "5. Salary Rate" << endl;
                    cout << "You Choice: ";
                    cin >> m_choice;

                    //Selects the functions based on the users choice
                    switch (m_choice)
                    {
                    case 1:
                        //Updates the name
                        cout << "Please Enter New First Name: ";
                        cin >> newFName;
                        cout << "Please Enter New Last Name: ";
                        cin >> newLName;
                        newName = newFName + " " + newLName;
                        emps [index].setName(newName);
                        break;
                    
                    case 2:
                        //Updates the age
                        cout << "Please Enter New Age: ";
                        cin >> newAge;
                        emps [index].setAge(newAge);
                        break;

                    case 3:
                        //Updates the new position
                        cout << "Please Enter New position: ";
                        cin >> newPosition;
                        emps [index].setPosition(newPosition);
                        break;

                    case 4:
                        //Updates the new hiring date
                        cout << "Please enter the new day of hiring: ";
                        cin >> newDay;
                        cout << "Please enter the new month of hiring: ";
                        cin >> newMonth;
                        cout << "Please enter the new Year of hiring: ";
                        cin >> newYear;
                        newDate.setDay(newDay);
                        newDate.setMonth(newMonth);
                        newDate.setYear(newYear);
                        emps [index].setHiredDate(newDate);
                        break;

                    case 5:
                        //Update the new Salary Rate
                        cout << "Please enter the new Salary Rate: ";
                        cin >> newSalaryRate;
                        emps [index].setSalaryRate(newSalaryRate);
                        break;

                    default:
                        cout << "Invalid Input" << endl;
                        break;
                    }

                    //Asking user to change the another field
                    cout << "Would you like to change another field? (Y/N) ";
                    cin >> modify;
                }

                //Opening file for overwriting
                ofile.open("employees.txt");
                index = 0;

                //UPdating the information in the file with all the changes
                while(emps [index].getAge() != 0)
                {
                    newDateString = to_string(emps[index].getHiredDate().getMonth()) + "-" + to_string(emps[index].getHiredDate().getDay()) +
                            "-" + to_string(emps[index].getHiredDate().getYear());
                    ofile << emps [index].getName() << ", " << to_string(emps[index].getAge()) << ", " << emps[index].getPosition()
                        << ", " << newDateString << ", " << to_string(emps[index].getSalaryRate()) << endl;
                    index++;
                }

                //Closing the file
                ofile.close();
            }
            break;
            
        case 6:
            index = 0;

            //Calculating the last available index to enter new Employee in the array
            while(emps [index].getAge() != 0)
            {
                index++;
            }

            //Getting and updating name of the new Employee
            cout << "Please Enter First Name of the Employee: ";
            cin >> newFName;
            cout << "Please Enter Last Name of the Employee: ";
            cin >> newLName;
            newName = newFName + " " + newLName;
            emps [index].setName(newName);

            //Getting and updating age of the new Employee
            cout << "Please enter the age of the Employee: ";
            cin >> newAge;
            emps [index].setAge(newAge);

            //Getting and updating position of the new Employee
            cout << "Please enter the Position of the Employee: ";
            cin >> newPosition;
            emps [index].setPosition(newPosition);

            //Getting new hiring day, month and year
            cout << "Please enter the day of hiring of the Employee: ";
            cin >> newDay;
            cout << "Please enter the month of hiring of the Employee: ";
            cin >> newMonth;
            cout << "Please enter the year of hiring of the Employee: ";
            cin >> newYear;

            //Creating and updating new hiring date
            newDate.setDay(newDay);
            newDate.setMonth(newMonth);
            newDate.setYear(newYear);
            emps [index].setHiredDate(newDate);
            newDateString = to_string(newMonth) + "-" + to_string(newDay) + "-" + to_string(newYear);

            //Getting and updating Salary of the new Employee
            cout << "Please enter Salary Rate of the Employee: ";
            cin >> newSalaryRate;
            emps [index].setSalaryRate(newSalaryRate);

            //Opening file in the append mode
            ofile.open("employees.txt", ios::app);

            //Appending information of new Employee in the file
            ofile << endl << newName << ", " << to_string(newAge) << ", " << newPosition << ", " << newDateString 
                  << ", " << to_string(newSalaryRate);
            ofile.close();
            break;
            
        default:
            cout << "Invalid Input" << endl;
            break;
        }

        //Asking user to continue or nots
        cout << endl <<"Would you like to continue: ";
        cin >> answer;
    }
    return 0;
}