// Project: Payroll Database
// Programmer: Arjav Lamsal
// Date: 20th Oct 2024
// Description: This program manages employee records. It allows the user to add employees and display the employee data
//              in a formatted table. The program continues to run until the user chooses to exit the menu.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Constants for formatting column widths
const int WIDTH_NAME = 20;  // Width for employee name column
const int WIDTH_ID = 10;    // Width for employee ID column
const int WIDTH_SALARY = 15; // Width for employee salary column

// Structure to hold employee data
struct Employee {
    string name;  // Employee name
    int id;       // Employee ID number
    double salary; // Employee salary
};

// Function prototypes
void displayMenu();  // Function to display the main menu
int getMenuChoice();  // Function to get the user's menu choice
void addNewEmployee(vector<Employee> &employees);  // Function to add a new employee
void displayEmployeeData(const vector<Employee> &employees);  // Function to display employee data

int main() {
    vector<Employee> employees;  // Vector to store employee records
    int choice;  // Variable to store user's menu choice

    // Loop to display menu and process user choices
    do {
        displayMenu();
        choice = getMenuChoice();

        switch (choice) {
            case 1:
                addNewEmployee(employees);  // Add a new employee
                break;
            case 2:
                displayEmployeeData(employees);  // Display all employee data
                break;
            case 3:
                cout << "Exiting program." << endl;  // Exit the program
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;  // Invalid choice message
        }
    } while (choice != 3);  // Loop until the user chooses to exit

    return 0;
}

// Display the main menu options
void displayMenu() {
    cout << "\n----------------------------------" << endl;
    cout << "    Payroll Database Main Menu" << endl;
    cout << "----------------------------------" << endl;
    cout << "1. Add New Employee" << endl;
    cout << "2. Display Employee Data" << endl;
    cout << "3. Exit" << '\n' << endl;
}

// Get and return the user's menu choice
int getMenuChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    return choice;
}

// Add a new employee to the employees vector
void addNewEmployee(vector<Employee> &employees) {
    Employee newEmployee;  // Temporary Employee object to hold new employee data
    cout << "Enter employee name: ";
    cin.ignore();  // Clear the newline character from previous input
    getline(cin, newEmployee.name);  // Get employee name
    cout << "Enter employee ID: ";
    cin >> newEmployee.id;  // Get employee ID
    cout << "Enter employee salary: ";
    cin >> newEmployee.salary;  // Get employee salary
    employees.push_back(newEmployee);  // Add the new employee to the employees vector
    system("clear");  // Clear the screen
}

// Display all employee data in a formatted table
void displayEmployeeData(const vector<Employee> &employees) {
    if (employees.empty()) {  // Check if there is any employee data to display
        cout << "No employee data to display." << endl;
        return;
    }

    // Print table headers with proper alignment
    cout << left << setw(WIDTH_NAME) << "Name"
         << setw(WIDTH_ID) << "ID"
         << setw(WIDTH_SALARY) << "Salary" << endl;
    cout << "---------------------------------------------" << endl;

    // Loop through each employee and display their data in a formatted manner
    for (const auto &employee : employees) {
        cout << left << setw(WIDTH_NAME) << employee.name
             << setw(WIDTH_ID) << employee.id
             << setw(WIDTH_SALARY) << fixed << setprecision(2) << employee.salary << endl;
    }
}
