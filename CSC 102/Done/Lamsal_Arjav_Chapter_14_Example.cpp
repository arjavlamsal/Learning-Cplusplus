// Program: Chapter 14 Example
// Programmar: Arjav Lamsal
// Date: 11/11/2024
// Description: This program stores and displays information about a college course,
//              ncluding course name, number of students, and details about each student.

#include <iostream>
#include <string>

using namespace std;

// *************************************************************
// Status class
// *************************************************************
class Status {
private:
    int classification; // 1, 2, 3, 4, 6 (graduate student)
    double GPA;

public:
    // Default constructor
    Status() {
        set(0, 0);
    }

    // Full constructor
    Status(int _classification, double _GPA) {
        set(_classification, _GPA);
    }

    // Setter for classification and GPA
    void set(int, double);

    // Setters for classification and GPA individually
    void set_classification(int _classification) {
        classification = _classification;
    }

    void set_GPA(double _GPA) {
        GPA = _GPA;
    }

    // Print function
    void print() const;
};

void Status::set(int _classification, double _GPA) {
    classification = _classification;
    GPA = _GPA;
}

void Status::print() const {
    cout << "Classification:        " << classification << endl
         << "GPA:                   " << GPA << endl;
}

// *************************************************************
// Student class
// *************************************************************
class Student {
private:
    string name;
    Status student_status;
    static int number_of_students;
    static string course_name;

public:
    // Default constructor
    Student() {
        set("", 0, 0);
    }

    // Full constructor
    Student(string _name, int _classification, double _GPA) {
        set(_name, _classification, _GPA);
    }

    // Copy constructor
    Student(const Student &obj);

    int get_number_of_students() const {
        return number_of_students;
    }

    // Setters for name, classification, and GPA
    void set_name(string _name) {
        name = _name;
    }

    void set_classification(int _classification) {
        student_status.set_classification(_classification);
    }

    void set_GPA(double _GPA) {
        student_status.set_GPA(_GPA);
    }

    static void set_course_name(string _course_name) {
        course_name = _course_name;
    }

    string get_course_name() const {
        return course_name;
    }

    void set(string, int, double);
    void print() const;
};

// Initialize static members
int Student::number_of_students = 0;
string Student::course_name = "";

void Student::set(string _name, int _classification, double _GPA) {
    name = _name;
    student_status.set(_classification, _GPA);
    number_of_students++;
}

// Copy constructor
Student::Student(const Student &obj) {
    name = obj.name;
    student_status = obj.student_status;
    number_of_students++;
}

void Student::print() const {
    cout << "Name: " << name << endl;
    student_status.print();
    cout << endl;
}

// *************************************************************
//          MAIN
// *************************************************************
int main() {
    system("color f0");

    Student::set_course_name("CSC 102 C++ Programming");

    Student student1("John Smith", 3, 3.8);
    Student student2("Olivia Jones", 2, 3.2);

    Student student3 = student1;

    student3.set_name("Ed Hayes");
    student3.set_classification(6);
    student3.set_GPA(3.9);

    Student student4("Beth Adams", 6, 4.0);
    student4 = student1; // Memberwise assignment

    student1.print();
    student2.print();
    student3.print();
    student4.print();

    cout << "Number of Students:    " << student1.get_number_of_students() << endl;
    cout << "Course Name:           " << student1.get_course_name() << endl;

    return 0;
}
