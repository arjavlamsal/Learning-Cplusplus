// Program Name: Count Words
// Programmer: Arjav Lamsal
// Date Created: September 26, 2024
// Program Description: This program prompts the user to enter one or more sentences,
// counts the number of words and sentences entered, and then displays the result.

#include <iostream>
#include <cstring> // for strlen()

using namespace std;

// Function prototypes
void getUserInput(char[]);
int numberOfWords(const char[]);
int numberOfSentences(const char[]);
void displayOutput(int, int);

int main() {
    char userInput[101];  // A character array to store up to 100 characters input by the user

    // Keep asking for input until the user enters a non-empty string
    do {
        getUserInput(userInput);
    } while (strlen(userInput) == 0);

    // Calculate the number of words and sentences
    int words = numberOfWords(userInput);
    int sentences = numberOfSentences(userInput);

    // Display the result
    displayOutput(words, sentences);

    return 0;  // End of the program
}

// This function prompts the user to enter a sentence and stores it in the userInput array
void getUserInput(char userInput[]) {
    cout << "Enter a sentence (max 100 characters): ";
    cin.getline(userInput, 101);  // Read up to 100 characters into the userInput array
}

// This function counts the number of words in the userInput array
int numberOfWords(const char userInput[]) {
    int wordCount = 0;  // Variable to store the word count

    // Loop through the input string character by character
    for (int i = 0; i < strlen(userInput); i++) {
        // Check for spaces to separate words
        if (userInput[i] == ' ' && userInput[i+1] != ' ' && i != strlen(userInput) - 1) {
            wordCount++;  // Increment word count when a space is found
        }
    }

    return wordCount + 1;  // Add 1 for the first word
}

// This function counts the number of sentences based on punctuation ('.', '!', '?')
int numberOfSentences(const char userInput[]) {
    int sentenceCount = 0;  // Variable to store the sentence count

    // Loop through the input string and check for sentence-ending punctuation
    for (int i = 0; i < strlen(userInput); i++) {
        if (userInput[i] == '.' || userInput[i] == '!' || userInput[i] == '?') {
            sentenceCount++;  // Increment sentence count for each sentence-ending punctuation
        }
    }

    return sentenceCount;
}

// This function displays the number of words and sentences
void displayOutput(int words, int sentences) {
    cout << "Number of words: " << words << endl;       // Output the word count
    cout << "Number of sentences: " << sentences << endl; // Output the sentence count
}
