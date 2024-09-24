#include <iostream>

int main(){

    int age;
    std::string name;

    std::cout << "What is your age?" << '\n';
    std::cin >> age;

    std::cout << "What is your first name?";
    // std::cin >> name; // this only gets a word, does not get the word/s after a space
    std::getline(std::cin >> std::ws, name);  // while using getline, it is neccesary 
    // to add ">> std::ws" to remove the '\n' in the input buffer.

    std::cout << "Hello " << name << '\n';
    std::cout << "Your age is " << age;
    return 0;
}