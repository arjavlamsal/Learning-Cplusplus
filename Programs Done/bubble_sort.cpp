// Bubble Sort

#include <iostream>

// Function declaration
void bubbleSort(int array[], int size);

// Main
int main(){

    int array[] = {10,9,8,7,6,5,4,3,2,1};
    int size = sizeof(array)/sizeof(array[0]);
    bubbleSort(array, size);
    
    for(int item : array){
        std::cout << item << ' ';
    }

    return 0;
}

void bubbleSort(int array[], int size){ // void as does not return anything explicitly
    int temp;
    for(int i = 0; i < size - 1; i++){ // i < size-1 because don't have to take the last element to compare with a element after it as there is none.
        for (int j = 0; j < size - i - 1; j++){ // j < size-i-1 because we don't need to sort already sorted elements to the right.
            if (array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

}
