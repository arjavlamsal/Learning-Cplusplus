// Reading from a file
#include <iostream>
#include <fstream> // For file handling operation (ifstream)

using namespace std;

int main(){

    ifstream file;
    file.open("Text.txt");

    string value;

/* // Reading words in the file
    file >> value;
    cout << value << endl;

    file >> value;
    cout << value << endl;

    file >> value;
    cout << value << endl;
*/

// Reading entire line - using getline(filename,value);

    getline(file, value);
    cout << value << endl;

    getline(file, value);
    cout << value << endl;


    file.close();

    return 0;
}