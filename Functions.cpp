#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "Date.h"
#include "Product.h"
#include "Functions.h"
#include <ctime>

string Functions::helpConvert (string& str)
{
    int pos = str.find(" ");
    string option;
    option = str.substr(0,pos);
    str.erase(0, pos+1);
    return option;
}

Date Functions::getCurrentDate ()
{
    Date currentDate;
    time_t t = time(0);
    struct tm* now = localtime( & t );
    currentDate.setYear(now->tm_year + 1900);
    currentDate.setMonth(now->tm_mon + 1);
    currentDate.setDay(now->tm_mday); 
    return currentDate;
}