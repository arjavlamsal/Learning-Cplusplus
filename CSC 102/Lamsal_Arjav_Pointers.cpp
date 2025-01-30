// Program: Chapter 9 Example
// Programmer: Arjav Lamsal (w10195547)
// Date created: September 18, 2024
// Description: This program explains how to define and use pointer variables.
//              This program also reads data from a text file into parallel dynamic arrays
//              and displays this data on the computer screen in tabular format.

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// Function prototypes
int countBooks(string filename);
void getData(string *item_number, string *title, double *price, int *quantity, int number_of_books);
void displayResults(string *item_number, string *title, double *price, int *quantity, int number_of_books);
void releaseArrays(string *&item_number, string *&title, double *&price, int *&quantity);

int main() {
    // Count number of books in text file.
    int number_of_books = countBooks("books.txt");

    // If no books are found or file could not be opened, terminate the program.
    if (number_of_books == 0) {
        cout << "No books found in the file or file could not be opened." << endl;
        return 1;
    }

    // Define dynamic arrays of size number_of_books.
    string *item_number = new string[number_of_books]; // Array to store item numbers
    string *title = new string[number_of_books];       // Array to store titles
    double *price = new double[number_of_books];       // Array to store prices
    int *quantity = new int[number_of_books];          // Array to store quantities

    // Read data from file.
    getData(item_number, title, price, quantity, number_of_books);

    // Display resulting data in tabular format.
    displayResults(item_number, title, price, quantity, number_of_books);

    // Release all allocated memory.
    releaseArrays(item_number, title, price, quantity);

    return 0;
}

// -----------------------------------------------------------------------------------------
// Function releaseArrays: This function releases dynamic memory and sets pointers to null.
// Parameters:
//     - item_number: Pointer to the dynamic array of item numbers
//     - title: Pointer to the dynamic array of titles
//     - price: Pointer to the dynamic array of prices
//     - quantity: Pointer to the dynamic array of quantities
// -----------------------------------------------------------------------------------------
void releaseArrays(string *&item_number, string *&title, double *&price, int *&quantity) {
    // Delete arrays.
    delete[] item_number;
    delete[] title;
    delete[] price;
    delete[] quantity;

    // Make pointer names point to null.
    item_number = nullptr;
    title = nullptr;
    price = nullptr;
    quantity = nullptr;
}

// -------------------------------------------------------------------------------------------------------------
// Function displayResults: This function displays the following data for each book: item_number, title, price,
// and quantity. This function also calculates and displays the total retail value of all books.
// Parameters:
//     - item_number: Pointer to the array of item numbers
//     - title: Pointer to the array of titles
//     - price: Pointer to the array of prices
//     - quantity: Pointer to the array of quantities
//     - number_of_books: Total number of books
// -------------------------------------------------------------------------------------------------------------
void displayResults(string *item_number, string *title, double *price, int *quantity, int number_of_books) {
    // Declare accumulator variable to store the total inventory value.
    double total_retail_value = 0, retail_value;

    // Column widths for tabular display.
    int w1 = 13, w2 = 25, w3 = 10, w4 = 14;

    // Display table header.
    cout << left << setw(w1) << "Item Number" << setw(w2) << "Title"
         << setw(w1) << "Retail Price" << right << setw(w3) << "Quantity" << setw(w4) << "Retail Value" << endl;
    cout << "-----------------------------------------------------------------" << endl;

    // Display data in tabular form.
    cout << setprecision(2) << fixed; // Set floating-point precision for prices.
    for (int index = 0; index < number_of_books; index++) {
        retail_value = quantity[index] * price[index]; // Calculate retail value for current book.

        cout << left;
        cout << setw(w1) << item_number[index]
             << setw(w2) << title[index]
             << right << setw(w1) << price[index]
             << setw(w3) << quantity[index]
             << setw(w4) << retail_value << endl;

        total_retail_value += retail_value; // Accumulate total retail value.
    }

    // Display total retail value.
    cout << endl << "Total retail value: $" << total_retail_value << endl;
}

// ---------------------------------------------------------------------------------------------
// Function countBooks: This function reads all books stored in a text file
// and returns the total number of books.
// Parameters:
//     - filename: Name of the text file containing book data
// Returns:
//     - Total number of books in the file
// ---------------------------------------------------------------------------------------------
int countBooks(string filename) {
    ifstream infile(filename.c_str()); // Open file for reading.

    // Check if file opened successfully.
    if (!infile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return 0;
    }

    string line;
    int count = 0;

    // Read lines from the file.
    while (getline(infile, line)) { // Read item number.
        getline(infile, line);  // Read title.
        getline(infile, line);  // Read price.
        getline(infile, line);  // Read quantity.
        getline(infile, line);  // Read blank line.
        count++;
    }

    infile.close(); // Close the file.
    return count; // Return the number of books.
}

// -------------------------------------------------------------------------------------------------------------
// Function getData: This function reads book data from a file and stores it in dynamic arrays.
// Parameters:
//     - item_number: Pointer to the dynamic array of item numbers
//     - title: Pointer to the dynamic array of titles
//     - price: Pointer to the dynamic array of prices
//     - quantity: Pointer to the dynamic array of quantities
//     - number_of_books: Total number of books
// -------------------------------------------------------------------------------------------------------------
void getData(string *item_number, string *title, double *price, int *quantity, int number_of_books) {
    ifstream infile("books.txt"); // Open file for reading.

    // Check if file opened successfully.
    if (!infile.is_open()) {
        cerr << "Error opening file for reading data." << endl;
        return;
    }

    // Read data for each book.
    for (int i = 0; i < number_of_books; i++) {
        getline(infile, item_number[i]); // Read item number.
        getline(infile, title[i]);       // Read title.
        infile >> price[i];              // Read price.
        infile >> quantity[i];           // Read quantity.
        infile.ignore();                 // Ignore trailing newline character.
        infile.ignore();                 // Ignore blank line.
    }

    infile.close(); // Close the file.
}
