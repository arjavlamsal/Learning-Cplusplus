#include <iostream>

// switch = alternative to using many 'else if' statements, compare one value against matching cases. 
int main(){
    using namespace std;

    // int month;
    // cout << "Enter month index = ";
    // cin >> month;

    // switch(month){
    //     case 1:
    //         cout << "Jan";
    //         break;

    //     case 2:
    //         cout << "Feb";
    //         break;

    //     case 3:
    //         cout << "Apr";
    //         break;

    //     default:
    //         cout << "please enter in numbers only 1-3";
    // }

    char grade;
    cout << "Enter your grade = ";
    cin >> grade;

    switch(grade){
        case 'A':
            cout << "You did great!";
            break;
        case 'B':
            cout << "You did good!";
            break;
        default:
            cout << "Please enter validd grade";  
    }

    return 0;
}