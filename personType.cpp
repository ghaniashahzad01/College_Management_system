#include"personType.h"
#include"studentType.h"
#include<stdexcept>
#include<fstream>
#include<cstring>
#include<iostream>
using namespace std;

personType::personType()
{
    firstName[0] = '\0';
    lastName[0] = '\0';
    age = 0;
}

personType::personType(int a, string fn, string ln)
{
   strncpy(firstName, fn.c_str(), sizeof(firstName) - 1);
   firstName[sizeof(firstName) - 1] = '\0';

   strncpy(lastName, ln.c_str(), sizeof(lastName) - 1);
   lastName[sizeof(lastName) - 1] = '\0';

   age = a;

}

personType::personType(const personType& other)    //copy constructor
{
    strncpy(firstName, other.firstName, sizeof(firstName) - 1);
    firstName[sizeof(firstName) - 1] = '\0'; // Null-terminate the string

    strncpy(lastName, other.lastName, sizeof(lastName) - 1);
    lastName[sizeof(lastName) - 1] = '\0'; // Null-terminate the string

    age = other.age;
}

personType& personType::operator=(const personType& other) // Assignment operator overloading
{
    if (this == &other) return *this; // Self-assignment check

    // Copy the first name
    strncpy(firstName, other.firstName, sizeof(firstName) - 1);
    firstName[sizeof(firstName) - 1] = '\0';

    // Copy the last name
    strncpy(lastName, other.lastName, sizeof(lastName) - 1);
    lastName[sizeof(lastName) - 1] = '\0';

    // Copy the age
    age = other.age;

    return *this;
}


bool personType::isNumeric(const string& str)
{
    for (char c : str)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}


void personType::setData()
{
    while (true)
    {
        try {
            cout << "Enter first name (alphabets only, max 25 characters): ";
            cin.getline(firstName, 26);

            // Check for end-of-file (EOF) or input failure
            if (cin.eof() || cin.fail()) {
                cin.clear(); // Clear the error flag
                cin.ignore(1000, '\n'); // Ignore up to 1000 characters until newline
                throw runtime_error("Error: Input failed or EOF reached.");
            }

            // Check length
            if (strlen(firstName) >= 26 - 1) {
                cin.clear(); // Clear the error flag
                cin.ignore(1000, '\n'); // Ignore up to 1000 characters until newline
                throw length_error("Error: Name is too long. Maximum 25 characters allowed.");
            }

            // Check for non-alphabet characters
            for (int i = 0; firstName[i] != '\0'; ++i)
            {
                if (!isalpha(firstName[i])) {
                    throw invalid_argument("Error: Name should contain alphabets only.");
                }
            }

            break; // If everything is correct, exit the loop
        }
        catch (const exception& e)
        {
            cout << e.what() << " Please try again." << endl;
        }
    }
cin.ignore(1000, '\n');

    while (true)
    {
        try {
            cout << "Enter last name (alphabets only, max 25 characters): ";
            cin.getline(lastName, 26); 

            
            if (cin.eof() || cin.fail()) {
                cin.clear(); 
                cin.ignore(1000, '\n'); 
                throw runtime_error("Error: Input failed or EOF reached.");
            }

            // Check if input length exceeds 25 characters
            if (strlen(lastName) >= 25) {
                cin.clear(); // Clear the error flag
                cin.ignore(1000, '\n'); // Ignore up to 1000 characters until newline
                throw length_error("Error: Name is too long. Maximum 25 characters allowed.");
            }

            // Check for non-alphabetic characters
            bool isValid = true;
            for (int i = 0; lastName[i] != '\0'; ++i) {
                if (!isalpha(lastName[i])) {
                    isValid = false;
                    break; // Exit the loop as soon as non-alphabetic character is found
                }
            }

            if (!isValid) {
                throw invalid_argument("Error: Name should contain alphabets only.");
            }

            break; // If everything is correct, exit the loop

        } catch (const exception& e)
        {
            cout << e.what() << " Please try again." << endl;
        }
    }

    while (true)
    {
        string ageInput;
        cout << "Enter age: ";
        cin >> ageInput;
        cin.ignore(1000, '\n');

        // Check for end-of-file (EOF) or input failure
        if (cin.eof() || cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(1000, '\n'); // Ignore up to 1000 characters until newline
            throw runtime_error("Error: Input failed or EOF reached.");
        }

        if (!isNumeric(ageInput) || ageInput.empty())
        {
            cout << "Error: Age must be a positive integer. Please try again.\n";
        }
        else
        {
            age = stoi(ageInput);
            if (age <= 0)
            {
                cout << "Error: Age must be a positive integer. Please try again.\n";
            }
            else
            {
                break;
            }
        }
    }
}

void personType::getData()
{
    try
    {
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout<<"Age: "<<age<<endl;
    }
    catch (...)
    {
        cerr << "An error occurred during getData." << endl;
    }
}

personType::~personType()
{

}



