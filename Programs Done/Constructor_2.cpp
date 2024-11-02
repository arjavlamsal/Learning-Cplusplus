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

    Car (std::string x, std::string y, int z){  // Different Variable is easier.
        name = x;  // If Attribute names != Parameter names, 'this->var' is not necesary! 
        color = y;
        milage = z;
    }
};

int main()
{
    Car ford("figo", "white", 500); // Passing arguments in (paranthesis) to the class blueprint.
    ford.runEngine(); // Calling methods.
    ford.stopEngine();

    std::cout << ford.name << " " << ford.color << std::endl; 


    return 0;
}