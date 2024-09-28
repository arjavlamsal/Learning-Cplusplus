// Detecting End-of-File (EOF) while reading from a file
#include <iostream>
#include <fstream> 

using namespace std;

int main(){

    ifstream file;
    file.open("Text.txt");

    string value;

// Reading entire line - using getline(filename,value);

    while(file >> value){ // If there are no lines left and file object has no value to take then the loop stops.
        getline(file, value);
        cout << value << endl;
    }
    

    file.close();

    return 0;
}