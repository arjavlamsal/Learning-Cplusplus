#include <iostream>

int main(){
    
    std::string name;
    int num;


    // While Loops - if the condition matches, then only the codeblock will work
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
    


    return 0;
}