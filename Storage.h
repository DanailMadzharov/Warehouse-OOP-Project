#ifndef STORAGE_H
#define STORAGE_H
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include "Product.h"

class Storage
{
    private:
    vector<Product> products;
    vector<Shelf> shelfs;
    vector<bool> toPrint;


    public:
    void createShelf(Product&);
    void setShelf(Product&);
    bool searchProduct (Product& p);
    void searchPrint(int);

    void clean();
    void print();
    void add();
    void removeAll();

    vector<Product>& getProducts() {return products;}
    vector<Shelf>& getShelfs() {return shelfs;}
    vector<bool>& getToPrint() {return toPrint;}




};

#endif