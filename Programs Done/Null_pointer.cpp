#include <iostream>

/* Null Pointer  :  A special value that means that something has no value. 
                    When a Pointer is holding a Null value, that pointer is not pointing to anything.
    
    nullptr = keyword represents a null pointer literal.

    - nullptrs are helpful when determining if an address was successfully assigned to a pointer.

    When using pointers, be careful that your isn't dereferencing null or pointing to free memory.
    This will cause undefined behaviour.
*/

int main() {

    int *p_age = nullptr;
    
    int age = 50;
    // p_age = &age;

    if (p_age == nullptr){
        std::cout << "Pointer is still of type null !!!, Change it ASAP.";
    }
    else {
        std::cout << "Pointer is pointing to some memory address...";
        std::cout << *p_age;
    }

    return 0;
}