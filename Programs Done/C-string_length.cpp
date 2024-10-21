// C-style strings length counting

#include <iostream>
using namespace std;

int main()
{
    char str_array[] = "hellooooooo"; // Adding elements into the char array passing a whole string 
    int length = 0;
    while (str_array[length] != '\0') // While element in str_array != null terminator ('\0') keep looping
    {
        length++;
    }
    cout << length << endl;
}
