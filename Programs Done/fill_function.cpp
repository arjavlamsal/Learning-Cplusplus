// fill() function to initialize an array. fill(begin, end, value)
#include <iostream>

int main(){
    const int SIZE = 99;
    std::string array[SIZE];

// For the initialization of the whole array.
    // fill(array, array + SIZE, "pizza"); // starting address is the name of the array "array" and ending is upto array + size 

// Filling an array in 3 divisions.
    // First 1/3 part.
    fill(array, array + SIZE/3, "a");
    // Second 1/3 part.
    fill(array + SIZE/3, array + SIZE/3 * 2, "b");
    // Third 1/3 part.
    fill(array + SIZE/3 * 2, array + SIZE, "c");


    for (std::string item : array){
        std::cout << item << '\n';
    }
    
    return 0;
}