// Chapter 13 Example 2
// Date: 11-04-2024
// Programmer: Arjav Lamsal
// Description: This program uses Object Oriented Programming to take data from users on the number of rooms 
//              and the size of the rooms and then calculates the area of multiple rooms in a house and displays them.

#include <iostream>
#include <cstdlib>
using namespace std;

// Rectangle class declaration.
class Rectangle {
    private:
        double width;
        double length;

    public:
        Rectangle();    // Default Constructor
        Rectangle(double , double );    // Constructor #1.
        void setWidth(double );
        void setLength(double );
        double getWidth() const;
        double getLength() const;
        double getArea() const;
        void print() const;
};

// Default Constructor.
Rectangle::Rectangle()
{
    width = 0;
    length = 0;

}

// Full Constructor.
Rectangle::Rectangle(double _width, double _length)
{
    width = _width;
    length = _length;
}

// setWidth Assigns a value to the width member.
void Rectangle::setWidth(double _width){
    if (_width >= 0){
        width = _width;
    }
    else{
        cout << "\nError: Invalid Width!" << endl;
        exit(EXIT_FAILURE);
    }
}


//setLength Assigns a value to the length member.
void Rectangle::setLength(double _length){
    if (_length >= 0){
        length = _length;
    }
    else{
        cout << "\nError: Invalid Width!" << endl;
        exit(EXIT_FAILURE);
    }
}



//getWidth() Gets the Width from the user.
double Rectangle::getWidth() const{
    return width;
}


//getLength() Gets the Length from the user.
double Rectangle::getLength() const{
    return length;
}


// getArea Returns the area of the rectangle.
double Rectangle::getArea() const
{
    return length * width;
}

void Rectangle::print() const {
    // Display the rectangle's data.
    cout << endl;
    cout << "Width  =  " << getWidth() << endl 
         << "Length =  " << getLength() << endl
         << "Area   =  " << getArea() << endl << endl;
}

// MAIN
// Prototype Statements.
void getData(Rectangle [], int &);
void displayResults(Rectangle [], int );

const int MAX_ROOMS = 100;


int main()
{
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
    cout << "Width:  " << box.getWidth() << endl;
    cout << "Length: " << box.getLength() << endl;
    cout << "Area:   " << box.getArea() << endl << endl;

  
    const int NUMBER_OF_RECTANGLES = 3;
    Rectangle box_list[NUMBER_OF_RECTANGLES];

    getRectangleData(box_list, NUMBER_OF_RECTANGLES);
    displayRectangleData(box_list, NUMBER_OF_RECTANGLES);
*/

    Rectangle room_array[MAX_ROOMS];
    int number_of_rooms = 0;
    getData(room_array, number_of_rooms);
    displayResults(room_array, number_of_rooms);
}


// Function getData: This function reads the width and length from the keyboard for each room.
void getData(Rectangle room_array[], int &number_of_rooms)
{
    double room_width, room_length;

    cout << "How many rooms does this house have? = ";
    cin >> number_of_rooms;

    for(int room = 0; room < number_of_rooms; room++)
    {
        // Get the room's width and length from the header.
        cout << "\nRoom " << room + 1 << endl;


        cout << "   Width: ";
        cin >> room_width;

        cout << "   Length: ";
        cin >> room_length;

        // Create a Rectangle Object.
        Rectangle new_room(room_width, room_length);

        // Store the Rectangle Object in the room_array.
        room_array[room] = new_room;
    }
}


void displayResults(Rectangle room_array[], int number_of_rooms)
{
    double total_square_feet = 0;

    for (int room = 0; room < number_of_rooms; room++)
    {
        cout << "\nroom #" << room + 1;
        room_array[room].print();

        // Add Area to total_square_feet.
        total_square_feet += room_array[room].getArea();

    }
    cout << "Total Square Feet = " << total_square_feet << " sq.ft.\n" << endl;
}
