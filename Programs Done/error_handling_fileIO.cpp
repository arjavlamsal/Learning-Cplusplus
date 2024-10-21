// Error Handling in FileIO.

#include <iostream>
#include <fstream> 

using namespace std;

int main(){

    ifstream file;
    file.open("Tet.txt");

    string value;

    if (file.fail()){   // .fail() method helps to manage error if file cannot be accessed.
        cout << "File failed to get.";
    } 
    else {
        while(file >> value){ 
            getline(file, value);
            cout << value << endl;
        }
    }
    file.close();

    return 0;
}