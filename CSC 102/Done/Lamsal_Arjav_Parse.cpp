// // Program Name: Parse
// // Programmer: Arjav Lamsal
// // Date Created: September 26, 2024
// // Program Description: This program asks the user to input their full name, address, and birthday,
// // parses the input, and displays the information in a formatted manner.`

#include <iostream>
#include <string>  // For using string objects
#include <sstream> // For string stream manipulation

using namespace std;

// Function prototypes
void parseAndDisplay(const string&, const string&, const string&);

int main() {
    string fullName, address, birthday;

    // Input user information
    cout << "Enter full name (e.g., John Willis Smith): ";
    getline(cin, fullName);

    cout << "Enter city, state, zip code (e.g., Long Beach, MS 39560): ";
    getline(cin, address);

    cout << "Enter birthday (e.g., May 18, 1998): ";
    getline(cin, birthday);

    // Call function to parse and display data
    parseAndDisplay(fullName, address, birthday);

    return 0;
}

// This function parses the user input and displays it in the required format
void parseAndDisplay(const string& fullName, const string& address, const string& birthday) {
    string firstName, middleInitial, lastName, city, state, zipCode, month, day, year;
    
    // Parse full name (Assuming the input format is always "First Middle Last")
    istringstream nameStream(fullName);
    nameStream >> firstName >> middleInitial >> lastName;
    
    // Parse address (city, state, and zip code)
    istringstream addressStream(address);
    addressStream >> city >> state >> zipCode;
    
    // Parse birthday (month, day, year)
    istringstream birthdayStream(birthday);
    birthdayStream >> month >> day >> year;
    
    // Output the parsed data in the specified format
    cout << "\nParsed Data:\n";
    cout << "Name: " << lastName << ", " << firstName << " " << middleInitial[0] << ".\n";
    cout << "City: " << city << endl;
    cout << "State: " << state << endl;
    cout << "Zip code: " << zipCode << endl;
    cout << "Birthday: " << month << " " << day.substr(0, day.size()-1) << ", " << year << endl;
}
