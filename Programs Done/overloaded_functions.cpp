#include <iostream>
// Overloaded Functions
// Function names can be the same but the Function Signtures must be different.
// Function Signature is ddefinition Function name + Parameters.

// Function Declarations
void bakePizza();
void bakePizza(std::string topping1);
void bakePizza(std::string topping1, std::string topping2);

int main(){ // Main Function

    std::string topping1 = "Pepperoni";
    std::string topping2 = "Cheese";

    bakePizza();
    // Overloaded Function Calls
    bakePizza(topping1);
    bakePizza(topping1,topping2);
}


void bakePizza(){
    std::cout << "Pizza is ready! \n";
}

// Overloaded Function 1
void bakePizza(std::string topping1){
    std::cout << "Pizza with " << topping1 << " is ready! \n";
}

// Overloaded Function 2
void bakePizza(std::string topping1, std::string topping2){
    std::cout << "Pizza with " << topping1 << " and " << topping2 << " is ready! \n";
}