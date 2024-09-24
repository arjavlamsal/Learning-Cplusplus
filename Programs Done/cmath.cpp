#include <iostream>
#include <cmath>

int main(){

    double x = 3.49;
    double y = 3.99;
    double z;
    double a;


    // math from standard:
    z = std::max(x, y); // max function
    a = std::min(x, y); // min function

    // math from the 'cmath' header
    z = pow(2, 2);
    z = sqrt(9);
    z = abs(-10);
    z = round(y);
    z = ceil(3.1);
    z = floor(3.9);


    std::cout << z;


    return 0;
}