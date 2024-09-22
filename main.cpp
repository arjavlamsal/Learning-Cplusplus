#include <iostream>

int main(){
    
    int rows;
    int columns;
    char symbol;

    std::cout << "#rows = ";
    std::cin >> rows;

    std::cout << "#columns = ";
    std::cin >> columns;

    std::cout << "?symbol = ";
    std::cin >> symbol;

    for (int i = 0; i <= rows; i++){
        for (int j = 0; j <= columns; j++){
            std::cout << symbol << " ";
        }
        std::cout << '\n';
    }
        
// hehe

    return 0;
}