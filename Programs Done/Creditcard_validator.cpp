#include <iostream>
// Credit-Card Number Validation Program
// This program will determine whether a credit card number is valid or not
// Do not need to know the logic but know common ways to iterate backwards through a string, 

int getDigit(const int number);
int sumOddDigits(const std::string card_number);
int sumEvenDigits(const std::string card_number);

int main() {
    std::string card_number;
    int result;
    std::cout << "Enter a credit card number: ";
    std::cin >> card_number;

    result = sumOddDigits(card_number) + sumEvenDigits(card_number);

    if (result % 10 == 0) {
        std::cout << card_number << " is valid" << std::endl;
    } else {
        std::cout << card_number << " is invalid" << std::endl;
    }

    return 0;
}

int getDigit(const int number) {
    return number % 10 + (number / 10 % 10);
}

int sumOddDigits(const std::string card_number){
    int sum = 0;
    for (int i = card_number.size() - 1; i >= 0; i -= 1) {
        sum += getDigit(card_number[i] - '0');
    }
    return sum;
}

int sumEvenDigits(const std::string card_number){
    int sum = 0;
    for (int i = card_number.size() - 2; i >= 0; i -= 2) {
        sum += getDigit((card_number[i] - '0') * 2);
    }
    return sum;
}

