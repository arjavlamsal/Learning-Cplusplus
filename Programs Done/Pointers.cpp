/* Pointers  =  Variables that store the memory address of other variables. 
                Sometimes easier to work with an address.

                & - Address-of operator
                * - Dereference operator
*/

#include <iostream>

int main() {
    std::string name = "Arjav";
    int age = 20;
    std::string pizza[5] = {"Pizza1", "Pizza2", "Pizza3", "Pizza4", "Pizza5"};

    std::string *p_name = &name; // Here p_name is now a pointer to name variable and stores its memory address.
    int *p_age = &age; // Here p_age is now a pointer to name variable and stores its memory address.
    std::string *p_pizza = pizza; // This is different as an Array already is a memory address, so doesn't need address-of (&) operator for creating pointers.


    std::cout << p_name << '\n'; // This gives the stored memory address.
    std::cout << *p_name << '\n'; // This gives the value stored at that memory address (Also known as dereferencing).

    std::cout << '\n';

    std::cout << p_age << '\n'; // This gives the stored memory address.
    std::cout << *p_age << '\n'; // This gives the value stored at that memory address.

    std::cout << '\n';

// For Arrays:
    std::cout << pizza << '\n'; // Same as(std::cout << &pizza << '\n';). It gives the stored memory address.
    std::cout << *p_pizza << '\n'; // This gives the first value stored int the array at that memory address.

    return 0;
}


