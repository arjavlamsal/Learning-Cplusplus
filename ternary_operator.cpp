//ternary operator '? :' = replacement to an if/else statement
//condition ? expression1 : expression2;
#include <iostream>

int main(){
    using namespace std;
    
    int marks = 60;
    marks <= 40 ? cout << "You failed" << '\n': cout << "You passed" << '\n';

    char grade = 'A';
    // grade == 'A' ? cout << "You did great!" : cout << "You did good!";

    // Also can be written as
    cout << (grade == 'A' ? "You did great!" : "You did good!") << '\n';


    bool hungry = true;
    hungry ? cout << "Hungry" : cout << "Full";
    


    return 0;
}