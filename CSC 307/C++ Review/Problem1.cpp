#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double manufacturerPrice;
    double finalPrice;
    double markupPercentage = 1.35;

    cout << "Enter the manufacturer's price of the item: ";
    cin >> manufacturerPrice;

    finalPrice = manufacturerPrice * markupPercentage;

    cout << fixed << setprecision(2);
    cout << "The retail price of the item is: " << finalPrice << endl;

return 0;
}