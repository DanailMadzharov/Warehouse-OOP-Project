#ifndef COMMANDLINEREADER_H
#define COMMANDLINEREADER_H
#include <iostream>
using namespace std;
#include <string>
#include <vector>

class CommandLineReader
{
    
    static int getNumber(string);

    public:
    static string ReadFile (vector<Product>&, vector<bool>&);

    static void open();
    static void help();
    static void saveas(vector<Product>&, string);
    static void remove(vector<Product>&);
};
#endif