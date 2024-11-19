#include"dateType_int.h"
#include <stdexcept>
#include<fstream>
#include<iostream>
using namespace std;

dateType::dateType(int m, int d, int y)
{
   date  = d;
   month = m;
   year = y;
}
int dateType::getDate() const
{
    return date;
}

int dateType::getMonth() const
{
    return month;
}

int dateType::getYear() const
{
    return year;
}

void dateType::setDate()
{
  int d,m,y;

   date = d;
   month = m;
   year = y;

while (true)
{

   try {
         cout << "Enter date of birth (dd/mm/yyyy): ";
         cin >> date >> month >> year;
      if (cin.fail() || date <= 0 || date > 31 || month <= 0 || month > 12 || year <= 0 || year > 2024)
     {
        cin.clear();
        cin.ignore(1000, '\n');
        throw invalid_argument("Invalid date. Please enter a valid date.");
     }

          break; // If no exception, break the loop
        }
        catch (const invalid_argument& e)
        {
            cout << "Error: " << e.what() << ". Please enter a valid date of birth.\n";
        }
}

}

void dateType::printDate() const
{
    cout << "Date: " << date << "/" << month << "/" << year << endl;
}



