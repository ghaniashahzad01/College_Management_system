#include "studentType.h"
#include "personType.h"
#include "dateType_int.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <stdexcept>
#include <cstring>
#include <string>

using namespace std;

studentType::studentType() : personType(), student_id(0), dob(), size(0), capacity(100) 
{
    students = new studentType*[capacity];
    for(int i = 0; i < capacity; i++) {
        students[i] = nullptr;
    }
}

studentType::studentType(string fn, string ln, int age, dateType date, int id)
    : personType(age, fn, ln), dob(date), student_id(id), size(0), capacity(100) {
    students = new studentType*[capacity];
    for(int i = 0; i < capacity; i++) {
        students[i] = nullptr;
    }
}

studentType::studentType(const studentType& other)
    : personType(other), dob(other.dob), student_id(other.student_id), size(other.size), capacity(other.capacity) {
    students = new studentType*[capacity];
    for (int i = 0; i < size; ++i) {
        students[i] = new studentType(*other.students[i]);
    }
    for (int i = size; i < capacity; ++i) {
        students[i] = nullptr;
    }
}

studentType& studentType::operator=(const studentType& other) {
    if (this == &other)
        return *this;

    for (int i = 0; i < size; ++i) {
        delete students[i];
    }
    delete[] students;

    size = other.size;
    capacity = other.capacity;
    students = new studentType*[capacity];
    for (int i = 0; i < size; ++i) {
        students[i] = new studentType(*other.students[i]);
    }
    for (int i = size; i < capacity; ++i) {
        students[i] = nullptr;
    }
    
    return *this;
}

bool studentType::isNumeric(const string& str) {
    if (str.empty()) {
        return false;
    }
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

void studentType::expandArray() {
    int newCapacity = capacity * 2;
    studentType** newStudents = new studentType*[newCapacity];

    for (int i = 0; i < size; ++i) {
        newStudents[i] = students[i];
    }
    for (int i = size; i < newCapacity; ++i) {
        newStudents[i] = nullptr;
    }

    delete[] students;
    students = newStudents;
    capacity = newCapacity;
}

void studentType::setDob(dateType dob) {
    this->dob = dob;
}

dateType studentType::getDob() const {
    return dob;
}

void studentType::setStudentID(int id) {
    student_id = id;
}

int studentType::getStudentID() const {
    return student_id;
}

void studentType::print() {
    personType::getData();
    dob.printDate();
    cout << "Student ID: " << getStudentID() << endl;
}

void studentType::SetData() {
	system("cls");
    personType::setData();
    dob.setDate();
    while (true) {
        string idInput;
        try {
            cout << "Enter student ID: ";
            cin >> idInput;
            if (!isNumeric(idInput)) {
                cin.clear();
                cin.ignore(1000, '\n');
                throw invalid_argument("Student ID must be a positive integer.");
            }
            student_id = stoi(idInput);
            setStudentID(student_id);
            break;
        } catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << ". Please enter a valid student ID.\n";
        }
        if (cin.eof()) {
            cout << "End of input detected. Exiting function.\n";
            return;
        }
    }

    writeRecords();
}

void studentType::createStudent() {
    if (size == capacity) {
        expandArray();
    }

    students[size] = new studentType();
    cout << "Enter details for student " << size + 1 << ":\n";
    students[size]->SetData();
    ++size;

    cout << "Student added successfully.\n";
}

void studentType::writeRecords() {
    ofstream file("student.dat", ios::binary | ios::app);
    if (!file) {
        cerr << "Error opening file\n";
    }
    file.write(reinterpret_cast<const char*>(this), sizeof(studentType));
    file.close();
}

void studentType::searchData() {
    cout << "Enter the ID of the student you want to search for: ";

    string input;
    getline(cin, input);

    if (!isNumeric(input)) {
        cout << "Invalid input. Please enter a valid number.\n";
        return;
    }

    int searchID = stoi(input); // Convert string to integer

    ifstream file("student.dat", ios::binary);
    if (!file) {
        cerr << "Error opening file\n";
        return;
    }

    studentType record;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&record), sizeof(studentType))) {
        if (record.getStudentID() == searchID) {
            record.print();
            found = true;
            break;
        }
        if (cin.eof()) {
            cout << "End of input detected. Exiting function.\n";
            file.close();
            return;
        }
    }

    if (!found) {
        cout << "Record not found.\n";
    }

    file.close();
}

void studentType::updateData() {
    ifstream file("student.dat", ios::binary);
    if (!file) {
        cerr << "Error opening file\n";
        return;
    }

    ofstream tempFile("temp.dat", ios::binary);
    if (!tempFile) {
        cerr << "Error opening temp file\n";
        return;
    }

    string input;
    int searchID = 0;

    while (true) {
        cout << "Enter Student ID to update: ";
        getline(cin, input);

        if (isNumeric(input)) {
            searchID = stoi(input); // Convert string to integer
            break; // Exit loop if valid input
        } else {
            cout << "Invalid input. Please enter a valid number.\n";
        }
        if (cin.eof()) {
            cout << "End of input detected. Exiting function.\n";
            file.close();
            tempFile.close();
            return;
        }
    }

    studentType record;
    bool updated = false;

    while (file.read(reinterpret_cast<char*>(&record), sizeof(studentType))) {
        if (record.getStudentID() == searchID) {
            cout << "Current record:\n";
            record.print();

            cout << "Enter new data for the student:\n";
            record.SetData(); // Update the student data

            updated = true;
        }
        tempFile.write(reinterpret_cast<const char*>(&record), sizeof(studentType));
        if (cin.eof()) {
            cout << "End of input detected. Exiting function.\n";
            file.close();
            tempFile.close();
            return;
        }
    }

    if (updated) {
        cout << "Record updated successfully.\n";
    } else {
        cout << "Student ID not found.\n";
    }

    file.close();
    tempFile.close();

    remove("student.dat");
    rename("temp.dat", "student.dat");
}

void studentType::deleteData() {
    ifstream file("student.dat", ios::binary);
    if (!file) {
        cerr << "Error opening file\n";
        return;
    }

    ofstream tempFile("temp.dat", ios::binary);
    if (!tempFile) {
        cerr << "Error opening temp file\n";
        return;
    }

    string input;
    int deleteID = 0;

    while (true) {
        cout << "Enter Student ID to delete: ";
        getline(cin, input);

        if (isNumeric(input)) {
            deleteID = stoi(input); // Convert string to integer
            break; // Exit loop if valid input
        } else {
            cout << "Invalid input. Please enter a valid number.\n";
        }
        if (cin.eof()) {
            cout << "End of input detected. Exiting function.\n";
            file.close();
            tempFile.close();
            return;
        }
    }

    studentType record;
    bool deleted = false;

    while (file.read(reinterpret_cast<char*>(&record), sizeof(studentType))) {
        if (record.getStudentID() == deleteID) {
            deleted = true; // Mark as deleted
        } else {
            tempFile.write(reinterpret_cast<const char*>(&record), sizeof(studentType));
        }
        if (cin.eof()) {
            cout << "End of input detected. Exiting function.\n";
            file.close();
            tempFile.close();
            return;
        }
    }

    if (deleted) {
        cout << "Record deleted successfully.\n";
    } else {
        cout << "Student ID not found.\n";
    }

    file.close();
    tempFile.close();

    remove("student.dat");
    rename("temp.dat", "student.dat");
}

studentType::~studentType() {
    for (int i = 0; i < size; ++i) {
        delete students[i];
    }
    delete[] students;
}

ostream& operator<<(ostream& os, const studentType& student) 
{
    os << "First Name: " << student.firstName << endl; // Access protected member
    os << "Last Name: " << student.lastName << endl;  // Access protected member
    os << "Age: " << student.age << endl;             // Access protected member
    os << "Student ID: " << student.getStudentID() << endl;
    return os;
}

