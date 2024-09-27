// Passing an array into a function
// When an array is passed into a function, it decays into a pointer which points the memory address to where the array begins
// This means that the function would have no idea what the size of the array is. So, we also need to pass the size of the
// array to the function. This should be done in both declaration and definition.

#include <iostream>

// Function declaration
double getTotal(double prices[], int size);

int main()
{
    double prices[] = {10.1, 20.2, 40.3, 40.4};
    int size = sizeof(prices)/sizeof(prices[0]); // length / size of the array
    double total = getTotal(prices, size);  // passing both array and its size/length as arguments
    std::cout << "total price = " << total << std::endl;

    return 0;
}

double getTotal(double prices[], int size)
{
    double total = 0;
    for(int i = 0; i < size; i++){ // iterating through using size
        total += prices[i];
    } 
    return total;
}