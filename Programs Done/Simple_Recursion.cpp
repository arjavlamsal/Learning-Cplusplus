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

#include <iostream>

void walk(int steps);

int main(){
    walk(100);  // Calling the function.
    return 0;
}

// Recursive Approach:
void walk(int steps){
    if (steps > 0){ // Continues until step is 1 starting from 100.
        std::cout << "You take a step!" << '\n';
        walk(steps - 1);    // Recursion
    }
}

// Iterative Approach:
// void walk(int steps){
//     for (int i = 0; i < steps; i++){
//         std::cout << "You take a step!" << '\n';
//     }
// }