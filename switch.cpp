#include <iostream>
// switch = alternative to using many 'else if' statements, compare one value against matching cases. 
int main(){
    using namespace std;

    int month;
    cout << "Enter month index = ";
    cin >> month;

    switch(month){
        case 1:
        cout << "Jan";
        break;

        case 2:
        cout << "Feb";
        break;

        case 3:
        cout << "Apr";
        break;
    }

    return 0;
}