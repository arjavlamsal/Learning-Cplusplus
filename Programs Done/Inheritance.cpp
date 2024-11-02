#include <iostream>

/*  Inheritance  =  An OOP principle in which a class(Child) can receive attributes and methods from another class(Parent).
                    Useful to reuse similar code within multiple classes.
*/

class Shape{
    public:
        double area;
        double volume;
};

class Cube : public Shape {
    public:
        double side;
    
    Cube(double side){
        this->side = side;
        this->area = side * side * 6;
        this->volume = side * side * side;
    }
};

class Sphere : public Shape {
    public:
        double radius;
    
    Sphere(double radius){
        this->radius = radius;
        this->area = 4 * 3.14159 * (radius * radius);
        this->volume = (4/3.0) * 3.14159 * (radius * radius * radius);
    }
};

int main(){

    Cube cube1(5.0);
    Sphere sphere1(5.0);

    std::cout << "\nCube's area = " << cube1.area << "\nCube's Volume =  " << cube1.volume << std::endl;
    std::cout << "Sphere's area = " << sphere1.area << "\nSphere's Volume =  " << sphere1.volume << std::endl;

    return 0;
}