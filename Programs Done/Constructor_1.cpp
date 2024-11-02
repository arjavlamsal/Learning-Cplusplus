/* Constructors in C++ =    Special Method that is automatically called when an object of the class is instantiated.
                            Useful for assigning values to attributes as arguments. */

#include <iostream>

class Car {
    public: // Setting access restrictions. (Encapsulation)
        std::string name;
        std::string color;
        int milage;

        void runEngine(){
            std::cout << "Engine ON!\n";
        }

        void stopEngine(){
            std::cout << "Engine OFF!\n";
        }

    Car (std::string name, std::string color, int milage){  // Constructor that is called on initializing an object.
        this->name = name;  // For the same name variable 'this->variable = variable;' is used.
        this->color = color;
        this->milage = milage;
    }
};

int main()
{
    Car ford("figo", "white", 500);
    ford.runEngine();
    ford.stopEngine();

    std::cout << ford.name << " " << ford.color << std::endl;


    return 0;
}