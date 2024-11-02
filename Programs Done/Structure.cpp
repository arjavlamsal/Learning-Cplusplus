/* Struct = A structure that groups related variables under one name.
            - Structs can contain many different datatypes (strings, int, float, bool, etc).
            - Variables in a struct are known as "Members".
            - Members can be accessed with "Class Member Access Operator".
*/

#include <iostream>

struct Car{ // Structure datatype
    int number_plate;   // Members of the struct
    std::string color;
    double milage;
    bool is_working = true;
};

int main(){
    Car mercedes;   // Instantiation of object mercedes of Car datatype.
    mercedes.color = "White";   // Storage in members of the struct datatype.
    mercedes.milage = 123.321;
    mercedes.number_plate = 111;

    std::cout << mercedes.color;   

    return 0;
}