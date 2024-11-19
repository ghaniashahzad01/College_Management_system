#include "program.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void CollegeManagementSystem::handlePayment(int requiredFee, const string& field) 
{
    int paidAmount = 0;
    int totalPaid = 0;

    while (totalPaid < requiredFee) 
    {
        cout << "Total fee to be paid for " << field << ": Rs. " << requiredFee << endl;
        cout << "Enter the amount you want to pay: Rs. ";

        while (!(cin >> paidAmount) || paidAmount < 0) 
        {
            if (cin.eof()) 
            {
                cout << "Input ended. Exiting payment process." << endl;
                return; // Exit payment process if EOF is encountered
            }
            
            if (cin.fail()) 
            {
                cin.clear(); // Clear the error state
                cin.ignore(10000, '\n'); // Discard invalid input
                cout << "Invalid input. Please enter a positive integer: ";
            }
            else 
            {
                cout << "Amount cannot be negative. Please enter a positive integer: ";
                cin.clear(); // Clear the error state
                cin.ignore(1000, '\n'); // Discard invalid input
            }
        }

        totalPaid += paidAmount;

        if (totalPaid < requiredFee) 
        {
            cout << "You need to pay Rs. " << (requiredFee - totalPaid) << " more." << endl;
        }
        else if (totalPaid > requiredFee) 
        {
            cout << "You have overpaid by Rs. " << (totalPaid - requiredFee) << ". Please pay the exact amount." << endl;
            totalPaid -= paidAmount; // Revert the overpayment
        }
    }
    cout << "Payment successful!" << endl;
}

void CollegeManagementSystem::fscPreMedical() 
{
    system("cls");
    cout << "FSc (Pre-Medical) subjects and fees:\n" << endl;
    cout << "----1st Year Subjects: ----" << endl;
    cout << "1- Islamiat\n";
    cout << "2- English\n"; 
    cout << "3- Urdu\n";
    cout << "4- Physics\n";
    cout << "5- Chemistry\n";
    cout << "6- Biology\n";
    cout << "----2nd Year Subjects:-----" << endl;
    cout << "1- Pakistan Studies\n";
    cout << "2- English\n";
    cout << "3- Urdu\n";
    cout << "4- Physics\n"; 
    cout << "5- Chemistry\n";
    cout << "6- Biology\n" << endl;
    handlePayment(25000, "FSc (Pre-Medical) 1st Year");
    cout << "------------------------------------------\n";
    handlePayment(27000, "FSc (Pre-Medical) 2nd Year");
}

void CollegeManagementSystem::fscPreEngineering() 
{
    system("cls");
    cout << "FSc (Pre-Engineering) subjects and fees:\n" << endl;
    cout << "----1st Year Subjects: ----" << endl;
    cout << "1- Islamiat\n";
    cout << "2- English\n";
    cout << "3- Urdu\n";
    cout << "4- Physics\n";
    cout << "5- Chemistry\n";
    cout << "6- Mathematics\n";
    cout << "----2nd Year Subjects: ----" << endl;
    cout << "1- Pakistan Studies\n";
    cout << "2- English\n";
    cout << "3- Urdu\n";
    cout << "4- Physics\n";
    cout << "5- Chemistry\n";
    cout << "6- Mathematics\n";
    handlePayment(26000, "FSc (Pre-Engineering) 1st Year");
    cout << "------------------------------------------" << endl;
    handlePayment(28000, "FSc (Pre-Engineering) 2nd Year");
}

void CollegeManagementSystem::icsPhysics() 
{
    system("cls");
    cout << "ICS (Physics) subjects and fees:\n" << endl;
    cout << "----1st Year Subjects: ----" << endl;
    cout << "1- Islamiat\n";
    cout << "2- English\n";
    cout << "3- Urdu\n";
    cout << "4- Physics\n";
    cout << "5- Computer Science\n";
    cout << "6- Mathematics\n";
    cout << "----2nd Year Subjects: ----" << endl;
    cout << "1- Pakistan Studies\n";
    cout << "2- English\n";
    cout << "3- Urdu\n";
    cout << "4- Physics\n";
    cout << "5- Computer Science\n";
    cout << "6- Mathematics\n";
    handlePayment(27000, "ICS (Physics) 1st Year");
    cout << "------------------------------------------" << endl;
    handlePayment(29000, "ICS (Physics) 2nd Year");
}

void CollegeManagementSystem::icsStatistics() 
{
    system("cls");
    cout << "ICS (Statistics) subjects and fees:\n" << endl;
    cout << "----1st Year Subjects: ----" << endl;
    cout << "1- Islamiat\n";
    cout << "2- English\n";
    cout << "3- Urdu\n";
    cout << "4- Statistics\n";
    cout << "5- Computer Science\n";
    cout << "6- Mathematics\n";
    cout << "----2nd Year Subjects: ----" << endl;
    cout << "1- Pakistan Studies\n";
    cout << "2- English\n";
    cout << "3- Urdu\n";
    cout << "4- Statistics\n";
    cout << "5- Computer Science\n";
    cout << "6- Mathematics\n";
    handlePayment(26500, "ICS (Statistics) 1st Year");
    cout << "------------------------------------------" << endl;
    handlePayment(28500, "ICS (Statistics) 2nd Year");
}

void CollegeManagementSystem::iCom() 
{
    system("cls");
    cout << "I.Com subjects and fees:\n" << endl;
    cout << "----1st Year Subjects: ----" << endl;
    cout << "1- Islamiat\n";
    cout << "2- English\n";
    cout << "3- Urdu\n";
    cout << "4- Principles of Accounting\n";
    cout << "5- Principles of Economics\n";
    cout << "6- Business Mathematics\n";
    cout << "----2nd Year Subjects: ----" << endl;
    cout << "1- Pakistan Studies\n";
    cout << "2- English\n";
    cout << "3- Urdu\n";
    cout << "4- Principles of Accounting\n";
    cout << "5- Principles of Economics\n";
    cout << "6- Business Statistics\n";
    handlePayment(24000, "I.Com 1st Year");
    cout << "------------------------------------------" << endl;
    handlePayment(26000, "I.Com 2nd Year");
}

bool isNumber(const string& str) 
{
    // Check if the string is empty
    if (str.empty()) 
    {
        return false;
    }

    // Check each character to ensure it's a digit
    for (char ch : str) 
    {
        if (!isdigit(ch)) 
        {
            return false;
        }
    }
    
    return true;
}

void CollegeManagementSystem::showMenu() 
{
	system("cls");
    cout << "Welcome to the College Management System" << endl;
    cout << "Please select your desired field:" << endl;
    cout << "1. FSc (Pre-Medical)" << endl;
    cout << "2. FSc (Pre-Engineering)" << endl;
    cout << "3. ICS (Physics)" << endl;
    cout << "4. ICS (Statistics)" << endl;
    cout << "5. I.Com" << endl;
    cout << "Option: ";

    int choice = 0;
    bool validInput = false;
    
    while (!validInput) 
    {
        string input;
        getline(cin, input);
        if (cin.eof()) 
        {
            // Handle EOF
            cout << "Error: End of input detected. Exiting..." << endl;
            exit(EXIT_FAILURE); // Or handle the error as appropriate
        }
        else if (cin.fail()) 
        {
            // Handle other input failures
            cin.clear(); // Clear the error state
            cin.ignore(10000, '\n'); // Discard invalid input
            cout << "Error: Input failure detected. Please enter a valid number: ";
        }
        else 
        {
            if (isNumber(input)) 
            {
                try 
                {
                    choice = stoi(input); // Convert string to integer
                    
                    if (choice >= 1 && choice <= 5) 
                    {
                        validInput = true;
                    } 
                    else 
                    {
                        cout << "Invalid choice. Please enter a number between 1 and 5: ";
                    }
                } 
                catch (const out_of_range&) 
                {
                    cout << "Number is out of range. Please enter a number between 1 and 5: ";
                }
            } 
            else 
            {
                cout << "Invalid input. Please enter a valid number: ";
            }
        }
    }
    
    switch (choice) 
    {
        case 1: 
            fscPreMedical();
            break;
        case 2: 
            fscPreEngineering(); 
            break;
        case 3: 
            icsPhysics(); 
            break;
        case 4: 
            icsStatistics(); 
            break;
        case 5:
            iCom(); 
            break;
    }
}

