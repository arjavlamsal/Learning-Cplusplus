/* Program: Book Inventory Management System
 * Date: November 26, 2024
 * Programmer: Arjav Lamsal
 * Description: This program allows the user to manage a list of books by reading data from a file, 
 *              adding new books, displaying the book list, saving changes to a file, and exiting the program with an 
 *              option to save data. It handles basic book information including item number, title, retail price, 
 *              and quantity, and calculates the total retail value for all books in the list.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Book class to store information about each book
class Book {
private:
    string item_number;  // Item number for the book
    string title;        // Title of the book
    double retail_price; // Retail price of the book
    int quantity;        // Quantity of the book available

public:
    // Default constructor to initialize the book object with default values
    Book() : item_number(""), title(""), retail_price(0.0), quantity(0) {}

    // Parameterized constructor to initialize the book object with specific values
    Book(string item, string t, double price, int qty) 
        : item_number(item), title(t), retail_price(price), quantity(qty) {}

    // Setters for each property of the book
    void setItemNumber(string item) { item_number = item; }
    void setTitle(string t) { title = t; }
    void setRetailPrice(double price) { retail_price = price; }
    void setQuantity(int qty) { quantity = qty; }

    // Getters for each property of the book
    string getItemNumber() const { return item_number; }
    string getTitle() const { return title; }
    double getRetailPrice() const { return retail_price; }
    int getQuantity() const { returns quantity; }

    // Method to calculate the total retail value for the book
    double getTotalRetailValue() const {
        return retail_price * quantity;
    }
};

// Function to read books from file and populate the book_list array
void readFile(Book book_list[], int& count) {
    ifstream inFile("books.txt"); // Open the file containing book data
    string item_number, title;
    double price;
    int qty;

    // Read books from the file until EOF
    while (!inFile.eof()) {
        // Read item number and title
        if (!getline(inFile, item_number) || item_number.empty()) break;
        if (!getline(inFile, title) || title.empty()) continue;

        // Read price and quantity
        inFile >> price >> qty;
        inFile.ignore(); // Ignore leftover newline after quantity

        // Add book to the list
        book_list[count] = Book(item_number, title, price, qty);
        count++; // Increment count of books in the list
    }

    inFile.close(); // Close the input file
}

// Function to display the menu and get user choice
char getMenuChoice() {
    char choice;
    cout << "\nMain Menu\n";
    cout << "1. Add new book\n";
    cout << "2. Display all books\n";
    cout << "3. Save to file\n";
    cout << "4. Exit the program\n";
    cout << "\nEnter your choice: ";
    cin >> choice;
    cin.ignore(); // Ignore the newline character after input
    return choice;
}

// Function to add a new book to the list
void addNewBook(Book book_list[], int& count) {
    string item_number, title;
    double price;
    int qty;

    // Prompt user for book details
    cout << "\nEnter item number: ";
    getline(cin, item_number);
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter retail price: ";
    cin >> price;
    cout << "Enter quantity: ";
    cin >> qty;
    cin.ignore(); // Ignore the newline after quantity input

    // Add new book to the list
    book_list[count] = Book(item_number, title, price, qty);
    count++; // Increment the book count
}

// Function to display all books in the list
void displayBooks(const Book book_list[], int count) {
    double total_value = 0.0;

    // Print header for the book list
    cout << "\nItem\n";
    cout << "Number  Book Title                                         Price     Quantity    Total\n";
    cout << "                                                                              Retail Value\n";
    cout << "--------------------------------------------------------------------------------\n";

    // Loop through and display each book's details
    for (int i = 0; i < count; i++) {
        cout << left << setw(8) 
             << (book_list[i].getItemNumber().empty() ? "N/A" : book_list[i].getItemNumber())
             << left << setw(45) 
             << (book_list[i].getTitle().empty() ? "Untitled" : book_list[i].getTitle())
             << right << setw(8) << fixed << setprecision(2) 
             << book_list[i].getRetailPrice()
             << right << setw(10) << book_list[i].getQuantity()
             << right << setw(13) << book_list[i].getTotalRetailValue() << endl;

        total_value += book_list[i].getTotalRetailValue(); // Calculate total retail value
    }

    // Display the total retail value of all books
    cout << "\nTotal retail value of all books = $" << fixed << setprecision(2) << total_value << endl;
    cout << "\nPress ENTER to continue...";
    cin.get(); // Wait for user input before continuing
}

// Function to save the current book list to file
void saveToFile(const Book book_list[], int count) {
    ofstream outFile("books.txt"); // Open file for writing

    // Write each book's details to the file
    for (int i = 0; i < count; i++) {
        outFile << book_list[i].getItemNumber() << endl
                << book_list[i].getTitle() << endl
                << fixed << setprecision(2) << book_list[i].getRetailPrice() << endl
                << book_list[i].getQuantity() << endl;
    }

    outFile.close(); // Close the output file
}

// Function to handle program exit and optional saving of data
void exitProgram(const Book book_list[], int count) {
    char choice;
    cout << "Do you want to save the data to file? (y/n): ";
    cin >> choice;

    // Save to file if user chooses 'y'
    if (tolower(choice) == 'y') {
        saveToFile(book_list, count);
    }
}
