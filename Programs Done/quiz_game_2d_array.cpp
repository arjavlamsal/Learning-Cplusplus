  // Quiz Game 
  // Using 2D array and nested loop for questions and answers
  // answer_key: list of chars for right options that go inside the questions loop and checks for right answer

  #include <iostream>

  int main(){

    char usr_in;
    int guesses = 0;

    char answer_key[] = {'b','c'};

    std::string questions[] = {"What Programming language are we learning?", "What language is called the mother of all programming languages?"};

    std::string answers[2][4] = { {"PYTHON","C++","C","JAVASCRIPT"},
                                {"HTML","CSS","C++","PHP"}} ;

    int length_of_questions = sizeof(questions) / sizeof(questions[0]); // no.of elements = size of array (total elements) in bites / size of 1 element in bytes. 
    int no_of_rows = sizeof(answers[0]) / sizeof(answers[0][0]); // no. of elements = size of array in the row in bytes / size of 1 element in the row in bytes.
    
    for (int i = 0; i < length_of_questions; i++){
        std::cout << questions[i] << '\n';
        for (int j = 0; j < no_of_rows; j++){
            std::cout << answers[i][j] << "   ";
        }
        std::cin >> usr_in;
        usr_in = tolower(usr_in);
        if (usr_in == answer_key[i]){
            std::cout << "Correct!" << std::endl;
            guesses++;
        }
        else{
            std::cout << "Incorrect!" << std::endl;
            std::cout << "The right answer was " << answer_key[i] << std::endl;

        }
    }
    std::cout << "You got " << guesses << " correct answers!" << std::endl; 



    return 0;
  }