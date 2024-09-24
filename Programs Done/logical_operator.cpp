#include <iostream>

int main(){
    using namespace std;
    int temp;

    cout << "Temperature = " << endl;
    cin >> temp;

    // && - 'and' operator
    if (temp <= 0 && temp >= -50){
        cout << "Very cold";
    }
    else {
        cout << "Hot";
    }

    cout << '\n';

    bool sunny = false;
    // Bool
    if (sunny){
        cout << "Sunny too";
    }
    // || - 'or' and ! - 'not' operators
    else if (temp < 0 || !sunny){
        cout << "Not sunny and not funny";
    }



    return 0;
}