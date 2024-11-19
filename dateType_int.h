#ifndef DATETYPE_INT_H_INCLUDED
#define DATETYPE_INT_H_INCLUDED
#include<iostream>
#include<fstream>
using namespace std;

class dateType {

protected:
    int date;
    int month;
    int year;

public:
    dateType(int d = 0, int m = 0, int y = 0);
    void printDate() const;
    int getDate() const;
    int getMonth() const;
    int getYear() const;
    void setDate();
};


#endif // DATETYPE_INT_H_INCLUDED

