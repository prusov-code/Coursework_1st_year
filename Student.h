#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct student {
    char surname[21];
    char name[21];
    char middlename[21];
    char birthday[11];
    char faculty[6];
    char department[7];
    char group[11];
    char record_book_number[8];
    int starting_year;
    int gender;
};
class Student {
private:
    student student_structure;
public:
    string get_surname() { return string(student_structure.surname); }
    string get_name() { return string(student_structure.name); }
    string get_middlename() { return string(student_structure.middlename); }
    string get_birthday() { return string(student_structure.birthday); }
    string get_faculty() { return string(student_structure.faculty); }
    string get_department() { return string(student_structure.department); }
    string get_group() { return string(student_structure.group); }
    string get_record_book_number() { return string(student_structure.record_book_number); }
    int get_starting_year() { return student_structure.starting_year; }
    int get_gender() { return student_structure.gender; }

    void set_surname(string surname) { strcpy_s(student_structure.surname, surname.c_str());}
    void set_name(string name) { strcpy_s(student_structure.name, name.c_str()); }
    void set_middlename(string middlename) { strcpy_s(student_structure.middlename, middlename.c_str()); }
    void set_birthday(string birthday) { strcpy_s(student_structure.birthday, birthday.c_str()); }
    void set_faculty(string faculty) { strcpy_s(student_structure.faculty, faculty.c_str()); }
    void set_department(string department) { strcpy_s(student_structure.department, department.c_str()); }
    void set_group(string group) { strcpy_s(student_structure.group, group.c_str()); }
    void set_record_book_number(string record_book_number) { strcpy_s(student_structure.record_book_number, record_book_number.c_str()); }
    void set_starting_year(int starting_year) { student_structure.starting_year = starting_year; }
    void set_gender(int gender) { student_structure.gender=gender; }
};