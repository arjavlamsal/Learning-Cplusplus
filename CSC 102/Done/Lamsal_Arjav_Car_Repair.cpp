// Project: Car Repair Bill Calculator
// Date: October 26, 2024
// Created by: Arjav Lamsal
// Description: This is a C++ Program to calculate and display car repair bills using OOP principles.

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

class CarRepairBill {
private:
    // Member variables
    string customerName;
    string phoneNumber;
    string carMake;
    string carModel;
    int carYear;
    string workDescription;
    double laborHours;
    double partsCost;
    
    // Static constants
    static const double SALES_TAX_RATE;  // 7%
    static const double LABOR_COST_PER_HOUR;  // $100/hour

    // Helper functions for formatting
    void printLine(char symbol = '=', int length = 60) const {
        cout << string(length, symbol) << endl;
    }

    void printCentered(const string& text, int width = 60) const {
        int padding = (width - text.length()) / 2;
        cout << string(padding, ' ') << text << endl;
    }

    void printSectionHeader(const string& text) const {
        printLine();
        printCentered(text);
        printLine();
    }

public:
    // Constructor
    CarRepairBill() {
        customerName = "";
        phoneNumber = "";
        carMake = "";
        carModel = "";
        carYear = 0;
        workDescription = "";
        laborHours = 0.0;
        partsCost = 0.0;
    }

    // Required functions for invoice number and date
    long int getInvoiceNumber() {
        // This function is a CarRepairBill member function. This function will 
        // generate and display an invoice number between 100000 and 999999.
        unsigned seed = time(0);
        srand(seed);        
        const int MAX_NUMBER = 999999;         
        return 100000 + rand() % MAX_NUMBER;    
    }

    void displayTodaysDate() {
        // This function is a CarRepairBill member function. This function will 
        // display the current date.
        time_t t = time(0);   
        struct tm *now = localtime(&t);
        cout << "Date:                    " 
             << (now->tm_mon + 1) << "/" 
             << now->tm_mday << "/" 
             << (now->tm_year + 1900) << endl;    
    }

    // Setters and getters
    void setCustomerName(string name) { customerName = name; }
    void setPhoneNumber(string phone) { phoneNumber = phone; }
    void setCarMake(string make) { carMake = make; }
    void setCarModel(string model) { carModel = model; }
    void setCarYear(int year) { carYear = year; }
    void setWorkDescription(string desc) { workDescription = desc; }
    void setLaborHours(double hours) { laborHours = hours; }
    void setPartsCost(double cost) { partsCost = cost; }

    string getCustomerName() const { return customerName; }
    string getPhoneNumber() const { return phoneNumber; }
    string getCarMake() const { return carMake; }
    string getCarModel() const { return carModel; }
    int getCarYear() const { return carYear; }
    string getWorkDescription() const { return workDescription; }
    double getLaborHours() const { return laborHours; }
    double getPartsCost() const { return partsCost; }

    // Calculation methods
    double calculateLaborCost() const { return laborHours * LABOR_COST_PER_HOUR; }
    double calculateSubtotal() const { return calculateLaborCost() + partsCost; }
    double calculateSalesTax() const { return calculateSubtotal() * SALES_TAX_RATE; }
    double calculateTotal() const { return calculateSubtotal() + calculateSalesTax(); }

    void displayWelcomeScreen() const {
        system("cls"); // Clear screen (use "clear" for Unix-based systems)
        printLine('*');
        printCentered("WELCOME TO THE CAR REPAIR PROGRAM");
        printLine('*');
        cout << endl;
    }

    void printReceipt() {
        system("cls"); // Clear screen
        cout << fixed << setprecision(2);
        
        // Header
        printLine('*');
        printCentered("AUTO REPAIR RECEIPT");
        printLine('*');
        cout << endl;

        // Invoice and Date (using the required functions)
        cout << "Invoice number: " << getInvoiceNumber() << endl;
        displayTodaysDate();
        cout << endl;

        // Customer Section
        printSectionHeader("CUSTOMER INFORMATION");
        cout << "Customer name: " << customerName << endl;
        cout << "Customer phone number: " << phoneNumber << endl;
        cout << endl;

        // Vehicle Section
        printSectionHeader("VEHICLE INFORMATION");
        cout << "Make: " << carMake << endl;
        cout << "Model: " << carModel << endl;
        cout << "Year: " << carYear << endl;
        cout << "Work performed: " << workDescription << endl;
        cout << endl;

        // Costs Section
        printSectionHeader("COST BREAKDOWN");
        cout << "Labor cost: $" << calculateLaborCost() << endl;
        cout << "Parts cost: $" << partsCost << endl;
        cout << "Subtotal: $" << calculateSubtotal() << endl;
        cout << "Sales tax: $" << calculateSalesTax() << endl;
        printLine('-');
        cout << "Total: $" << calculateTotal() << endl;
        printLine('*');
        
        // Footer
        printCentered("Thank you for your business!");
        printLine('*');
    }

    void getCustomerInput() {
        displayWelcomeScreen();
        printCentered("Please enter the following information:");
        cout << endl;

        cout << "Customer's name: ";
        getline(cin, customerName);

        cout << "Customer's telephone number: ";
        getline(cin, phoneNumber);

        cout << "Car make: ";
        getline(cin, carMake);

        cout << "Car model: ";
        getline(cin, carModel);

        cout << "Car year: ";
        cin >> carYear;
        cin.ignore();

        cout << "Description of work performed: ";
        getline(cin, workDescription);

        cout << "Total labor hours: ";
        cin >> laborHours;

        cout << "Total parts cost: ";
        cin >> partsCost;

        cout << "\nProcessing your receipt...\n";
        system("pause");
    }
};

// Define static constants
const double CarRepairBill::SALES_TAX_RATE = 0.07;
const double CarRepairBill::LABOR_COST_PER_HOUR = 100.00;

int main() {
    CarRepairBill bill;
    bill.getCustomerInput();
    bill.printReceipt();
    return 0;
}