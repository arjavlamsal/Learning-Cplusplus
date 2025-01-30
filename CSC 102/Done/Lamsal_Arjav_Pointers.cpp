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

int countBooks(string );
void getData(string *, string *, double *, int *);

void displayResults(string *, string *, double *, int *, int );
void releaseArrays(string *&, string *&, double *&, int *&);

int main(){

/*
    // POINTERS
    // **

    int x = 12;                                    // define an int variable x
    cout << x << endl
         << &x << endl;                            // & is the address operator

    int *ptr;                                      // define a pointer to an int
    ptr = &x;                                      // assign the memory address of variable x to the pointer
    cout << ptr << endl                           // display the value of the pointer the value of the pointer is a memory address
         << *ptr << endl;                          // is the indirection operator                                            // displays the value of x
    *ptr = 100;                                    // change the value of the memory
    cout << *ptr << endl                          // display the value of x
         << x << endl << endl;                     // Location pointed to by ptr to 100



    // -----------------------------------------------
    // Relationship between arrays and pointers
    // -----------------------------------------------

    int data[3] = {14, 7, 11}; // Declare and initialize an array

    cout << data << endl     // Display the starting memory address of the array
         << data + 1 << endl  // Display the address of the 2nd array element
         << data + 2 << endl;  // Display the address of the 3rd array element

    cout << data[0] << endl  // Display array contents using subscript notation
         << data[1] << endl
         << data[2] << endl;

    cout << *data << endl    // Display array contents using pointer notation
         << *(data + 1) << endl
         << *(data + 2) << endl;

    ptr = data; // Address is not needed because the array name "data" is a memory address
    cout << ptr << endl    // Display the starting memory address of the array
         << ptr + 1 << endl  // Display the address of the 2nd array element
         << ptr + 2 << endl;  // Display the address of the 3rd array element

    cout << ptr[0] << endl  // Display array contents using subscript notation
         << ptr[1] << endl
         << ptr[2] << endl;

    cout << *ptr << endl
         << *(ptr + 1) << endl
         << *(ptr + 2) << endl << endl;
*/

    // -----------------------------------------------
    // Dynamic Memory Allocation
    // -----------------------------------------------

    // Count number of books in text file.
    int number_of_books = countBooks("books.txt");

    // Define dynamic arrays of size number_of_books.
    string *item_number = new string[number_of_books];
    string *title = new string[number_of_books];
    double *price = new double[number_of_books];
    int *quantity = new int[number_of_books];
    // Read data from file.
    getData(item_number, title, price, quantity);

    // Display resulting data.
    displayResults(item_number, title, price, quantity, number_of_books);

    // Release all allocated memory.
    releaseArrays(item_number, title, price, number_of_books);

    return 0;
}



// -----------------------------------------------------------------------------------------
// Function releaseArrays: This function releases dynamic memory and sets pointers to null.
// -----------------------------------------------------------------------------

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
// -------------------------------------------------------------------------------------------------------------

void displayResults(string *item_number, string *title, double *price, int *quantity, int number_of_books) {

    // Declare accumulator variable to store the total inventory value.
    double total_retail_value = 0, retail_value;

    int w1 = 13, w2 = 25, w3 = 10, w4 = 14;
    cout << left << setw(w1) << "Item Number" << setw(w2) << "Title"
         << setw(w1) << "Retail Price" << right << setw(w3) << "Quantity" << setw(w4) << "Retail Value" << endl;
    cout << "-----------------------------------------------------------------" << endl;

    // Display data in tabular form.
    cout << setprecision(2) << fixed;
    for (int index = 0; index < number_of_books; index++) {
        retail_value = quantity[index] * price[index];

        cout << left;
        cout << setw(w1) << item_number[index]
             << setw(w2) << title[index]
             << right << setw(w1) << price[index]
             << setw(w3) << quantity[index]
             << setw(w4) << retail_value << endl;

        total_retail_value += retail_value;
    }

    cout << endl << "Total retail value: $" << total_retail_value << endl;
}




// ---------------------------------------------------------------------------------------------
// Function countBooks: This function reads all books stored in a text file
// and returns the total number of books.
// ---------------------------------------------------------------------------------------------

int countBooks(string filename) {
    ifstream infile;
    infile.open(filename.c_str());

    string line;
    int count = 0;

    while (getline(infile, line)) { // Read item number.
        getline(infile, line);  // Read title.
        getline(infile, line);  // Read price.
        getline(infile, line);  // Read quantity.
        getline(infile, line);  // Read blank line.
        count++;
    }

    infile.close();

    return count;
}





