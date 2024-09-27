// Linear Search

#include <iostream>

// Function declaration
int linearSearch(std::string array[], int size, std::string usr_in);


int main(){
    std::string attendance[] = {"arjav", "renasha", "papa", "mamu"};
    int size = sizeof(attendance)/sizeof(attendance[0]);
    std::string usr_in;

    std::cout << "What do you want to check in the list = " << std::endl;
    std::cin >> usr_in;

    int index = linearSearch(attendance, size, usr_in);

    if (index != -1){
        std::cout << "Item is at index = " << index << std::endl;
    } else {
        std::cout << "Not in the array" << std::endl;
        
    }
    return 0;
}

int linearSearch(std::string array[], int size, std::string usr_in){

    for (int i = 0; i < size; i++){
        if (array[i] == usr_in){
            return i;
        }
    }
    return -1;  // If function does not return anything, at last return -1, which means that the hoped result is not found.
}


