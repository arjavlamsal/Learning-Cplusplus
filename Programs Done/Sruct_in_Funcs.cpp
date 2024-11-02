/* Passing Structs into Functions = Structs are pass-by-value rather than pass-by-reference.
                                    So, copies of the variable is made of the struct and that is used in the function.
*/
#include <iostream>

struct Car{ 
    int number_plate;   
    std::string color;
    double milage;
};

void printCar(Car &car);
void paintCar(Car &car, std::string color);

int main(){
    Car mercedes; 
    mercedes.color = "White";   
    mercedes.milage = 123.321;
    mercedes.number_plate = 111;

    std::cout << &mercedes << '\n'; // Memory address of mercedes.

    Car bmw; 
    bmw.color = "red";   
    bmw.milage = 123.321;
    bmw.number_plate = 111;

    std::cout << &bmw << '\n'; // Memoery address where struct bmw is stored.

    printCar(mercedes);
    printCar(bmw);

    paintCar(mercedes, "green");
    paintCar(bmw, "golden");

    return 0;
}

// void printCar(Car car){ // Passing Struct as an argument in a function ( STRUCTS are PASS BY VALUE BY DEFALUT).
//     std::cout << car.color << " , " << car.milage << std::endl;
//     std::cout << &car << std::endl; // Memory address of car (struct) argument which is a different one as passed-by-value.
// }

void printCar(Car &car){ // Passing Struct as an argument in a function. ( PASSING BY REFERENCE ).
    std::cout << car.color << " , " << car.milage << std::endl;
    std::cout << &car << std::endl; 
}

void paintCar(Car &car, std::string color){
    car.color = color;
    std::cout << car.color << " , " << car.milage << std::endl;
}