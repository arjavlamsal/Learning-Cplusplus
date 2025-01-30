// Project: Used Cars Inventory Program
// Programmer: Arjav Lamsal
// Date: 10-7-2024
// Description: This program reads vehicle data from a file, applies a discount, and displays the inventory.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// Maximum number of vehicles that can be stored
const int MAX_NUMBER_OF_VEHICLES = 500;

// Structure to store vehicle information
struct Vehicle {
    string make;
    string model;
    string year;
    string mileage;
    double price;
    double discount_price;
};

// Function prototypes
double getDiscountRate();
void getData(Vehicle vehicles[], int& count, double discountRate);
void displayOutput(const Vehicle vehicles[], int count);

int main() {
    // Array to store vehicle data
    Vehicle vehicles[MAX_NUMBER_OF_VEHICLES];
    // Counter for the number of vehicles read
    int vehicleCount = 0;
    // Get discount rate from user
    double discountRate = getDiscountRate();
    
    // Read data from file and apply discount
    getData(vehicles, vehicleCount, discountRate);
    // Display the inventory
    displayOutput(vehicles, vehicleCount);

    return 0;
}

// Function to get the discount rate from the user
double getDiscountRate() {
    double rate;
    while (true) {
        cout << "Enter the discount rate (0-99.9%): ";
        if (cin >> rate && rate >= 0 && rate < 100) {
            return rate / 100.0; // Convert percentage to decimal
        }
        cout << "Invalid input. Please enter a number between 0 and 99.9." << endl;
        // Clear error flags and ignore invalid input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Function to read data from file and store in the vehicles array
void getData(Vehicle vehicles[], int& count, double discountRate) {
    ifstream inFile("car inventory.txt");
    if (!inFile) {
        cout << "Error opening file. Please make sure 'car inventory.txt' exists." << endl;
        exit(1);
    }

    string line;
    while (getline(inFile, vehicles[count].make) && count < MAX_NUMBER_OF_VEHICLES) {
        // Read vehicle details
        getline(inFile, vehicles[count].model);
        getline(inFile, vehicles[count].year);
        getline(inFile, vehicles[count].mileage);
        getline(inFile, line);
        vehicles[count].price = stod(line); // Convert string to double
        // Calculate discounted price
        vehicles[count].discount_price = vehicles[count].price * (1 - discountRate);
        getline(inFile, line); // Read the blank line

        count++; // Increment vehicle count
    }

    inFile.close(); // Close the file
}

// Function to display the vehicle inventory
void displayOutput(const Vehicle vehicles[], int count) {
    // Display headers
    cout << left 
         << setw(12) << "Price" 
         << setw(12) << "Disc. Price" << endl;
    
    // Display a line to separate headers from data
    cout << string(30, '-') << endl;

    // Display each vehicle's information
    for (int i = 0; i < count; i++) {
        cout << left << setw(10) << vehicles[i].make
             << setw(20) << vehicles[i].model
             << setw(6) << vehicles[i].year
             << setw(10) << vehicles[i].mileage
             << "$" << setw(11) << fixed << setprecision(2) << vehicles[i].price
             << "$" << setw(11) << fixed << setprecision(2) << vehicles[i].discount_price << endl;
    }
}