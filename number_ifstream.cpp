// Reading numbers from a file
#include <iostream>
#include <fstream> // For file handling operation (ifstream)
#include <iomanip>

using namespace std;

int main(){

    ifstream file;
    file.open("numbers.txt");

    int value;
    const int ROWS = 6;
    const int COLUMNS = 4;


for (int i = 0; i < ROWS; i++){
    for (int j = 0; j < COLUMNS; j++){
        file >> value;
        std::cout << setw(10) << value;
    }
    std::cout << std::endl;
    file.close();

    return 0;
}


    file.close();

    return 0;
}