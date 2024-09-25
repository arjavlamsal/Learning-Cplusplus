#include <iostream>
// Array in C++
// sizeof() operator to determine the size of a variable, dataset...

using namespace std;

int main() {

    int numbers[] = {10, 20, 30, 40, 50};

    // Calculate and print the size of the array using sizeof
    int arraySize = sizeof(numbers) / sizeof(numbers[0]);
    cout << "Array size: " << arraySize << endl;

    // Loop through the array using a for loop
    for (int i = 0; i < arraySize; i++) {
        cout << "Element " << i << ": " << numbers[i] << endl;
    }

    // Loop through the array using a while loop
    int index = 0;
    while (index < arraySize) {
        cout << "Element " << index << ": " << numbers[index] << endl;
        index++;
    }

    // Loop through the array using a do-while loop
    int counter = 0;
    do {
        cout << "Element " << counter << ": " << numbers[counter] << endl;
        counter++;
    } while (counter < arraySize);

    return 0;
}
