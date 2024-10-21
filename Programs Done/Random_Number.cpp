// Number guessing game.
#include <iostream>
#include <ctime>

int main(){
    using namespace std;

    int tries = 0;
    int guess;
    char usr_in;
    
    srand(time(0));

    int rand_num = (rand() % 10) + 1;

    bool flag = true;

    while (flag)
    {
        cout << "Do you want to play the game? (y/n)= ";
        cin >> usr_in;
        usr_in = tolower(usr_in); // Changed to lower case.

         if (usr_in == 'y')
         {
            cout << "Enter a guess = ";
            cin >> guess;

            if (guess == rand_num){
                cout << "You guessed it!" << '\n';
            } else {

                cout << "Wrong! " << "The answer was " << rand_num << '\n' << "Better luck next time..." << '\n';
            }
         } else if (usr_in == 'n'){
            cout << "Thank You for playing! See you again soon.." << '\n';
            flag = false;
         } else {
            cout << "Enter correct response!" << '\n';
         }

    }
    
    return 0;
}