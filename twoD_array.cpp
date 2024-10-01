  // Matrix ( 2D - arrays)

  #include <iostream>

  int main(){

    std::string matrix[][3] = { {"a","b","c"},
                                {"d","e","f"},
                                {"g","h","i"}} ;

    int no_of_rows = sizeof(matrix) / sizeof(matrix[0]); // no.of rows = size of array (total rows as elements) in bites / size of 1 element/row in bytes. 
    int no_of_columns = sizeof(matrix[0]) / sizeof(matrix[0][0]); // similar in sense.
    for(int i = 0; i < no_of_rows ; i++){
        for (int j = 0; j < no_of_columns; j++){
            std::cout << matrix[i][j] << '\n';
        }
    }


    return 0;
  }