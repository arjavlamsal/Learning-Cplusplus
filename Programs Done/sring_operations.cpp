#include <iostream>

int main(){
    
    std::string name;
    std::cout << "Enter your name = ";
    std::getline(std::cin, name);

    // Clear the contents in the string variable name
    // std:: cout << name.clear(); 

    // Targeting position of character in string
    std::cout << name.at(0) << '\n';

    // Erasing a target portion of the string
    std::cout << name.erase(5,10) << '\n';
    
    // Append method
    std::cout << name.append("@gmail.com") << '\n';

    // Inserting a string or characters into the main string
    std::cout << name.insert(0,"Lamsal") << '\n';

    // Finding the position of space
    std::cout << name.find(" ") << '\n';

    std::cout << "Length = " << name.length() << '\n';
    std::cout << "If the name is empty then displays 1 - 'True' or displays 0 - 'false' = " << name.empty();
    


    return 0;
}