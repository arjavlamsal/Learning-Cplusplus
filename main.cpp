#include <iostream>
class Animal {
    public:

        void walk(){
            std::cout << "It walks!" << std::endl;
        }
};

class Dog : public Animal {
    public:
        void bark(){
            std::cout << "Dog barks!" << std::endl;
        }
};

class Cat : public Animal {
    public:
        void meow(){
            std::cout << "Cat meows!" << std::endl;
        }
};