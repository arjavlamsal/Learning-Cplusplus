#include <iostream>

int main(){
    
    std::string name;
    std::cout << "Enter your name = ";
    std::getline(std::cin, name);

    // Clear the contents in the string variable name
    // std:: cout << name.clear(); 

    // Targeting position of character in string
    std::cout << name.at(0) << '\n';
    
    // Append method
    std::cout << name.append("@gmail.com") << '\n';

    std::cout << "Length = " << name.length() << '\n';
    std::cout << name.empty();
    


    return 0;
}