// Program name: Chapter 8 Example Assignment
// Programmer: Arjav Lamsal (w10195547)
// Creation Date: 09-10-2024
// Description: This program reads data from a text file called books.txt and stores the
// data in three parallel arrays, item_number, title, and retail_price. This program will
// then ask the user to enter an item number. A search algorithm will be used to find the
// item number in the item_number array. If it is found, the data for that book will be
// displayed on the screen; otherwise, a not found message will be displayed.

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Prototype statements.
void getData(string, string[], string[], double[] );
int linearSearch(string[], int, string );
void displayResults(string [], string [], double [], int );
int binarySearch(const string [], int, string );


// Main function.
int main() {

    system("color f0");

    // Declare constant.
    const int MAXIMUM_NUMBER_OF_BOOKS = 400;

    // Declare variables.
    string filename = "books.txt";
    string item_number[MAXIMUM_NUMBER_OF_BOOKS], title[MAXIMUM_NUMBER_OF_BOOKS];
    double retail_price[MAXIMUM_NUMBER_OF_BOOKS];
    string itemNumber;
    int number_of_books;


    // Read from text file and store the data in the parallel arrays.
    getData(filename, item_number, title, retail_price);

    do {
    system("cls");
    cout << "Enter item number (or q to quit): ";
    getline(cin, itemNumber);

    if (itemNumber != "q" && itemNumber != "Q") 
    {

        // Call the linear search function.
        // int position = linearSearch(item_number, MAXIMUM_NUMBER_OF_BOOKS, itemNumber);

        // Call the binary search function.
        int position = binarySearch(item_number, MAXIMUM_NUMBER_OF_BOOKS, itemNumber);

        if (position >= 0) {
        // Display the results of the search.
        displayResults(item_number, title, retail_price, position);
        } else {
        cout << "Item number not found.\n\n";
        }

        system("pause");
    }
    } while (itemNumber != "q" && itemNumber != "Q"); // Loop until user enters "q" or "Q".

    return 0;
}



// This function displays the results on the screen.

void displayResults(string item_number[], string title[], double retail_price[], int position) 
{
  cout << setprecision(2) << fixed;
  cout << "\nItem number: " << item_number[position] << endl;
  cout << "Book title: " << title[position] << endl;
  cout << "Retail price: $" << retail_price[position] << endl << endl;
}



// This function performs a linear search for value on the string array array[].

int linearSearch(string array[], int size, string value) 
{
  for (int index = 0; index < size; index++) {
    if (array[index] == value) {
      return index;
    }
  }

  return -1;
}



// This function performs a binary search for value on the string array array[].

int binarySearch(const string array[], int array_size, string value) 
{
  int first = 0, last = array_size - 1, middle;

  while (first <= last) {
    middle = (first + last) / 2;

    if (array[middle] == value) {
      return middle;
    } else if (array[middle] < value) {
      first = middle + 1;
    } else {
      last = middle - 1;
    }
  }

  return -1;
}



// This function reads all data from the text file and stores the data in parellel arrays.

void getData(string filename, string item_number[], string title[], double retail_price[], int &number_of_books) 
{
  ifstream inputFile;
  inputFile.open(filename.c_str());

  if (inputFile.fail()) {
    cout << "\nError reading file....\n\n";
    system("pause");
    return;
  }

  string line;
  int index = 0;

  while (getline(inputFile, item_number[index])) {
    getline(inputFile, title[index]);
    getline(inputFile, line);
    retail_price[index] = atof(line.c_str());
    getline(inputFile, line);
    index++;
  }

  inputFile.close();
  number_of_books = index;
}