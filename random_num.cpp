#include <iostream>

int main(){

    // Not truely random but close

    // Will have to put in seed for random number or won't work
    srand(time(NULL));

    int num1 = (rand() % 20) + 1;
    int num2 = (rand() % 20) + 1;
    int num3 = (rand() % 20) + 1;



    std::cout << num1;


    return 0;
}