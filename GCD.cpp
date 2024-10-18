// Greatest Common Divisor Finder for 2 numbers

#include <iostream>
using namespace std;

int gcd(int a, int b);

int main() {
    int a, b;
    cout << "Enter first number = ";
    cin >> a;
    cout << "Enter second number = ";
    cin >> b;

    int ans = gcd(a, b);
    cout << "The greatest common divisor is " << ans << endl;

    return 0;
}

int gcd(int a, int b) {
    int lower_val = min(a, b);
    for (int i = lower_val; i >= 1; i--) {
        if ((a % i == 0) && (b % i == 0)) {
            return i;
        }
    }
    return 0; // If no common divisor is found, return 0
}