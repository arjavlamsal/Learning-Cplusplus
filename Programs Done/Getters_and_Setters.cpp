#include <iostream>
/*  
Abstraction =  Hiding unnecessary data from outside of a class.
    Getter  =  Function that makes private attributes READABLE.
    Setter  =  Function that makes private attributes WRITABLE.  
*/


class Stove{
    private:
        int temperature = 0;

    public:
        // Getter - Gets the value of the private attribute temperature and returns it.
        int getTemp(){
            return temperature;
        }

        // Setter - Gets the user input and sets the value of the private attribute temperature.
        void setTemp(int temperature)
        {
            if (temperature < 0){   // Setting a conditional check for the user input validaion.
                this->temperature = 0;
            }
            else if (temperature > 100){
                this->temperature = 100;
            }
            else {
                this->temperature = temperature;
            }
        } 

    // Also we can invoke setters inside of a Constructor to set values:
    Stove(int temperature){
        setTemp(temperature);   // Calling the Setter inside of the constructor to set the value of the private member.
    }
};


int main()
{

    Stove Stove1(-20);
    // Stove1.setTemp(520);
    std::cout << Stove1.getTemp();

    return 0;
}