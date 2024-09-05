#include <iostream>
// The purpose of namespace is to allow the use of multiple variables of the same name without an error in a 
// long project.

namespace first{
    int x = 1;
}

double num = 6;

namespace second{
    int x = 2;
}

int main(){
    // using namespace first;
    // using namespace second;


    int x = 0;

    std::cout << x;
    std::cout << first::x;
    std::cout << second::x;

}

/* Also "using namespace std" allows to use for std included namespaces without having to type "std::"
Eg: cout, string, and many more.*/