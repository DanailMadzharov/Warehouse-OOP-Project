#ifndef PRODUCTS_H
#define PRODUCTS_H
#include <iostream>
using namespace std;
#include <string.h>
#include "Date.h"

struct Shelf 
{
    int number;
    int spaceLeft;

    
    Shelf(): number (0), spaceLeft (0) {}
    Shelf(int _number, int _spaceLeft): number(_number), spaceLeft (_spaceLeft) {}
    Shelf& operator= (const Shelf& other)
    {
        number = other.number;
        spaceLeft = other.spaceLeft;
        return *this;
    }
    void printShelf() const
    {
        cout << number << endl;
    }    
};
/*ostream& operator<< (ostream& out, const Shelf& s)
{
    out << s.number << " ";
    return out;
}*/

class Product
{
    private:
    string name;
    Date expirationDate;
    Date dateOfArrival;
    string manufacter;
    string unit;
    double quantity;
    Shelf location;
    string notes;
    
    void copyProduct(string, Date, Date, string, string, double, Shelf, string);

    public:
    Product();
    Product(string, Date, Date, string, string, double, Shelf, string);
    Product(const Product&);
    Product& operator= (const Product&);
    ~Product();
    void printProduct() const;
    void inputProduct();

    void setLocation(const Shelf&);
    void setLocation (string&);
    void setQuantity(double);
    void setQuantity(string&);

    double getQuantity() const {return quantity;}
    string getName() const {return name;}
    Shelf& getLocation() {return location;}
    int getLocationNumber () const {return location.number;}
    Date getExpirationDate() const {return expirationDate;}
    Date getArrDate() const {return dateOfArrival;}
    string getManufacter() const {return manufacter;}
    string getUnit() const  {return unit;}
    string getNotes() const {return notes;}
    
    void convert(string&);
    friend ostream& operator<< (ostream&, const Product&) ;


};

#endif