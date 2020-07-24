#include "Product.h"
#include "Date.h"
#include "Functions.h"
#include "CommandLineReader.h"
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <string.h>
#include <fstream>




void CommandLineReader::help ()
{
     cout <<  "The following commands are being supported:\n" <<
                          "open <file>      ->   opens <file>. If a file with that name does not exist a new one is being created.\n" <<
                          "close            ->   closes currently opened file\n" <<
                          "save             ->   saves the currently opened file\n" <<
                          "saveas<file>     ->   saves the currently opened file in <file>\n" <<
                          "exit             ->   exits the program\n" <<
                          "add              ->   adds a new product\n" <<
                          "print            ->   prints all products available\n" <<
                          "remove           ->   removes the amount you've stated from the product you've stated\n" <<
                          "clean            ->   cleans the storage from all expired products \n" <<
                          "log <from> <to> ->    gives information for all changes made in that period\n";

}

void CommandLineReader::remove(vector<Product>& products)
{
    string name;
    cout << "Product name: ";
    cin >> name;
    double quantity;
    cout << "Quantity: ";
    cin >> quantity;
    double quantityToLog = quantity;
    vector<Product> toRemove;
    vector<int> index;
    double sumQuantity = 0;
    for (int i = 0; i < products.size(); i++)
    {
        if (name == products[i].getName())
        {
            toRemove.push_back(products[i]);
            index.push_back(i);
            sumQuantity += products[i].getQuantity();
        }
        
    }
    if (sumQuantity < quantity)
    {
        cout << "Sorry, not enough quantity in stock!\n";
        return;
    }
    else 
    {
        for (int i=0; i < toRemove.size() - 1; i++)
        {
            for(int j = i+1; j < toRemove.size(); j++)
            {
                if (toRemove[i].getExpirationDate() > toRemove[j].getExpirationDate())
                {
                    swap(toRemove[i], toRemove[j]);
                    swap(index[i], index[j]);
                }
            }
        }        
        auto it = toRemove.begin();
        auto it2= index.begin();
        for(int i=0; i < toRemove.size(); i++,it++)
        {
            if(toRemove[i].getQuantity() > quantity)
            {
                toRemove[i].setQuantity(toRemove[i].getQuantity() - quantity);
                products[index[i]].setQuantity(products[index[i]].getQuantity() - quantity);
                quantity = 0;
            }
            else if (toRemove[i].getQuantity() == quantity)
            {
                toRemove.erase(it);
                products.erase(products.begin() + index[i]);
                index.erase(it2);
                quantity = 0;
            }
            else 
            {
                quantity -= toRemove[i].getQuantity();
                toRemove.erase(it);
                products.erase(products.begin() + index[i]);
                index.erase(it2);
                i--;
                it--;
            }
            if (quantity == 0) break;
        }
    }
    cout << "\nProduct has been removed successfully!\n";
    ofstream logFile ("log.txt", ios::out | ios::app);
    logFile << Functions::getCurrentDate() << " " << quantityToLog << toRemove[0].getUnit() 
                                            << " of" << name << " have been removed from the storage.\n";
    logFile.close();
}

int CommandLineReader::getNumber (string a)
{
    int n = a.size();
    int x = 0;
    for (int i=0; i < n; i++)
    {
        x = x*10 + (int(a[i] - '0'));

    }
    return x;
}

string CommandLineReader::ReadFile (vector<Product>& products, vector<bool>& print)
{
    string fileName;
    cin >> fileName;
    string a;
    fstream inFile (fileName, ios::in | ios::out | ios::app);
    int number;
    if(inFile.is_open())
    {
        getline(inFile, a);
        number = getNumber(a);
        inFile.close();
    }
    else
    {
        cout<<"Unable to open file!\n";
    }

    inFile.open(fileName);
    if(inFile.is_open())
    {
        int id=0;
        while(getline(inFile, a))
        {
            if(id > 0)
            {
                string str = a;
                Product newProduct;
                newProduct.convert(a);
                products.push_back(newProduct);
                print.push_back(false);
            }
            id++;
        }
        inFile.close();
    }
    return fileName;
}


void CommandLineReader::saveas(vector<Product>& products, string fileName)
{
    
    ofstream outFile (fileName);
    outFile << products.size() << endl;
    for (int i = 0; i < products.size(); i++)
    {
        outFile << products[i];
    }
    cout << "All changes have successfully been saved to a file!\n";

}