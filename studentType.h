#ifndef STUDENT_TYPE_H
#define STUDENT_TYPE_H

#include "personType.h"
#include "dateType_int.h"
#include <string>
#include <fstream>
using namespace std;

class studentType : public personType {
public:
    studentType();
    studentType(string fn, string ln, int age, dateType date, int id);
    studentType(const studentType& other); // Copy constructor

    studentType& operator=(const studentType& other); // Assignment operator

    void setDob(dateType dob);
    dateType getDob() const;
    void setStudentID(int id);
    int getStudentID() const;
    void searchData();
    void print();
    void SetData();
    void createStudent();
    void writeRecords();
    void updateData();
    void deleteData();
    friend ostream& operator<<(ostream& os, const studentType& student);


    ~studentType();

private:
    int student_id;
    dateType dob;

    int size;
    int capacity;
    studentType** students;

    bool isNumeric(const std::string& str);
    void expandArray();
};



#endif




