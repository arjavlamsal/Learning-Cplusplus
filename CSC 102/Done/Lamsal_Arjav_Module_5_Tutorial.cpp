// Program: Module 5 Tutorial
// Programmer: Arjav Lamsal
// Date created: 09-26-2024
// Description: This program demonstrates how to:
//              * use character testing functions
//              * create C-strings
//              * use library functions for working with C-strings
//              * use C-string numeric conversion functions
//              * use string class member functions

#include <iostream>
#include <string>
#include <cstring>    // required by strcat(), strstr(), strlen()
#include <cctype>     // required by isdigit(), toupper(), tolower()
#include <cstdlib>    // required by atof(), atoi()

using namespace std;

// Protoype statements
double getDouble();
bool isNumber(char[]);
string getPrice(string );
string getMileage(string );
string getMake(string );
string getModel(string );
string getYear(string );


int main()
{
	system("color f0");	

	//*******************************************************************************
	//                    Character Testing Functions (p. 542)
	//*******************************************************************************

	char input;

	cout << "Enter any character = ";
	cin.get(input);
	cout << "The character You entered is: " << input << endl << endl;

	if (isalpha(input)){
		cout << "That's an alphabetic character. \n";
	}
	if (isdigit(input)){
		cout << "That's a numeric digit. \n";
	}
	if (islower(input)){
		cout << "The letter you entered is in lowercase. \n";
	}
	if (isupper(input)){
		cout << "The letter you entered is in uppercase. \n";
	}
	if (isspace(input)){
		cout << "That's a whitespace character. \n";
	}
	if (ispunct(input)){
		cout << "That's a non alpha-numeric character. \n";
	}
	if (isprint(input)){
		cout << "That's a printable character. \n";
	}


	//*******************************************************************************
	//                                    C-STRINGS
	//*******************************************************************************

	const int SIZE = 40;

	//Declare two c-strings.
	char name1[SIZE], name2[SIZE];

	cout << "\nEnter your first name: ";

	// Use the cin.getline() to read first name into name1.
	cin.ignore();
	cin.getline(name1, SIZE);

	// Capitalize first character of first name.
	name1[0] = toupper(name1[0]);	// Func toupper requires header #include <cctype>>

	// Change every character except for the first one to lowercase.
	for (int c = 1; c < strlen(name1); c++){ 	// Func strlen requires header #include <cstring>
		name1[c] = tolower(name1[c]);			// Func toupper requires header #include <cctype>
	}


	cout << "\nEnter your last name: ";

	// Use the cin.getline() to read first name into name2.
	cin.getline(name2, SIZE);

	// Capitalize first character of first name.
	name2[0] = toupper(name2[0]);	// Func toupper requires header #include <cctype>>

	// Change every character except for the first one to lowercase.
	for (int c = 1; c < strlen(name2); c++){ 	// Func strlen requires header #include <cstring>
		name2[c] = tolower(name2[c]);			// Func toupper requires header #include <cctype>
	}

	// Concatenate first name (name1) and space, store the result in name1.
	strcat(name1, " ");

	// Concatenate first name (name1) and Last name (name2), store the result in name1.
	strcat(name1, name2);

	// Use a for loop to display the contents of a c-string.
	cout << "\nHello ";
	for (int i = 0; i < strlen(name1); i++){
		cout << name1[i];
	cout << endl;
	}

	// Use a while loop to display the contents of a c-string.
	cout << "\nHello ";
	int index = 0;
	while (name1[index] != '\0'){
		cout << name1[index] << endl;
		index++;
	}

	// Display the contents of c-string using only the array name. We don't have to use loops for this.
	cout << "Hello " << name1 << endl << endl;


	//*******************************************************************************
	//      C-string Example: Read two real numbers and display their sum.
	//*******************************************************************************

	double number1 = getDouble();
	double number2 = getDouble();

	cout << "\nThe sum of " << number1 << " and " << number2 << " is " << number1 + number2 << endl << endl;

	//*******************************************************************************
	//                       MORE ABOUT THE STRING CLASS
	//*******************************************************************************
    
	string line;
    cout << "Enter automobile information\n";
    cout << "Example: 2017 Toyota Camry SE $15,600 45,800\n";

    getline(cin, line);

    cout << "Year: " << getYear(line) << endl;
    cout << "Make: " << getMake(line) << endl;
    cout << "Model: " << getModel(line) << endl;
    cout << "Mileage: " << getMileage(line) << endl;
    cout << "Price: " << getPrice(line) << endl;

    return 0;
}


//***********************************************************************************
// Function getDouble: This function asks the user to enter a real number. It then 
// reads the value entered by the user and determines if it is a valid number or not.
// If the value entered is not a valid number, an error message is displayed and this 
// function will ask the user to re-enter the number. This function returns a valid 
// real number as a double.
//***********************************************************************************
double getDouble() {

    const int SIZE = 30;
    char number[SIZE];
    bool valid = false;

    while (!valid) {

        cout << "Enter a real number: ";
        cin.getline(number, SIZE);
        if (isNumber(number)) {
            valid = true;
        } else {
            cout << "Error: invalid input.\n\n";
        }
    }

    return atof(number); // Function atof requires #include <cstdlib>
}

//***********************************************************************************
// Function isNumber. This function accepts a c-string as a parameter. This function 
// returns true if the value stored in the c-string is a valid real number or integer;
// false otherwise.
//***********************************************************************************

   bool isNumber(char text[]) {

    // if text is empty, return false
    if (text[0] == '\0') return false;

    // if number equals only a '.', return false
    if (text[0] == '.' && text[1] == '\0') return false;

    // if text ends with '.', return false
    if (text[strlen(text) - 1] == '.') return false;

    // Inspect each character of text to ensure it is valid.
    // Also, make sure that only one decimal point occurs.

    bool decimal_found = false;
    int index = 0;

    while (text[index] != '\0') {

        if (isdigit(text[index])) {
            index++;
        } else if (text[index] == '.') {
            if (decimal_found) {
                return false; // Multiple decimal points found
            }
            decimal_found = true;
            index++;
        } else {
            return false;
        }
    }

    return true;
}

//************************************************************************************
// Function getPrice: This function parses the string parameter line and returns the 
// price of the vehicle.
//************************************************************************************
string getPrice(string line) {

    int pos1 = line.find("$", 0); // find the location of the $ sign
    int pos2 = line.find(" ", pos1); // find the first space after the $ sign

    return line.substr(pos1 + 1, pos2 - pos1 - 1);
}


//************************************************************************************
// Function getMileage: This function parses the string parameter line and returns the 
// mileage of the vehicle.
//************************************************************************************
string getMileage(string line) {

    int pos1 = line.find("$", 0); // find the location of the $ sign
    int pos2 = line.find(" ", pos1); // find the first space after the $ sign

    return line.substr(pos2 + 1);
}


//************************************************************************************
// Function getModel: This function parses the string parameter line and returns the 
// model of the vehicle.
//************************************************************************************
string getModel(string line) {

    int pos1 = line.find(" ", 0);
    int pos2 = line.find(" ", pos1 + 1);
    int pos3 = line.find("$", 0);

    return line.substr(pos2 + 1, pos3 - pos2 - 2);
}


//************************************************************************************
// Function getMake: This function parses the string parameter line and returns the 
// make of the vehicle.
//************************************************************************************
string getMake(string line) {

    int pos1 = line.find(" ", 0);
    int pos2 = line.find(" ", pos1 + 1);

    return line.substr(pos1 + 1, pos2 - pos1 - 1);
}


//***********************************************************************************
// Function getYear: This function parses the string parameter line and returns the 
// year of the vehicle.
//***********************************************************************************

string getYear(string line) 
{
    string year = line.substr(0, 4);
    return year;
}

