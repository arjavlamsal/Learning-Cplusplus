// Project name: Chapter 13 Class Example 1
// Programmer: Arjav Lamsal
// Date: Oct 28, 2024
// Description: This program uses a class called Rectangle to store the width and length of a specified number of rectangles.
// The width and length of each rectangle are read from the keyboard.
// The width, length, and area for each rectangle is then displayed on the screen.
#include <iostream>
#include <cstdlib>
using namespace std;

class Rectangle
{
private:
    double width;
    double length;

public: // Added public access specifier
    void setWidth(double width);
    void setLength(double length);
    double getWidth() const;
    double getLength() const;
    double getArea() const;
}; // Added semicolon here

// setWidth assigns a value to the width member.
void Rectangle::setWidth(double _width) {
    if (_width >= 0) {
        width = _width;
    } else {
        cout << "\nError: Invalid width.\n";
        exit(EXIT_FAILURE);
    }
}

// setLength assigns a value to the length member.
void Rectangle::setLength(double _length) {
    if (_length >= 0) {
        length = _length;
    } else {
        cout << "\nError: Invalid length.\n"; // Corrected error message
        exit(EXIT_FAILURE);
    }
}

// getWidth returns the value in the width member.
double Rectangle::getWidth() const {
    return width;
}

// getLength returns the value in the length member.
double Rectangle::getLength() const {
    return length;
}

// getArea returns the value of the rectangle's area.
double Rectangle::getArea() const {
    return length * width;
}

// Prototype Statements
void getRectangleData(Rectangle [], int);
void displayRectangleData(Rectangle [], int); // Moved this declaration up

int main() {
    /*
    Rectangle box;
    double box_width, box_length;

    // Get the rectangle's width and length from the user.
    cout << "What is the width? ";
    cin >> box_width;
    cout << "What is the length? ";
    cin >> box_length;

    // Store the width and length in the box object.
    box.setWidth(box_width);
    box.setLength(box_length);

    // Display the rectangle's data.
    cout << endl;
    cout << "Width: " << box.getWidth() << endl;
    cout << "Length: " << box.getLength() << endl;
    cout << "Area: " << box.getArea() << endl << endl;
    */
    
    const int NUM_OF_RECTANGLES = 3;
    Rectangle box_list[NUM_OF_RECTANGLES];

    getRectangleData(box_list, NUM_OF_RECTANGLES);
    displayRectangleData(box_list, NUM_OF_RECTANGLES);

    return 0;
}

// displayRectangleData displays all data in the box_list array.
void displayRectangleData(Rectangle box_list[], int array_size) {
    for (int c = 0; c < array_size; c++) {
        // Display the rectangle's data.
        cout << endl;
        cout << "Data for rectangle " << c + 1 << endl;
        cout << "  Width:  " << box_list[c].getWidth() << endl;
        cout << "  Length: " << box_list[c].getLength() << endl;
        cout << "  Area:   " << box_list[c].getArea() << endl << endl;
    }
}

// getRectangleData reads data for all rectangles.
void getRectangleData(Rectangle box_list[], int array_size) {
    double box_width, box_length;

    for (int c = 0; c < array_size; c++) {
        // Get the rectangle's width and length from the user.
        cout << "What is the width for rectangle " << c + 1 << "? ";
        cin >> box_width;
        cout << "What is the length for rectangle " << c + 1 << "? ";
        cin >> box_length;
        cout << endl;

        // Store the width and length in the box object.
        box_list[c].setWidth(box_width);
        box_list[c].setLength(box_length);
    }
}
