#include <iostream>
#include <cstdlib>  // For rand(), srand()
#include <ctime>    // For time()
using namespace std;

// Function Declarations
void drawBoard(char *array);
void playerMove(char *array, char player);
void computerMove(char *array, char computer);
bool checkWinner(char *array, char player);
bool checkTie(char *array);

int main(){
    char array[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    bool running = true;
    char player = 'X';
    char computer = 'O';

    srand(time(0)); // Move srand to main, to seed once at the start of the game.

    do {
        drawBoard(array);
        playerMove(array, player); 
        if (checkWinner(array, player) || checkTie(array)) {
            break;
        }

        computerMove(array, computer);
        if (checkWinner(array, computer) || checkTie(array)) {
            break;
        }
    } while (running);

    return 0;
}

void drawBoard(char *array) {
    cout << "       |       |       " << '\n';
    cout << "  " << array[0] <<"    |"<<"  " << array[1] <<"    |"<< "   " << array[2] <<"   "<< '\n';
    cout << "_______|_______|_______" << '\n';
    cout << "       |       |       " << '\n';
    cout << "  " << array[3] <<"    |"<<"  " << array[4] <<"    |"<< "   " << array[5] <<"   "<< '\n';
    cout << "_______|_______|_______" << '\n';
    cout << "       |       |       " << '\n';
    cout << "  " << array[6] <<"    |"<<"  " << array[7] <<"    |"<< "   " << array[8] <<"   "<< '\n';
    cout << "       |       |       " << '\n';
}

void playerMove(char *array, char player) {
    int usr_in;
    do {
        cout << "Enter the place you want to cross (1 to 9): ";
        cin >> usr_in;
        usr_in--;   // Convert to array index

        if (usr_in >= 0 && usr_in < 9 && array[usr_in] == ' ') {
            array[usr_in] = player;
            break;
        } else {
            cout << "Invalid move. Try again.\n";
        }
    } while (true);
}

void computerMove(char *array, char computer) {
    while (true) {
        int random_move = rand() % 9;  // Generate a number between 0 and 8
        if (array[random_move] == ' ') {
            array[random_move] = computer;
            break;
        }
    }
}

bool checkWinner(char *array, char player) {
    int winPatterns[8][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
                              {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
                              {0, 4, 8}, {2, 4, 6} };          // Diagonals
    for (int i = 0; i < 8; ++i) {
        if (array[winPatterns[i][0]] == player &&
            array[winPatterns[i][1]] == player &&
            array[winPatterns[i][2]] == player) {
            drawBoard(array);
            cout << (player == 'X' ? "YOU WIN!\n" : "YOU LOSE!\n");
            return true;
        }
    }
    return false;
}

bool checkTie(char *array) {
    for (int i = 0; i < 9; i++) {
        if (array[i] == ' ') {
            return false;
        }
    }
    drawBoard(array);
    cout << "It's a tie!\n";
    return true;
}
