  // Matrix ( 2D - arrays)

  #include <iostream>

  int main(){

    std::string matrix[][3] = { {"a","b","c"},
                                {"d","e","f"},
                                {"g","h","i"}} ;

    int no_of_rows = sizeof(matrix) / sizeof(matrix[0]);
    int no_of_columns = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    
    for(int i = 0; i < no_of_rows ; i++){
        for (int j = 0; j < no_of_columns; j++){
            std::cout << matrix[i][j] << '\n';
        }
    }


    return 0;
  }