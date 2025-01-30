#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float grade_input;
    float grade_total = 0;
    int num_grades = 0;
    float average_grade;

    // Adding cin inside the do-while loop to get the effect of inputting in a single line. Eg: (50 60 70 80 -1)
    cout << "Enter the grade: ";
    do {
        cin >> grade_input;
        
        grade_total += grade_input;
        num_grades++;
    } while (grade_input != -1);
    
    average_grade = float(grade_total) / num_grades;
    cout << "The average grade is: " << fixed << setprecision(2) << average_grade << endl;

    if (average_grade > 59.0) {
        cout << "The student passed the course." << endl;
    } else {
        cout << "The student failed the course." << endl;
    }

    return 0;
}