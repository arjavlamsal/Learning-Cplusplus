#include <iostream>
// Functions are used as reusable code-blocks.

void customerDetails(std::string name , int age); // Function Declaration


int main(){ // Main Function

    std::string name = "Arjav";
    int age = 19;

    customerDetails(name, age); // Calling the other function.
}


void customerDetails(std::string name, int age){ // Function Definition
    std::cout << "Hello " << name << " ! \n" << "Congrats on being " << age << "!";
}