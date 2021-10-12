//
// Created by Dang Minh Anh on 6/24/2021.
//

#ifndef QLDIEM_STUDENT_H
#define QLDIEM_STUDENT_H
#include "Student.h"
#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <regex>

using namespace std;
class Student {
    char id_num[10];
    char name[30];
    char gender[10];
    char date_of_birth[30];
    float gpa;
public:
    void getData();
    int getIDNum();
    void writeData();
    void showData();
    void modifyData();
    void deleteData();
    void displaySP();
    void displayAll();
    void save(ofstream& of);
    void load(ifstream& inf);
};




#endif //QLDIEM_STUDENT_H
