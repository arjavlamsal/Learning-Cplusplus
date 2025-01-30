/*
Program Name: Auto Repair Bill Calculator
Programmer: Arjav Lamsal
Date Created: 11-04-2024
Program Description:
    This program calculates a customer's auto repair bill based on the labor hours and parts cost. It utilizes 
    object-oriented programming techniques, including the definition of an AutoRepairBill class. The class includes 
    methods to calculate the labor cost, subtotal, sales tax, and total cost, and to display the complete bill as a receipt.
*/


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

class AutoRepairBill
{
private:
    string customer_name;
    string phone_number;
    string vehicle_make;
    string vehicle_model;
    string vehicle_year;
    string work_performed;
    double labor_hours;
    double parts_cost;

public:
    // Default constructor
    AutoRepairBill() : labor_hours(0.0), parts_cost(0.0) {}

    // Full constructor
    AutoRepairBill(string name, string phone, string make, string model, string year, 
                   string work, double hours, double cost)
        : customer_name(name), phone_number(phone), vehicle_make(make), vehicle_model(model),
          vehicle_year(year), work_performed(work), labor_hours(hours), parts_cost(cost) {}

    // Setters
    void setCustomerName(const string &name) { customer_name = name; }
    void setPhoneNumber(const string &phone) { phone_number = phone; }
    void setVehicleMake(const string &make) { vehicle_make = make; }
    void setVehicleModel(const string &model) { vehicle_model = model; }
    void setVehicleYear(const string &year) { vehicle_year = year; }
    void setWorkPerformed(const string &work) { work_performed = work; }
    void setLaborHours(double hours) { labor_hours = hours; }
    void setPartsCost(double cost) { parts_cost = cost; }

    // Getters
    string getCustomerName() const { return customer_name; }
    string getPhoneNumber() const { return phone_number; }
    string getVehicleMake() const { return vehicle_make; }
    string getVehicleModel() const { return vehicle_model; }
    string getVehicleYear() const { return vehicle_year; }
    string getWorkPerformed() const { return work_performed; }
    double getLaborHours() const { return labor_hours; }
    double getPartsCost() const { return parts_cost; }

    // Calculation functions
    double getLaborCost() const { return labor_hours * 100.0; }
    double getSubtotal() const { return getLaborCost() + parts_cost; }
    double getSalesTax() const { return getSubtotal() * 0.07; }
    double getTotal() const { return getSubtotal() + getSalesTax(); }

    // Function to print the bill
    void print() const {
        cout << fixed << setprecision(2);
        cout << "\nCustomer Name: " << customer_name << endl;
        cout << "Phone Number: " << phone_number << endl;
        cout << "Vehicle: " << vehicle_year << " " << vehicle_make << " " << vehicle_model << endl;
        cout << "Work Performed: " << work_performed << endl;
        cout << "Labor Hours: " << labor_hours << endl;
        cout << "Labor Cost: $" << getLaborCost() << endl;
        cout << "Parts Cost: $" << parts_cost << endl;
        cout << "Subtotal: $" << getSubtotal() << endl;
        cout << "Sales Tax (7%): $" << getSalesTax() << endl;
        cout << "Total: $" << getTotal() << endl;
    }
};

// **********************************************************************************************************
//                                         F U N C T I O N     M A I N
// **********************************************************************************************************

// Function prototype statements
void getData(string &, string &, string &, string &, string &, string &, double &, double &);

int main()
{
    // Define variables
    string customer_name, phone_number, make, model, year, work_performed;
    double labor_hours, parts_cost;
    
    // Get data from the user
    getData(customer_name, phone_number, make, model, year, work_performed, labor_hours, parts_cost);
    
    // Define an instance of the AutoRepairBill class using the full constructor
    AutoRepairBill repair_bill(customer_name, phone_number, make, model, year, work_performed, labor_hours, parts_cost);
    
    // Display output
    repair_bill.print();        
    
    return 0;
}    

void getData(string &customer_name, string &phone_number, string &make, string &model, 
             string &year, string &work_performed, double &labor_hours, double &parts_cost)
{
    cout << "Enter customer name: ";
    getline(cin, customer_name);
    cout << "Enter phone number: ";
    getline(cin, phone_number);
    cout << "Enter vehicle make: ";
    getline(cin, make);
    cout << "Enter vehicle model: ";
    getline(cin, model);
    cout << "Enter vehicle year: ";
    getline(cin, year);
    cout << "Enter work performed: ";
    getline(cin, work_performed);
    cout << "Enter labor hours: ";
    cin >> labor_hours;
    cout << "Enter parts cost: ";
    cin >> parts_cost;
}
