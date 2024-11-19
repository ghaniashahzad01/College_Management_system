#ifndef PROGRAM_H_INCLUDED
#define PROGRAM_H_INCLUDED

#include <string>
#include<iostream>
using namespace std;

class CollegeManagementSystem 
{
private:
    void handlePayment(int requiredFee, const string& field);
    void fscPreMedical();
    void fscPreEngineering();
    void icsPhysics();
    void icsStatistics();
    void iCom();

public:
    void showMenu();
};

#endif // PROGRAM_H_INCLUDED
