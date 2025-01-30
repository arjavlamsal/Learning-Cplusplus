// Project: Employees Assignment 
// Programmer: Arjav Lamsal (w10195547)
// Date: September 18, 2024
// Description: This program calculates and displays the total pay for each employee in a company.

#include <iostream>
#include <iomanip> // for setw and formatting
using namespace std;

int main() {
    int numEmployees;

    // 1. Ask for the number of employees
    cout << "Enter the number of employees: ";
    cin >> numEmployees;
    cout << '\n';


    // 2. Dynamic array for employee names
    string* namesPtr = new string[numEmployees];

    // 3. Input employee names
    for (int i = 0; i < numEmployees; i++) {
        cout << "Enter the name of employee " << i + 1 << ": ";
        cin >> namesPtr[i];
    }
    cout << '\n';

    // 4. Dynamic array for pay rates
    double* payRatePtr = new double[numEmployees];

    // 5. Input pay rates
    for (int i = 0; i < numEmployees; i++) {
        cout << "Enter the pay rate for " << namesPtr[i] << ": ";
        cin >> payRatePtr[i];
    }
    cout << '\n';

    // 6. Dynamic array for hours worked
    double* hoursWorkedPtr = new double[numEmployees];

    // 7. Input hours worked
    for (int i = 0; i < numEmployees; i++) {
        cout << "Enter the hours worked by " << namesPtr[i] << ": ";
        cin >> hoursWorkedPtr[i];
    }
    cout << '\n';

    // 8. Dynamic array for total pay
    double* totalPayPtr = new double[numEmployees];

    // 9. Calculate total pay
    for (int i = 0; i < numEmployees; i++) {
        totalPayPtr[i] = payRatePtr[i] * hoursWorkedPtr[i];
    }

    // 10. Display output
    cout << "-------------------------------" << endl;
    cout << left << setw(15) << "Employee Name" << right << setw(10) << "Total Pay" << endl;
    cout << "-------------------------------" << endl;
    for (int i = 0; i < numEmployees; i++) {
        cout << left << setw(15) << namesPtr[i] << right << fixed << setprecision(2) << setw(10) << totalPayPtr[i] << endl;
    }
    
    cout << '\n';
    cout <<  "Press any key to continue ...";

    // Cleanup dynamic memory
    delete[] namesPtr;
    delete[] payRatePtr;
    delete[] hoursWorkedPtr;
    delete[] totalPayPtr;

    return 0;
}
