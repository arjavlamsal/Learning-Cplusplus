/* Recursion =  A programming technique where a function invokes itself from within.
                - Helps break a complex concept into repeatable signle steps.
                - There needs to be a 'base case' to know when to stop or else,infinite calls
                  to the function recursively will lead to Stack Overflow.
                
Iterative vs Recursive (Can be solved both ways...):
        
        Advantages of Recursion:
        - Less code; is cleaner.
        - Useful for Searching & Sorting Algorithms.
        
        Disadvantages of Recursion:
        - Uses more memory.
        - Slower.
*/

// Factorial Program
#include <iostream>

int fact(int num);

int main() {
    int num;
    std::cout << "Enter the number to know its factorial = ";
    std::cin >> num;

    int result = fact(num);

    std::cout << '\n' << result;

    return 0;
}

int fact(int num){
    if (num > 0){   // Base Case (when the recursion should stop).
        return num * fact(num - 1);
    }
    return 1;
}