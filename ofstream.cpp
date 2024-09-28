// Writing to a file
#include <iostream>
#include <fstream> // For file handling operation (ofstream)

using namespace std;

int main(){
    ofstream file; // Initialize which file object for writing
    file.open("Text.txt"); // Open file for manipulation

    file << "Arjav Lamsal \n" << "Amrita Lamsal \n" << "Hari Lamsal \n" << endl;
    file.close();

    return 0;
}