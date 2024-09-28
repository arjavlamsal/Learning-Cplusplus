// Static Variable
// A static variable is not destroyed when a function completes execution unlike other variables, they exist for the lifetime
// of the program.
// Their scope is only within the function they are declared.
#include <iostream>

using namespace std;

void showStatic(); // Function prototype

int main() {
    // Call the showStatic function five times.
    for (int count = 0; count < 3; count++) {
        showStatic();
    }

    return 0;
}

void showStatic() {
    static int statNum = 5; // Declaration of static int statNum.

    cout << "statNum is " << statNum << endl;
    statNum++; // This adds +1 to the state of statNum preserved due to the previous iteration.
}