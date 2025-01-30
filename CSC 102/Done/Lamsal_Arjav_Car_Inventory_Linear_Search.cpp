// Project: Car Lot Inventory
// Programmer: Arjav Lamsal
// Date: September 12, 2024
// Description: This program prompts the user to enter a car's inventory number,
// performs linear search to read car inventory from a file " inventory.txt",
// searches by car ID, and outputs its price and description. If the number is not found will
// output "Not Found". 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function prototypes
void getData(string[], string[], int[], double[], int);
void processUserSelections(string[], string[], int[], double[], int);
void displayResults(string, string[], string[], int[], double[], int);
int linearSearch(string[], int, string);

const int NUM_CARS = 40;  // Number of cars based on the inventory.txt file

int main() {
    string inventory_number[NUM_CARS];
    string description[NUM_CARS];
    int mileage[NUM_CARS];
    double price[NUM_CARS];

    // Read data from file
    getData(inventory_number, description, mileage, price, NUM_CARS);
    
    // Process user selections
    processUserSelections(inventory_number, description, mileage, price, NUM_CARS);

    return 0;
}

// Function to read data from inventory.txt file
void getData(string inventory_number[], string description[], int mileage[], double price[], int size) {
    ifstream inputFile("inventory.txt");

    if (!inputFile) {
        cout << "Error opening the file!" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        getline(inputFile, inventory_number[i]); // Inventory number
        getline(inputFile, description[i]);      // Description (year, make, model)
        inputFile >> mileage[i];                 // Mileage
        inputFile >> price[i];                   // Price
        inputFile.ignore();                      // Ignore newline after reading price
    }

    inputFile.close();
}

// Function to process user selections
void processUserSelections(string inventory_number[], string description[], int mileage[], double price[], int size) {
    string userInput;
    
    while (true) {
        cout << "Enter a car's inventory number (or 'q' to quit): ";
        getline(cin, userInput);

        if (userInput == "q" || userInput == "Q") {
            break;
        }

        int index = linearSearch(inventory_number, size, userInput);
        
        if (index != -1) {
            displayResults(userInput, inventory_number, description, mileage, price, index);
        } else {
            cout << "Inventory number not found." << endl;
        }
    }
}

// Function to display the car details
void displayResults(string inventory_num, string inventory_number[], string description[], int mileage[], double price[], int index) {
    cout << "Inventory Number: " << inventory_number[index] << endl;
    cout << "Description: " << description[index] << endl;
    cout << "Mileage: " << mileage[index] << " miles" << endl;
    cout << "Price: $" << price[index] << endl;
}

// Function to perform linear search
int linearSearch(string array[], int size, string value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i;  // Return index where the inventory number was found
        }
    }
    return -1;  // Return -1 if the inventory number was not found
}
