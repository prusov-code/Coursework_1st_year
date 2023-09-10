#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <vector>
#include <conio.h>
#include <files.h>
#include <default.h>
#include "Student.h"
#include "Student_list.h"
#include "Exam_mark.h"
#include "Exam_mark_list.h"


using namespace std;
using namespace CryptoPP;

class Database{
public:
    int exit_from_program() { return 0; }
bool is_number(const string & s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
bool check_date(string date) {
    vector <string> date_vector;
    stringstream tmp_stream(date);
    string tmp_str;
    while (getline(tmp_stream, tmp_str, '.')) {
        date_vector.push_back(tmp_str);
    }
    if (date_vector.size()!= 3) {
        return false;
    }
    if (stoi(date_vector[0]) < 1 || stoi(date_vector[0]) > 31) {
        return false;
    }
    if (stoi(date_vector[1]) < 1 || stoi(date_vector[1]) > 12) {
        return false;
    }
    if (stoi(date_vector[2]) < 1900 || stoi(date_vector[2]) > 2023) {
        return false;
    }
    return true;
}
struct Student find_student_by_record_book_number(string record_book_number) {
    int arr_size = check_db_file_size("Students_db.bin");
    Student_list Students_db;
    fill_student_list(Students_db, arr_size);
    bool record_book_state = false;
    int i = 0;
    for (i = 0; i < arr_size; i++) {
        if (Students_db[i].get_record_book_number() == record_book_number) {
            record_book_state = true;
            break;
        }
    }
    return Students_db[i];
}
bool check_record_book_number(string record_book_number) {
    int arr_size = check_db_file_size("Students_db.bin");
    Student_list Students_db;
    fill_student_list(Students_db, arr_size);
    bool record_book_state = false;
    for (int i = 0; i < arr_size; i++) {
        if (Students_db[i].get_record_book_number() == record_book_number) {
            record_book_state = true;
            break;
        }
    }
    return record_book_state;
}
bool is_file_exist(string file_path)
{
    bool exist_state = false;
    ifstream fin(file_path.c_str());
    if (fin.is_open()) {
        exist_state = true;
    }
    fin.close();
    return exist_state;
}
long check_db_file_size(string file_path) {
    ifstream file;
    long size = 10;
    file.open(file_path, ios::binary);
    file.seekg(0, SEEK_END);
    size = file.tellg();
    file.close();
    int arr_size = 0;
    if (file_path == "Students_db.bin") {
        arr_size = size / sizeof(Student);
    }
    else {
        arr_size = size / sizeof(Exam_mark);
    }
    return arr_size;
}
bool encrypt_file(string password, string file_input, string file_output) {
    FileSource* file_source = new FileSource(file_input.c_str(), true, new DefaultEncryptor(password.c_str(), new FileSink(file_output.c_str())));
    delete file_source;
    remove(file_input.c_str());
    return true;
}

bool decrypt_file(string password, string file_input, string file_output) {
    try {
        FileSource f(file_input.c_str(), true, new DefaultDecryptor(password.c_str(), new FileSink(file_output.c_str())));
    }
    catch (KeyBadErr) {
        remove(file_output.c_str());
        return false;
    }
    remove(file_input.c_str());
    return true;

}
void fill_exam_mark_list(Exam_mark_list& Exam_marks_db, int arr_size) {
    ifstream Exam_marks_file("Exam_marks_db.bin", ios::binary);
    for (int i = 0; i < arr_size; i++) {
        Exam_mark exam_mark;
        Exam_marks_file.read((char*)&exam_mark, sizeof(exam_mark));
        Exam_marks_db.push_back(exam_mark);
    }
    Exam_marks_file.close();
}
void fill_student_list(Student_list& student_list, int arr_size) {
    ifstream Students_file("Students_db.bin", ios::binary);
    for (int i = 0; i < arr_size; i++) {
        Student student;
        Students_file.read((char*)&student, sizeof(student));
        student_list.push_back(student);
    }
    Students_file.close();
}
};