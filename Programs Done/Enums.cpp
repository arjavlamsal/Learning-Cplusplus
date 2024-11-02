/* Enum (Enumerators) = A user-defined datatype that consists of paired name-integer constants.
                        - GREAT if you have potential options.
                        - Helpful in using switch-case.
                        - Can be used as a dictionary for integer and string. 
*/

#include <iostream>

enum Day {sunday = 0, monday = 1, tuesday = 2, wednesday = 3, thursday = 4, friday = 5, saturday = 6}; // Creating enums with assigned integers.
enum Flavor {vanilla, strawberry, chocolate, mint};   // Creating enums with default integers, i.e. 0,1,2...
enum Planet {mercury = 4800, venus = 12104, earth = 12756, mars = 6794, jupiter = 142984};  // Enums for planet and their diameters in km.

int main()
{
    Day today = sunday; // Initializing 'today' as a variable of user-defined datatype 'day'.

    switch (today)  // Switch-Case cannot take string as an argument so enums come in handy.
    {
    case sunday:    // sunday or 0, both work!
        std::cout << "It is sunday today!";
        break;

    case 1:         // 1 or monday, both work!
        std::cout << "It is Monday today!";
        break;

    default:
        break;
    }


    return 0;
}