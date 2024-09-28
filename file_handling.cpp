#include <iostream>
#include <fstream> // For file handling operations (ofstream & ifstream)

using namespace std;

int main(){
    ofstream file1; // Initialize which file object for writing
    file1.open("Text.txt"); // Open file for manipulation

    file1 << "Arjav Lamsal \n" << "Amrita Lamsal \n" << "Hari Lamsal \n" << endl;

    file1.close();

    return 0;
}