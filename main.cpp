// For Each Loop: Loop that eases the traversal over an iterative dataset
#include <iostream>

int main(){

    std::string students[] = {"arjav", "renasha", "lovebirds"};

    for (std::string student : students){
        std::cout << student << std::endl;
    }

    int scores[] = {1,2,3,4,5,6,7,8,9};

    for (int score : scores){
        std::cout << score << std::endl;
    }

    return 0;
}