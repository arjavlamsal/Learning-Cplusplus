#include <iostream>

/*  Dynamic Memory  =   Memory that is allocated after the program is already compiled and running.
                        Use the 'new' operator to allocate dynamic memory in the heap rather than traditionally in the stack.
                        Use the 'delete' operator to free-up memory in the heap when no longer using it. 
                        If not deleted, might cause a memory leak.

                        Useful when we don't know how much memory we will need. Makes our program more flexible.
                        Especially when accepting user input.
*/ 

int main(){

// For Dynamic Variables:

    int *p_num = NULL;  // Setting a null pointer.
    p_num = new int;    // Using the new keyword, now, p_num is pointing to the new allocated memory address in the heap.
    *p_num = 21;    // Now the value 21 is stored in a memory address in the heap.

    std::cout << "\nAddress in the heap = " << p_num << '\n';
    std::cout << "Value in that address in the heap = " << *p_num;

    delete p_num; // Deleting the memory allocated in the heap.


// For Dynamic Arrays:

    char *p_grades = NULL; // Creating a null pointer.
    int size;   // For the size of the dynamic array as per the user's will.

    std::cout << "Enter the number of characters you will enter = ";
    std::cin >> size;

    p_grades = new char[size]; // Allocating memory in the heap with 'new char [size]'

    for (int i = 0; i < size; i++){
        std::cout << "\nEnter the grades = " << '\n';
        std::cin >> p_grades[i];    // Adding values to the array in the heap.

        std::cout << p_grades[i] << '\n';   // Displaying the item that is added to the array in the heap.
    }

    delete[] p_grades; // Deleting the array from the heap.

    return 0;
}