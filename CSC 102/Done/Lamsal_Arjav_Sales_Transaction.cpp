// Project: Sales Transaction
// Programmer: Arjav Lamsal
// Date: 11/11/2024
// Description: This program displays information about sales transactions made at a car dealership,
//              including transaction details, car information, sales person information, and customer information.

#include <iostream>
#include <string>
using namespace std;

// Car class to hold information about the car purchased
class Car {
private:
    string make;
    string model;
    int year;
    double stickerPrice;

public:
    Car() : make(""), model(""), year(0), stickerPrice(0.0) {} // Default constructor

    Car(string mk, string mdl, int yr, double price) : make(mk), model(mdl), year(yr), stickerPrice(price) {} // Constructor with parameters

    void setCarInfo(string mk, string mdl, int yr, double price) {
        make = mk;
        model = mdl;
        year = yr;
        stickerPrice = price;
    }

    void print() const {
        cout << "Car Information:\n";
        cout << "Make: " << make << "\nModel: " << model << "\nYear: " << year << "\nSticker Price: $" << stickerPrice << endl;
    }
};

// SalesPerson class to hold information about the salesperson
class SalesPerson {
private:
    string lastName;
    string firstName;
    string officePhone;

public:
    SalesPerson() : lastName(""), firstName(""), officePhone("") {} // Default constructor

    SalesPerson(string ln, string fn, string phone) : lastName(ln), firstName(fn), officePhone(phone) {} // Constructor with parameters

    void setSalesPersonInfo(string ln, string fn, string phone) {
        lastName = ln;
        firstName = fn;
        officePhone = phone;
    }

    void print() const {
        cout << "\nSales Person Information:"
             << "\n****************************************************************\n";
        cout << "Last Name: " << lastName << "\nFirst Name: " << firstName << "\nOffice Phone: " << officePhone << endl;
    }
};

// Customer class to hold information about the customer
class Customer {
private:
    string lastName;
    string firstName;
    string phoneNumber;

public:
    Customer() : lastName(""), firstName(""), phoneNumber("") {} // Default constructor

    Customer(string ln, string fn, string phone) : lastName(ln), firstName(fn), phoneNumber(phone) {} // Constructor with parameters

    void setCustomerInfo(string ln, string fn, string phone) {
        lastName = ln;
        firstName = fn;
        phoneNumber = phone;
    }

    void print() const {
        cout << "\nCustomer Information:"
             << "\n****************************************************************\n";
        cout << "Last Name: " << lastName << "\nFirst Name: " << firstName << "\nPhone Number: " << phoneNumber 
             << "\n****************************************************************\n" << endl;
    }
};

// SalesTransaction class to hold transaction information and associated car, salesperson, and customer data
class SalesTransaction {
private:
    string transactionNumber;
    double salePrice;
    Car car;
    SalesPerson salesPerson;
    Customer customer;

public:
    SalesTransaction(string transNum, double price, string mk, string mdl, int yr, double sticker, 
                     string spLast, string spFirst, string spPhone, 
                     string custLast, string custFirst, string custPhone) 
        : transactionNumber(transNum), salePrice(price), 
          car(mk, mdl, yr, sticker), salesPerson(spLast, spFirst, spPhone), 
          customer(custLast, custFirst, custPhone) {} // Constructor with parameters

    void print() const {
        cout << "\n****************************************************************\n"
             << "Sales Transaction Information:"
             << "\n****************************************************************\n";
        cout << "Transaction Number: " << transactionNumber << "\nSale Price: $" << salePrice << endl;
        car.print();
        salesPerson.print();
        customer.print();
        cout << endl;
    }
};

// Main function
int main() {
    system("color f0");

    // Create a SalesTransaction object
    SalesTransaction sale1("11111", 68000.00, 
                           "Ford", "F-250", 2022, 55000.00, 
                           "Williams", "Ted", "555-7777", 
                           "Ross", "Scott", "555-1111");

    // Create another SalesTransaction object
    SalesTransaction sale2("22222", 33000.00, 
                           "Ford", "F-150", 2016, 36000.00, 
                           "Williams", "Jessica", "555-7785", 
                           "Thomas", "Billy", "555-2222");

    // Display the SalesTransaction info
    sale1.print();
    sale2.print();

    return 0;
}
