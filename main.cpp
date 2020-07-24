#include <iostream>
using namespace std;
#include <cstring>
#include <string>
#include "Product.h"
#include "Date.h"
#include "CommandLineReader.h"
#include "Storage.h"
#include <vector>
#include <ctime>
#include <fstream>

void CLR()
{
    string fileName;
    Storage storage;
    cout << "Welcome!\n" << "If you need help using this app please type help!\n";
    string command;
    while(command != "exit")
    {
        cin >> command;
        if (command == "add")
        {
            storage.add();   
        }
        else if (command == "open")
        {
            fileName = CommandLineReader::ReadFile(storage.getProducts(), storage.getToPrint());
        }
        else if(command == "print")
        {
           storage.print();
        }
        else if(command == "help")
        {
           CommandLineReader::help();
        }
        else if (command == "remove")
        {
            CommandLineReader::remove(storage.getProducts());
        }
        else if (command == "clean")
        {
            storage.clean();
        }

        else if (command == "save")
        {
            CommandLineReader::saveas(storage.getProducts(), fileName);
        }

        else if (command == "saveas")
        {
            string fileName;
            cin >> fileName;
            CommandLineReader::saveas(storage.getProducts(), fileName);
        }
        else if (command == "close")
        {
            storage.removeAll();
        }
        else if (command == "exit")
        {
            cout << "Exiting the program...";
            continue;
        } 
        
        else 
        {
            cout << "Command not found!\n";
        }
    }

}


int main()
{
    
    CLR();
    return 0;

}