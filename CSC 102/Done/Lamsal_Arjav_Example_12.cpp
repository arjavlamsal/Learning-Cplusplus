// Program: Chapter 12 Example
// Programmer: Arjav Lamsal
// Date: 20th October, 2024

// Description: This program demonstrates the following:
//              * how to use the fstream data type to open a file for output, input, or append.
//              * how to use the get function to read one character from a text file.
//              * how to use the put function to write one character to a text file.
//              * how to create a binary file.
//              * how to write data to a binary file.
//              * how to read data from a binary file.

#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

using namespace std;

const int NAME_SIZE = 51;

struct Info {
    char name[NAME_SIZE];
    int ID_Number;
};

void displayTextFileContents(fstream&, string);
void writeCharactersToFile(string, string);
void writeToBinaryFile(string);
void readFromBinaryFile(string);


int main()
{

	// **************************************************************
	//    Part 1: Open a text file for output, input, and append.
	// **************************************************************
    string name, filename = "names.txt";
    fstream dataFile;

    // Read names from the keyboard and write them to names.txt.
    dataFile.open(filename.c_str(), ios::out); // Open file for output.

    cout << "Enter names or Q to quit.\n";
    getline(cin, name);

    while (name != "Q" && name != "q") {
        dataFile << name << endl;
        getline(cin, name);
    }

    dataFile.close();

    displayTextFileContents(dataFile, filename); // Display the file contents.

    // Read names from the keyboard and append them to names.txt.

    dataFile.open(filename.c_str(), ios::out | ios::app); // Open file for append.

    cout << "Enter names or Q to quit.\n";
    getline(cin, name);

    while (name != "Q" && name != "q") {
        dataFile << name << endl;
        getline(cin, name);
    }

    dataFile.close();

    displayTextFileContents(dataFile, filename); // Display the file contents.
        
    // **************************************************************
    // Part 2: get and put functions. 
    // get reads one character from a text file. 
    // put writes one character to a text file.
    // **************************************************************
        string filename2 = "names2.txt";
        writeCharactersToFile(filename, filename2);
        displayTextFileContents(dataFile, filename2);

	// **************************************************************
	//    Part 3: Binary files
	// **************************************************************	
		string filename3 = "people.dat";
        writeToBinaryFile(filename3);
        readFromBinaryFile(filename3);

	return 0;
}

// **************************************************************************
//  Function readFromBinaryFile: This function reads objects of the Info data 
//  type from a binary file and displays the data on the screen.
// **************************************************************************
void readFromBinaryFile(string filename) {
    Info person; // To hold info about a person.

    fstream people(filename.c_str(), ios::in | ios::binary); // Open file for input in binary mode.

    people.read(reinterpret_cast<char *>(&person), sizeof(person)); // Read the first record from the file.

    cout << endl << left << setw(20) << "Name" << endl
         << left << setw(10) << "ID Number" << endl
         << "-------------------------\n"; // Display column headings.

    while (!people.eof()) { // While not end of file, display next record.
        cout << left << setw(20) << person.name
             << left << setw(10) << person.ID_Number << endl; // Display the record.

        people.read(reinterpret_cast<char *>(&person), sizeof(person)); // Read the next record from the file.
    }

    people.close(); // Close the file.
}


// **************************************************************************
//  Function writeToBinaryFile: This function writes data records of the Info
//  data type to a binary file.
// **************************************************************************
void writeToBinaryFile(string filename) {
    Info person; // To hold info about a person
    char again; // To hold Y or N

    fstream people(filename.c_str(), ios::out | ios::binary); // Open file for output in binary mode.

    do {
        cout << "\nEnter name: "; // Read name.
        cin.getline(person.name, NAME_SIZE);

        cout << "Enter ID Number: "; // Read ID Number.
        cin >> person.ID_Number;

        cin.ignore(); // Skip over the remaining newline.

        people.write(reinterpret_cast<char *>(&person), sizeof(person)); // Write the record to the file.

        do {
            cout << "Do you want to enter another record? "; // Ask user to enter another record.
            cin >> again;

            cin.ignore(); // Skip over the remaining newline.
        } while (toupper(again) != 'Y' && toupper(again) != 'N');
    } while (again == 'Y' || again == 'y');

    people.close(); // Close the file.
}


// **************************************************************************
// Function writeCharactersToFile: This function opens filename1 for input
// and opens filename2 for output. This function then uses the get function to
// read each character from filename1 and uses the put function to write the
// upper case of the character just read to filename2.
// **************************************************************************
void writeCharactersToFile(string filename1, string filename2) {
    fstream dataFile1;
    dataFile1.open(filename1.c_str(), ios::in);

    fstream dataFile2;
    dataFile2.open(filename2.c_str(), ios::out);

    char ch;
    while (dataFile1.get(ch)) {
        dataFile2.put(toupper(ch));
    }

    dataFile1.close();
    dataFile2.close();
}



// **************************************************************************
// Function displayTextFileContents: This function opens dataFile for input, 
// reads the contents of dataFile, and displays the contents on the screen.
// **************************************************************************
void displayTextFileContents(fstream& dataFile, string filename) {
    // Open file for reading.
    dataFile.open(filename.c_str(), ios::in);
    
    // Check if file was opened successfully.
    if (!dataFile) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    cout << "\nContents of " << filename << ":\n";
    // Read file line by line and display.
    while (getline(dataFile, line)) {
        cout << line << endl;
    }

    // Close the file after reading.
    dataFile.close();
}
