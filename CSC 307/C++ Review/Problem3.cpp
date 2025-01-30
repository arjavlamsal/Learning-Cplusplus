#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

// Function prototypes
vector<double> readGradesFromFile(string filename);
double computeAverage(string filename);
char computeLetterGrade(double average);


int main() {
    double average = computeAverage("grades.txt");
    char letterGrade = computeLetterGrade(average);
    cout << "The average grade is " << average;
    cout << " which is a \'" << letterGrade << "'" << endl;
   
    return 0;
}


vector<double> readGradesFromFile(string filename) {
    ifstream file;  // This file object is like a string.
    file.open(filename);
    vector<double> data;

    string line;
    while (getline(file, line)) {
        data.push_back(stod(line));
    }
    file.close();
    return data;
}

double computeAverage(string filename) {
    vector<double> grades = readGradesFromFile(filename);
    double sum = 0;
    for (int i = 0; i < grades.size(); i++) {
        sum += grades[i];
    }
    return sum / grades.size();
}

char computeLetterGrade(double average) {
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'F';
    } 
}