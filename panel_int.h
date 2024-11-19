#ifndef PANEL_INT_H_INCLUDED
#define PANEL_INT_H_INCLUDED

#include <iostream>
#include <iomanip>
#include<cctype>
#include <stdexcept>
#include "studentType.h"
#include"program.h"

using namespace std;

void displayMenu() {
	system("cls");
    cout << "\n\t+--------------------------------------+" << endl;
    cout << "\t¦           STUDENT MANAGEMENT         ¦" << endl;
    cout << "\t¦--------------------------------------¦" << endl;
    cout << "\t¦ 1. Enroll new student                ¦" << endl;
    cout << "\t¦ 2. Show existing data                ¦" << endl;
    cout << "\t¦ 3. Search data of a student          ¦" << endl;
    cout << "\t¦ 4. Update data of a student          ¦" << endl;
    cout << "\t¦ 5. Delete data                       ¦" << endl;
    cout << "\t¦ 6. Exit                              ¦" << endl;
    cout << "\t+--------------------------------------+" << endl;
}

bool containsOnlyDigits(const string& str) 
{
    if (str.empty()) return false; // Check for empty string
    for (char c : str) {
        if (!isdigit(c)) { // Check if each character is a digit
            return false;
        }
    }
    return true;
}

int getOption() {
    string input;
    int option;
    bool valid = false;

    while (!valid) 
{
        cout << "\nEnter your choice (1-6): ";
        getline(cin, input); // Read the entire line of input

        // Validate input
        if (containsOnlyDigits(input)) {
            try {
                option = stoi(input);
                if (option >= 1 && option <= 6) {
                    valid = true; 
                } 
				else {
                    cout << "Invalid input. Please enter a number between 1 and 6.\n";
                }
            } catch (invalid_argument& e) {
                cout << "Invalid input. Please enter a number between 1 and 6.\n";
            } catch (out_of_range& e) {
                cout << "Number out of range. Please enter a valid number between 1 and 6.\n";
            }
        } else {
            cout << "Invalid input. Please enter a valid number.\n";
        }

        // Clear input stream and ignore invalid input
        if (!valid) {
            cin.clear(); // Clear the error flags
            cin.ignore(10000, '\n'); // Ignore remaining characters in the input buffer
        }
    }

    return option;
}
    
void panel() {
    studentType s1;
    CollegeManagementSystem c1;
    int option;

    while (true) {
        displayMenu();
        option = getOption();

        switch(option) {
            case 1:
                c1.showMenu();
                s1.createStudent();
                break;
            case 2:
                 showData<studentType>("student.dat");
                break;
            case 3:
                s1.searchData();
                break;
            case 4:
                s1.updateData();
                break;
            case 5:
                s1.deleteData();
                break;
            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                return;
        }

        cout << "\nPress Enter to continue...";
        cin.ignore(1000, '\n');
        cin.get();
        
        if (cin.eof()) 
		{
            cout << "End of input detected. Exiting program." << endl;
            break;
        }
    }
}


#endif // PANEL_INT_H_INCLUDED
