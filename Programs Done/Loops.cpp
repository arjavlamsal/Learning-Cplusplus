#include <iostream>

int main(){
    
    std::string name;
    int num;


    // While Loops - if the condition matches, then only the codeblock will work.
    while (name.empty()){
        std::cout << "Enter a name = ";
        std::getline(std::cin, name);
    }

    // DO While Loops - Once the code-block is exeuted and only then the condition 
    // check occurs and the codeblock will re run if the condition matches 
    do{
        std::cout << "Enter a number";
        std::cin >> num ;
    } while (num > 0 && num < 10);
    

    // For Loops - Loops that execute a code-block for the specified number of times.
    // for (typedec i = startingvalue; max limit; stepper)
    for (int i = 10; i >= 0; i--){
        if (i==5){
        // Continue - skips the current iteration to the next value of index, not executing code-block below it.
            continue;
        }
        if (i==2){
        // Break - breaks out of the loop.
            break;
        }
        std::cout << i << '\n';
    }

    return 0;
}