#ifndef TEMPLATE_H_INCLUDED
#define TEMPLATE_H_INCLUDED
#include<iostream>
#include<fstream>
#include<cstring>
#include"studentType.h"
#include"personType.h"
#include"dateType_int.h"
using namespace std;

template <typename T>
void showData(const string& filename)
{
    ifstream file(filename.c_str(), ios::binary);
    if (!file)
    {
        cerr << "Error opening file\n";
        return;
    }

    T record;
    while (file.read(reinterpret_cast<char*>(&record), sizeof(T)))
    {
        record.print(); // Assuming `print` is a method in the class `T`
        cout << "------------------------\n";
    }

    if (file.fail() && !file.eof())
	{
        cerr << "Error reading from file.\n";
    }
    system("pause");
}



#endif // TEMPLATE_H_INCLUDED

