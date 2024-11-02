/* Function Templates = Describes what a function looks like.
                        Can be used to generate as many overloaded functions 
                        as needed, each using different data-types.
*/

#include <iostream>

template <typename T, typename U>   // Creating a function template.

T max(T x, U y){    // Function 'max' takes arguments of type T and U and returns of type T (can also be U or auto as needed).
    return (x > y) ? x : y;
}


int main(){

    std::cout << max(3.2,3);
    
    return 0;
}

