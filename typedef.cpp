// typedef and typealiases & using
// Used to make definitions of datatypes easier by substituting with a alias for use.
// Use only when clear benefit.
/* Example for 
typedef std::vector<std::pair<std::string, int>> pairlist_t;
*/
// BUT lately "typedef" has been replaced with "using" keyword as it works better with templates.


// // Program with "typedef":
// #include <iostream>

// typedef std::string text_t;
// typedef int number_t;

// int main(){
//     text_t str= "Haha i don't have to use std::string anymore its just the typealias and the variable name!";
//     number_t num = 5;

//     std::cout << str << '\n' << num;

//     return 0;
// }


// Program with "using":
#include <iostream>

using text_t = std::string;
using number_t = int;

int main(){
    text_t str= "Haha i don't have to use std::string anymore its just the typealias and the variable name!";
    number_t num = 5;

    std::cout << str << '\n' << num;

    return 0;
