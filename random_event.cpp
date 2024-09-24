// For example in a game Random Weather or Random Monster to show up.
#include <iostream>
#include <ctime>

int main()
{
    using namespace std;
    srand(time(0)); // Uses current time as the seed to generate random number.
    int rand_num = rand() % 5 + 1; // Random number between (1,5).

    switch (rand_num)
    {
    case (1):
        cout << "1" << '\n';
        break;

    case (2):
        cout << "2" << '\n';
        break;

    case (3):
        cout << "3" << '\n';
        break;
    
    default:
        cout << "No prize sorry" << '\n';
        break;
    }

    std::cout << rand_num;



    return 0;
}