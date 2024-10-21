#include <iostream>
// Palindrome Checker
int main() {

    std::string usr_in;
    std::string rev_str;

    std::cout << "Enter a word = ";
    std::cin >> usr_in;

    for (int i = usr_in.length() - 1; i >= 0; i -= 1){
        rev_str += usr_in[i];
    }
    
    if (usr_in == rev_str){
        std::cout << "Issa Palindrome!";
    }
    else {
        std::cout << "Issnutt!";
    }

    return 0;
}