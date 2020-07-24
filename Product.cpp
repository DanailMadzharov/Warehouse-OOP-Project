#include "Product.h"
#include "Functions.h"
#include "Date.h"
#include <iostream>
using namespace std;
#include <string.h>

void Product::copyProduct(string _name, Date _expirationDate, Date _dateOfArrival, string _manufacter, 
                          string _unit, double _quantity, Shelf _location, string _notes)
{
    name = _name;
    expirationDate = _expirationDate;
    dateOfArrival = _dateOfArrival;
    manufacter =  _manufacter;
    unit = _unit;
    quantity = _quantity;
    location = _location;
    notes = _notes;
}

Product::Product() = default;
Product::Product(string _name, Date _expirationDate, Date _dateOfArrival, string _manufacter, 
                string _unit, double _quantity, Shelf _location, string _notes)
{
    copyProduct(_name, _expirationDate, _dateOfArrival, _manufacter, _unit, _quantity, _location, _notes);   
}

Product::Product(const Product& other)
{
    copyProduct(other.name, other.expirationDate, other.dateOfArrival, other.manufacter, other.unit, other.quantity,
                other.location, other.notes);
}

Product& Product::operator=(const Product& other)
{
    if (this != &other)
    {
        copyProduct(other.name, other.expirationDate, other.dateOfArrival, other.manufacter, other.unit, other.quantity,
                    other.location, other.notes);
    }
    return *this;
}

Product::~Product() = default;

void Product::printProduct() const
{
    cout << "Product name: " << name << endl
              << "Manufacter: " << manufacter << endl
              << "Quantity: " << quantity << unit << endl
              << "Location: shelf #";
              location.printShelf();
              cout << "Notes: " << notes << endl;
}

ostream& operator<< (ostream& out , const Product& p)
{
    out << p.getName() << " "
        << p.getExpirationDate() << " "
        << p.getArrDate() << " "
        << p.getManufacter() << " "
        << p.getUnit() << " "
        << p.getQuantity() << " "
        << p.getLocationNumber() << " "
        << p.getNotes() << endl;
    return out;

}


void Product::setLocation(const Shelf& s)
{
    location = s;
}

void Product::setLocation (string& str)
{
    int number = 0;
    for (int i=0; i<str.size(); i++)
    {
        number = number*10 + (str[i] - '0');  
    }
    Shelf newShelf (number, 500);
    this->setLocation(newShelf);

}
void Product::setQuantity(double q)
{
    quantity = q;
}
void Product::inputProduct()
{
    cout << "Product name: ";
    cin >> name;
    cout << "Expiration date: ";
    cin >> expirationDate;
    cout << "Date of arrival: ";
    cin >> dateOfArrival;
    cout << "Manufacter: ";
    getline(cin, manufacter) ;
    getline(cin, manufacter) ;
     cout << "Unit (kg/l): ";
    cin >> unit;
    if (unit != "kg" && unit != "l")
    {
        bool validUnit = false;
        while (!validUnit)
        {
            cout << "Invalid unit!\nUnit: ";
            cin >> unit;
            if (unit == "kg" || unit == "l") 
            {
                validUnit = true;
            }
        }
        
    }
    cout << "Quantity: ";
    cin >> quantity;
    cout << "Notes: ";
    getline(cin, notes);
    getline(cin, notes);
}

void Product::setQuantity(string& str)
{
    int divider = 1;
    bool div = false;
    quantity=0;
    for (int i = 0; i < str.size(); i++)
    {
        if (div)
            divider *= 10;
        
        if (str[i] == '.')
        {
            div = true;
        }
        else 
        {
            quantity = quantity*10 + (int(str[i]) - '0');

        }
    }
    quantity /= divider;
}

void Product::convert(string& str)
{
    
    name = Functions::helpConvert(str);

    expirationDate.setDate(Functions::helpConvert(str));

    dateOfArrival.setDate(Functions::helpConvert(str));

    manufacter = Functions::helpConvert(str);

    unit = Functions::helpConvert(str);

    string helper = Functions::helpConvert(str);

    this->setQuantity(helper);

    helper = Functions::helpConvert(str);

    this->setLocation(helper);

    notes = str;

}