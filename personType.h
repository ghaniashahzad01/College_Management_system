#ifndef PERSONTYPE_H_INCLUDED
#define PERSONTYPE_H_INCLUDED

#include <iostream>
#include<cstring>
#include<fstream>

using namespace std;

class personType
{
	protected:
		char firstName[26];
		char lastName[26];
	    int age;

    public:
    	personType();
	    personType(int a, string fn, string ln);
	    personType(const personType& other);
	    personType& operator=(const personType& other);
		bool isNumeric(const string& str);
        void setData();
        void getData();
        virtual void print() = 0;
        virtual ~personType();

};

#endif // PERSONTYPE_H_INCLUDED

