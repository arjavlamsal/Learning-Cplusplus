// Program: Chapter 11 Example
// Programmer: Arjav Lamsal
// Date created: 10/07/2024
// Description: This program defines a structure named PayRoll that consists
// of the following members: employee_ID, name, hours_worked, pay_rate, and
// gross_pay. This program then reads employee data from a text file into an
// array of type PayRoll. The records are then sorted by the name field and
// displayed on the screen.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

// PayRoll definition
struct PayRoll {
    int employee_ID;
    string name;
    double hours_worked;
    double pay_rate;
    double gross_pay;
};

// Function Declarations
void getData(PayRoll [], int &, string );
void displayOutput(const PayRoll [], int );
void sortByName(PayRoll [], int );


const int MAX_NUM_OF_EMPLOYEES = 100;


int main() {
/*
    system("color f0"); // Does not work on Macs

    PayRoll dept_head;
    string line;

    cout << "Enter the following data for the department:\n\n";

    cout << "Employee ID: ";
    getline(cin, line);
    dept_head.employee_ID = atoi(line.c_str());

    cout << "Name: ";
    getline(cin, dept_head.name);

    cout << "Hours worked: ";
    getline(cin, line);
    dept_head.hours_worked = atof(line.c_str());

    cout << "Pay rate: ";
    getline(cin, line);
    dept_head.pay_rate = atof(line.c_str());

    dept_head.gross_pay = dept_head.hours_worked * dept_head.pay_rate;

    cout << setprecision(2) << fixed << endl;
    cout << "Gross pay: $" << dept_head.gross_pay << endl;
*/

    PayRoll employees[MAX_NUM_OF_EMPLOYEES];
    int number_of_employees;

    getData(employees, number_of_employees, "employee data.txt");
    sortByName(employees, number_of_employees);
    displayOutput(employees, number_of_employees);


    return 0;
}



// ************************************************************************
// Function displayOutput: This function displays the contents of the employees array.
// ************************************************************************
void displayOutput(const PayRoll employees[], int number_of_employees)
{
    cout << endl;
    cout << setprecision(2) << fixed;

    cout << left << setw(15) << "Employee ID" << setw(20) << "Employee Name"
         << right << setw(12) << "Hours Worked" << setw(12) << "Pay Rate"
         << setw(12) << "Gross Pay" << endl;
    cout << "------------------------------------------------------------\n";

    for (int index = 0; index < number_of_employees; index++)
    {
        cout << left << setw(15) << employees[index].employee_ID
             << setw(20) << employees[index].name
             << right << setw(12) << employees[index].hours_worked
             << setw(12) << employees[index].pay_rate
             << setw(12) << employees[index].gross_pay << endl;
    }
}

// **************************************************************************************
// Function getData: This function reads data from a text file into the employees array.
// **************************************************************************************

void getData(PayRoll employees[], int &number_of_employees, string filename)
{
    ifstream infile;
    infile.open(filename.c_str());
    string line;

    int index = 0;
    while (getline(infile, line)) // read employee ID
    {
        employees[index].employee_ID = atoi(line.c_str());

        // read name
        getline(infile, employees[index].name);

        // read hours worked
        getline(infile, line);
        employees[index].hours_worked = atof(line.c_str());

        // read pay rate
        getline(infile, line);
        employees[index].pay_rate = atof(line.c_str());

        // calculate gross pay
        employees[index].gross_pay = employees[index].pay_rate * employees[index].hours_worked;

        // read blank line
        getline(infile, line);

        index++;
    }
    infile.close();

    number_of_employees = index;
}


// *******************************************************************************
// Function sortByName: This function uses the Selection Sort algorithm to sort
// the data in the employees array. The data are sorted by the name field.
// *******************************************************************************
void sortByName(PayRoll employees[], int size)
{
    int minimum_index;
    string minimum_value;

    for (int count = 0; count < size - 1; count++)
    {
        minimum_value = employees[count].name;
        for (int index = count + 1; index < size; index++)
            if (employees[index].name < minimum_value)
            {
                minimum_value = employees[index].name;
                minimum_index = index;
            }
        if (minimum_value != employees[count].name)
        {
            PayRoll temp = employees[count];
            employees[count] = employees[minimum_index];
            employees[minimum_index] = temp;
        }
    }
}