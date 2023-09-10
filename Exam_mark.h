#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct exam_mark {
    char record_book_number[8];
    int session_number;
    char subject_name[45];
    char mark[9];
};
class Exam_mark {
private:
    exam_mark exam_mark_structure;
public:
    string get_record_book_number() { return string(exam_mark_structure.record_book_number); }
    int get_session_number() { return exam_mark_structure.session_number; }
    string get_subject_name() { return string(exam_mark_structure.subject_name); }
    string get_mark() { return string(exam_mark_structure.mark); }   

    void set_record_book_number(string record_book_number) { strcpy_s(exam_mark_structure.record_book_number, record_book_number.c_str()); }
    void set_session_number(int session_number) { exam_mark_structure.session_number = session_number; }
    void set_subject_name(string subject_name) { strcpy_s(exam_mark_structure.subject_name, subject_name.c_str()); }
    void set_mark(string mark) { strcpy_s(exam_mark_structure.mark, mark.c_str()); }
    
};