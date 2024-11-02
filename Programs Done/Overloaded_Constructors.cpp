#include <iostream>

/* Overleaded Constructors   =  Multiple constructors w/ same name but different parameters.
                                Allows for varying arguments while instantiating an object.
*/

class Pizza {
    public:
        std::string topping1;
        std::string topping2;

    // Constructor1 with 0 or no parameters.
    Pizza(){}

    // Constructor2 with 1 parameter.
    Pizza(std::string topping1){
        this->topping1 = topping1;
    }
    
    // Constructor3 with 2 parameters.
    Pizza(std::string topping1, std::string topping2){
        this->topping1 = topping1;
        this->topping2 = topping2;
    }

};


int main(){
    Pizza pizza1(); // Object1 with no arguments.
    Pizza pizza2("top1");   // Object2 with 1 argument.
    Pizza pizza3("top1", "top2");   // Object3 with 2 arguments.

    std::cout << pizza2.topping1 << '\n' << pizza3.topping2 << std::endl;
    
    return 0;
}