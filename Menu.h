#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <files.h>
#include <default.h>
#include "Database.h"


using namespace std;

class Menu:public Database {
public:
    void students_menu() {
        string menu_number;
        while (true) {
            system("cls");
            cout << "------- �������� -------" << endl;
            cout << "��������� ��������:" << endl;
            cout << "1. ���������� ������ ���� ���������" << endl;
            cout << "2. ���������� ������ ��������� �� ������ ������" << endl;
            cout << "3. ��������� ���������� � ��������" << endl;
            cout << "4. �������� ��������" << endl;
            cout << "5. �������� ������ ��������" << endl;
            cout << "6. ������� ��������" << endl;
            cout << "7. ������������ ��������" << endl;
            cout << "8. ��������� � ������� ����" << endl;
            cout << "�������� �������� (1-8): ";
            cin >> menu_number;
            if (menu_number == "1" || menu_number == "2" || menu_number == "3" || menu_number == "4" || menu_number == "5" || menu_number == "6" || menu_number == "7" || menu_number == "8") {
                break;
            }
        }
        if (menu_number == "1") {
            students_table("");
        }
        else if (menu_number == "2") {
            system("cls");
            cout << "------- ������ ��������� �� ������ ������ -------" << endl;
            bool repeat = true;
            while (repeat == true) {
                string group;
                cout << "������� ����� ������: ";
                cin >> group;
                if (group.length() > 10 || group.length() < 1) {
                    cout << "[ERROR]: ������� ������ ����� ������. ����� ������ ���������� �� 1 �� 10 ��������" << endl;
                }
                else {
                    students_table(group);
                }
            }
        }
        else if (menu_number == "3") {
            system("cls");
            cout << "------- ��������� ���������� � �������� -------" << endl;
            string record_book_number = "";
            while (1) {
                cout << "������� ����� �������� ������ �������� ��� ������: ";
                cin >> record_book_number;
                if (record_book_number.length() == 7) {
                    break;
                }
                else {
                    cout << endl << "[ERROR]: ������� ������ ����� �������� ������! ����� ������ ���������� 7 ��������" << endl;
                }
            }
            bool record_book_state = check_record_book_number(record_book_number);
            if (record_book_state == true) {
                Student Student_info = find_student_by_record_book_number(record_book_number);
                system("cls");
                print_student_info(Student_info);
                cout << endl << "[SUCCESS]: ������� ������� ������!";
                cout << endl << "[INFO]: ������� ����� ������� ����� ��������� � ���� ����������" << endl;
                system("pause");
                students_menu();
            }
            else {
                cout << endl << "[ERROR]: ������� � ������� �������� ������ �" << record_book_number << "� �� ������.";
                cout << endl << "[INFO]: ������� ����� ������� ����� ��������� � ���� ����������" << endl;
                system("pause");
                students_menu();
            }
        }
        else if (menu_number == "4") {
            add_new_student();
        }
        else if (menu_number == "5") {
            system("cls");
            cout << "------- ��������� ���������� � �������� -------" << endl;
            string record_book_number = "";
            while (true) {
                cout << "������� ����� �������� ������ �������� ��� ������: ";
                cin >> record_book_number;
                if (record_book_number.length() == 7) {
                    break;
                }
                else {
                    cout << endl << "[ERROR]: ������� ������ ����� �������� ������! ����� ������ ���������� 7 ��������" << endl;
                }
            }
                bool record_book_state = check_record_book_number(record_book_number);
                if (record_book_state == true) {
                    Student Student_info = find_student_by_record_book_number(record_book_number);
                    while (true) {
                        system("cls");
                        print_student_info(Student_info);
                        cout << endl << "------- ��������� ���������� � �������� -------" << endl;
                        cout << endl << "��������� ��������:" << endl;
                        cout << "1. �������� ���" << endl;
                        cout << "2. �������� �������" << endl;
                        cout << "3. �������� ��������" << endl;
                        cout << "4. �������� ���� ��������" << endl;
                        cout << "5. �������� ��� ����������� � �����������" << endl;
                        cout << "6. �������� ��������� (��������)" << endl;
                        cout << "7. �������� �������" << endl;
                        cout << "8. �������� ������" << endl;
                        cout << "9. �������� ���" << endl;
                        cout << "10. ����� � ����" << endl;
                        string sub_menu_number;
                        while (true) {
                            cout << "�������� �������� (1-10): ";
                            cin >> sub_menu_number;
                            if (sub_menu_number == "1" || sub_menu_number == "2" || sub_menu_number == "3" || sub_menu_number == "4" || sub_menu_number == "5" || sub_menu_number == "6" || sub_menu_number == "7" || sub_menu_number == "8" || sub_menu_number == "9" || sub_menu_number == "10") {
                                break;
                            }
                            else {
                                cout << endl << "[ERROR]: ������� ������� ��������. ������� ����� �� 1 �� 10" << endl;
                            }
                        }
                        while (true) {
                            string temp_string;
                            if (sub_menu_number == "1") {
                                cout << "������� ����� ��� ��������: ";
                                cin >> temp_string;
                                if (temp_string.length() < 1 || temp_string.length() > 20) {
                                    cout << "[ERROR]: ������� ������� ���! ����� ������ ���������� �� 1 �� 20 ��������"<<endl;
                                }
                                else {
                                    Student_info.set_name(temp_string);
                                    break;
                                }
                            }
                            else if (sub_menu_number == "2") {
                                cout << "������� ����� ������� ��������: ";
                                cin >> temp_string;
                                if (temp_string.length() < 1 || temp_string.length() > 20) {
                                    cout << "[ERROR]: ������� ������� �������! ����� ������ ���������� �� 1 �� 20 ��������" << endl;
                                }
                                else {
                                    Student_info.set_surname(temp_string);
                                    break;
                                }
                            }
                            else if (sub_menu_number == "3") {
                                cout << "������� ����� �������� ��������: ";
                                cin >> temp_string;
                                if (temp_string.length() < 1 || temp_string.length() > 20) {
                                    cout << "[ERROR]: ������� ������� ��������! ����� ������ ���������� �� 1 �� 20 ��������" << endl;
                                }
                                else {
                                    Student_info.set_middlename(temp_string);
                                    break;
                                }
                            }
                            else if (sub_menu_number == "4") {
                                cout << "������� ����� ���� �������� �������� (� ������� 09.09.2009): ";
                                cin >> temp_string;
                                if (temp_string.length() < 1 || temp_string.length() > 10) {
                                    cout << "[ERROR]: ������� ������ ���� ��������! ����� ������ ���������� 10 ��������" << endl;
                                }
                                else {
                                    if (check_date(temp_string) == true) {
                                        Student_info.set_birthday(temp_string);
                                        break;
                                    }
                                    else {
                                        cout << endl << "[ERROR]: ������� ������� ���� �������� ��������! ������� ���� � ������� 01.10.2010" << endl;
                                    }
                                }
                            }
                            else if (sub_menu_number == "5") {
                                cout << "������� ����� ��� ����������� � ����������� ��������: ";
                                cin >> temp_string;
                                if (temp_string.length() != 4 || is_number(temp_string) == false) {
                                    cout << "[ERROR]: ������� ������ ��� ����������� � �����������! ����� ������ ���������� 4 �������" << endl;
                                }
                                else {
                                    Student_info.set_starting_year(stoi(temp_string));
                                    break;
                                }
                            }
                            else if (sub_menu_number == "6") {
                                cout << "������� ����� ���������: ";
                                cin >> temp_string;
                                if (temp_string.length() < 1 || temp_string.length() > 5) {
                                    cout << "[ERROR]: ������� ������ ���������! ����� ������ ���������� �� 1 �� 5 ��������" << endl;
                                }
                                else {
                                    Student_info.set_faculty(temp_string);
                                    break;
                                }
                            }
                            else if (sub_menu_number == "7") {
                                cout << "������� ����� �������: ";
                                cin >> temp_string;
                                if (temp_string.length() < 1 || temp_string.length() > 6) {
                                    cout << "[ERROR]: ������� ������� �������! ����� ������ ���������� �� 1 �� 6 ��������" << endl;
                                }
                                else {
                                    Student_info.set_department(temp_string);
                                    break;
                                }
                            }
                            else if (sub_menu_number == "8") {
                                cout << "������� ����� ������: ";
                                cin >> temp_string;
                                if (temp_string.length() != 10) {
                                    cout << "[ERROR]: ������� ������� ������! ����� ������ ���������� 10 ��������" << endl;
                                }
                                else {
                                    Student_info.set_group(temp_string);
                                    break;
                                }
                            }
                            else if (sub_menu_number == "9") {
                                cout << "������� ��� �������� (�/�): ";
                                cin >> temp_string;
                                if (temp_string == "�" || temp_string == "�") {
                                    Student_info.set_gender(1);
                                    break;
                                }
                                else if (temp_string == "�" || temp_string == "�") {
                                    Student_info.set_gender(0);
                                    break;
                                }
                                else {
                                    cout << endl << "[ERROR]: ������� ������ ��� ��������! ���������� ������ �̻ ��� �ƻ" << endl;
                                }
                            }
                            else if (sub_menu_number == "10") {
                                students_menu();
                                break;
                            }
                        }
                        change_student_info(Student_info, record_book_number);
                    }
                }
                else {
                    cout << endl << "[ERROR]: ������� � ������� �������� ������ �" << record_book_number << "� �� ������.";
                    cout << endl << "[INFO]: ������� ����� ������� ����� ��������� � ���� ����������" << endl;
                    system("pause");
                    students_menu();
                }

        }
        else if (menu_number == "6") {
            system("cls");
            cout << "------- �������� �������� -------" << endl;
            string record_book_number = "";
            while (true) {
                cout << "������� ����� �������� ������ �������� �������� ���������� �������: ";
                cin >> record_book_number;
                if (record_book_number.length() == 7) {
                    break;
                }
                else {
                    cout << endl << "[ERROR]: ������� ������ ����� �������� ������! ����� ������ ���������� 7 ��������" << endl;
                }
            }
                bool record_book_state = check_record_book_number(record_book_number);
                if (record_book_state == true) {
                    Student Student_info = find_student_by_record_book_number(record_book_number);
                    system("cls");
                    print_student_info(Student_info);
                    cout << "------- �������� �������� -------" << endl;
                    cout << "�� ������� ��� ������ ������� ��������?" << endl;
                    cout << "1. ��" << endl << "2. ���" << endl;
                    string temp_string;
                    while (true) {
                        cout << "������� 1 ��� 2 ��� ������������� ��� ������ ��������: ";
                        cin >> temp_string;
                        if (temp_string == "1" || temp_string == "2") {
                            break;
                        }
                        else {
                            cout << "������� ������� �������. ������� 1 ��� 2 ��� ������������� ��� ������ �������� ������ ��������." << endl;
                        }
                    }
                    if (temp_string == "1") {
                        delete_student(record_book_number);
                    }
                    else if (temp_string == "2") {
                        cout << endl << "[INFO]: �������� �������� ��������." << endl;
                        cout << endl << "[INFO]: ������� ����� ������� ����� ��������� � ���� ����������" << endl;
                        system("pause");
                        students_menu();
                    }
                }
                else {
                    cout << endl << "[ERROR]: ������� � ������� �������� ������ �" << record_book_number << "� �� ������.";
                    cout << endl << "[INFO]: ������� ����� ������� ����� ��������� � ���� ����������" << endl;
                    system("pause");
                    students_menu();
                }
        }
        else if (menu_number == "7") {
            academic_performance("", "");
        }
        else if (menu_number == "8") {
            main_menu();
        }
    }
    void students_table(string group) {
        system("cls");
        bool check_group = false;
        string title;
        if (group != "") {
            check_group = true;
            title = "|������ ���� ��������� " + group;
        }
        else {
            title = "|������ ���� ���������";
        }
        print_table_line(108);

        cout.fill(' '); cout.width(108); cout << left << title; cout << "|" << endl;
        print_table_line(108);
        cout.width(23); cout.fill(' '); cout << left << "|����� �������� ������";
        cout << left << "|"; cout.width(22); cout << "�������";
        cout << left << "|"; cout.width(22); cout << "���";
        cout << left << "|"; cout.width(22); cout << "��������";
        cout << left << "|"; cout.width(15); cout << "����� ������";
        cout << left << "|" << endl;
        print_table_line(108);
        int arr_size = check_db_file_size("Students_db.bin");
        Student_list Students_db;
        fill_student_list(Students_db, arr_size);
        if (check_group == true) {
            for (int i = 0; i < arr_size; i++) {
                if (Students_db[i].get_group() == group) {
                    cout << "|"; cout.width(22); cout.fill(' '); cout << left << Students_db[i].get_record_book_number();
                    cout << left << "|"; cout.width(22); cout << Students_db[i].get_surname();
                    cout << left << "|"; cout.width(22); cout << Students_db[i].get_name();
                    cout << left << "|"; cout.width(22); cout << Students_db[i].get_middlename();
                    cout << left << "|"; cout.width(15); cout << Students_db[i].get_group() << "|" << endl;
                    print_table_line(108);
                }
            }
        }
        else {
            for (int i = 0; i < arr_size; i++) {
                cout << "|"; cout.width(22); cout.fill(' '); cout << left << Students_db[i].get_record_book_number();
                cout << left << "|"; cout.width(22); cout << Students_db[i].get_surname();
                cout << left << "|"; cout.width(22); cout << Students_db[i].get_name();
                cout << left << "|"; cout.width(22); cout << Students_db[i].get_middlename();
                cout << left << "|"; cout.width(15); cout << Students_db[i].get_group() << "|" << endl;
                print_table_line(108);
            }
        }
        cout << endl << "[INFO]: ��� ��������� ���������� � �������� �������������� ������� ���������� ���������� � �������� � ���� ����������";
        cout << endl << "[SUCCESS]: ������� ����� ������� ����� ��������� � ���� ����������" << endl;
        system("pause");
        students_menu();
    }
    void print_student_info(Student Student_info) {
        cout << "------- ���������� � �������� -------" << endl;
        cout << "����� �������� ������: " << Student_info.get_record_book_number() << endl;
        cout << "��� ��������: " << Student_info.get_surname() << " " << Student_info.get_name() << " " << Student_info.get_middlename() << endl;
        cout << "���� ��������: " << Student_info.get_birthday() << endl;
        cout << "��� ����������� � �����������: " << Student_info.get_starting_year() << endl;
        cout << "��������� (��������): " << Student_info.get_faculty() << endl;
        cout << "�������: " << Student_info.get_department() << endl;
        cout << "������: " << Student_info.get_group() << endl;
        char student_gender[8];
        if (Student_info.get_gender() == 1) {
            strcpy_s(student_gender, "�������");
        }
        else {
            strcpy_s(student_gender, "�������");
        }
        cout << "���: " << student_gender << endl;
    }
    void print_table_line(int length) {
        cout.fill('-'); cout.width(length); cout << left << "|"; cout << right << "|" << endl;
    }
    void add_new_student() {
        system("cls");
        string file_path = "Students_db.bin";
        cout << "------- ���������� ������ �������� -------" << endl;
        string temp_string;
        Student Student_info;
        while (1) {
            cout << "������� ������� ��������: ";
            cin >> temp_string;
            if (temp_string.length() > 20 || temp_string.length() < 1) {
                cout << endl << "[ERROR]: ������� ������� ������� ��������! ����� ������ ���������� �� 1 �� 20 ��������" << endl;
            }
            else {
                Student_info.set_surname(temp_string);
                break;
            }
        }
        while (1) {
            cout << "������� ��� ��������: ";
            cin >> temp_string;
            if (temp_string.length() > 20 || temp_string.length() < 1) {
                cout << endl << "[ERROR]: ������� ������� ��� ��������! ����� ������ ���������� �� 1 �� 20 ��������" << endl;
            }
            else {
                Student_info.set_name(temp_string);
                break;
            }
        }
        while (1) {
            cout << "������� �������� ��������: ";
            cin >> temp_string;
            if (temp_string.length() > 20 || temp_string.length() < 1) {
                cout << endl << "[ERROR]: ������� ������� �������� ��������! ����� ������ ���������� �� 1 �� 20 ��������" << endl;
            }
            else {
                Student_info.set_middlename(temp_string);
                break;
            }
        }
        while (1) {
            cout << "������� �����,�����,��� �������� �������� (� ������� 09.09.2000): ";
            cin >> temp_string;
            if (temp_string.length() > 10 || temp_string.length() < 1) {
                cout << endl << "[ERROR]: ������� ������� ���� �������� ��������! ����� ������ ���������� 10 ��������" << endl;
            }
            else {
                if (check_date(temp_string)==true) {
                    Student_info.set_birthday(temp_string);
                    break;
                }
                else {
                    cout << endl << "[ERROR]: ������� ������� ���� �������� ��������! ������� ���� � ������� 01.10.2010" << endl;
                }   
            }
        }
       
        while (1) {
            cout << "������� ��������� (��������) ��������: ";
            cin >> temp_string;
            if (temp_string.length() > 5 || temp_string.length() < 1) {
                cout << endl << "[ERROR]: ������� ������ ��������� (��������)! ����� ������ ���������� �� 1 �� 5 ��������" << endl;
            }
            else {
                Student_info.set_faculty(temp_string);
                break;
            }
        }
        while (1) {
            cout << "������� ������� ��������: ";
            cin >> temp_string;
            if (temp_string.length() > 6 || temp_string.length() < 1) {
                cout << endl << "[ERROR]: ������� ������� �������! ����� ������ ���������� �� 1 �� 6 ��������" << endl;
            }
            else {
                Student_info.set_department(temp_string);
                break;
            }
        }
        while (1) {
            cout << "������� ������ ��������: ";
            cin >> temp_string;
            if (temp_string.length() != 10) {
                cout << endl << "[ERROR]: ������� ������� ������! ����� ������ ���������� 10 ��������" << endl;
            }
            else {
                Student_info.set_group(temp_string);
                break;
            }
        }
        while (1) {
            cout << "������� ����� �������� ������ �������� (� ������� 12�4567): ";
            cin >> temp_string;
            if (temp_string.length() != 7) {
                cout << endl << "[ERROR]: ������� ������ ����� �������� ������! ����� ������ ���������� 7 ��������" << endl;
            }
            else {
                bool record_book_state = check_record_book_number(temp_string);
                if (record_book_state == true) {
                    cout << endl << "[ERROR]: ������� � ����� ������� �������� ������ ��� ���� � ���� ������!" << endl;
                }
                else {
                    Student_info.set_record_book_number(temp_string);
                    break;
                }
            }
        }
        while (1) {
            cout << "������� ��� ����������� � ��������: ";
            cin >> temp_string;
            if (temp_string.length() != 4 || is_number(temp_string) == false) {
                cout << endl << "[ERROR]: ������� ������ ��� ����������� � ��������! ����� ������ ���������� 4 �������" << endl;
            }
            else {
                Student_info.set_starting_year(stoi(temp_string));
                break;
            }
        }
        while (1) {
            cout << "������� ��� �������� (�/�): ";
            cin >> temp_string;
            if (temp_string == "�" || temp_string == "�") {
                Student_info.set_gender(1);
                break;
            }
            else if (temp_string == "�" || temp_string == "�") {
                Student_info.set_gender(0);
                break;
            }
            else {
                cout << endl << "[ERROR]: ������� ������ ��� ��������! ���������� ������ �̻ ��� �ƻ" << endl;
            }
        }
        ofstream students_db_file;
        students_db_file.open(file_path, ios::binary | ios::app);
        if (students_db_file.is_open()) {
            students_db_file.write((char*)&Student_info, sizeof(Student_info));
            cout << endl << "[SUCCESS]: ������� ������� ��������! ������� ����� ������� ����� ��������� � ����" << endl;
            students_db_file.close();
            system("pause");
            students_menu();
        }
        else {
            students_db_file.close();
            cout << "[ERROR]: ������ �������� �����!";
        }
    }
    void delete_student(string record_book_number) {
        int arr_size = check_db_file_size("Students_db.bin");
        Student_list Students_db;
        fill_student_list(Students_db, arr_size);
        Student New_student_db[100];
        int q = 0;
        for (int i = 0; i < arr_size; i++) {
            if (Students_db[i].get_record_book_number() != record_book_number) {
                New_student_db[q] = Students_db[i];
                q++;
            }
        }
        ofstream students_db_write_file;
        students_db_write_file.open("Students_db.bin", ios::binary | ios::app);
        if (students_db_write_file.is_open()) {
            ofstream clear_file;
            clear_file.open("Students_db.bin", std::ofstream::out | std::ofstream::trunc);
            clear_file.close();
            for (int i = 0; i < arr_size - 1; i++) {
                if (New_student_db[i].get_name() != "") {
                    students_db_write_file.write((char*)&New_student_db[i], sizeof(New_student_db[i]));
                }
            }
            cout << endl << "[SUCCESS]: ������� ������� ������!" << endl;
            cout << endl << "[INFO]: ������� ����� ������� ����� ��������� � ���� ����������" << endl;
            students_db_write_file.close();
            system("pause");
            students_menu();

        }
        else {
            cout << endl << "[ERROR]: ������ �������� �����!";
            cout << endl << "[INFO]: ������� ����� ������� ����� ��������� � ���� ����������" << endl;
            students_db_write_file.close();
            system("pause");
            students_menu();
        }
    }
    void change_student_info(Student Student_info, string record_book_number) {
        int arr_size = check_db_file_size("Students_db.bin");
        Student_list Students_db;
        fill_student_list(Students_db, arr_size);
        ofstream students_db_write_file;
        students_db_write_file.open("Students_db.bin", ios::binary | ios::app);
        if (students_db_write_file.is_open()) {
            ofstream clear_file;
            clear_file.open("Students_db.bin", std::ofstream::out | std::ofstream::trunc);
            clear_file.close();
            for (int i = 0; i < arr_size; i++) {
                if (Students_db[i].get_record_book_number() == record_book_number) {
                    Students_db[i] = Student_info;
                }
                students_db_write_file.write((char*)&Students_db[i], sizeof(Students_db[i]));
            }
            cout << endl << "[SUCCESS]: ���������� � �������� ������� ��������!" << endl;
            cout << endl << "[INFO]: ������� ����� ������� ����� ��������� � ���� ��������� ��������" << endl;
            students_db_write_file.close();
            system("pause");
        }
        else {
            cout << endl << "[ERROR]: ������ �������� �����!";
            cout << endl << "[INFO]: ������� ����� ������� ����� ��������� � ���� ��������� ��������" << endl;
            students_db_write_file.close();
            system("pause");
            students_menu();
        }
    }
    void academic_performance(string session_number, string record_book_number) {
        system("cls");
        bool record_book_state = false;
        if (session_number == "") {
            cout << "------- ������������ �������� -------" << endl;
            while (1) {
                cout << "������� ����� �������� ������ ��������: ";
                record_book_number = "";
                cin >> record_book_number;
                if (record_book_number.length() == 7) {
                    record_book_state = check_record_book_number(record_book_number);
                    break;
                }
                else {
                    cout << endl << "[ERROR]: ������� ������ ����� �������� ������! ����� ������ ���������� 7 ��������" << endl;
                }
            }
        }
        else {
            record_book_state = true;
        }
        if (record_book_state == true) {
            Student Student_info = find_student_by_record_book_number(record_book_number);
            system("cls");
            print_student_info(Student_info);
            cout << endl << "------- ������������ �������� -------" << endl;
            if (session_number == "") {
                while (1) {
                    cout << "������� ����� ������ � ������� ����� �������� (1-9): ";
                    cin >> session_number;
                    if (is_number(session_number) == false || stoi(session_number) > 9 || stoi(session_number) < 1) {
                        cout << "[ERROR]: ������� ������ ����� ������! ������� ����� �� 1 �� 9" << endl;
                    }
                    else {
                        break;
                    }
                }
            }
            string temp_string;
            while (1) {
                cout << endl;
                print_academic_perfomance(session_number, Student_info);
                cout << endl << "------- �������� � ������������� �������� -------" << endl;
                cout << "1. �������� ����� ������ �� " << session_number << " ������" << endl;
                cout << "2. �������� ������ �� " << session_number << " ������" << endl;
                cout << "3. ������� ������ �� " << session_number << " ������" << endl;
                cout << "4. ������� ������ ������" << endl;
                cout << "5. ����� � ����" << endl;
                cout << endl << "�������� �������� (1-4): ";
                cin >> temp_string;
                if (temp_string == "1") {
                    add_new_exam_mark(session_number, Student_info);
                    break;

                }
                else if (temp_string == "2") {
                    change_exam_mark(session_number, Student_info.get_record_book_number());
                    break;
                }
                else if (temp_string == "3") {
                    delete_exam_mark(session_number, Student_info.get_record_book_number());
                    break;
                }
                else if (temp_string == "4") {
                    while (1) {
                        cout << "������� ����� ������ � ������� ����� �������� (1-9): ";
                        cin >> session_number;
                        if (is_number(session_number) == false || stoi(session_number) > 9 || stoi(session_number) < 1) {
                            cout << "[ERROR]: ������� ������ ����� ������! ������� ����� �� 1 �� 9" << endl;
                        }
                        else {
                            academic_performance(session_number, record_book_number);
                            break;
                        }
                    }
                }
                else if (temp_string == "5") {
                    students_menu();
                    break;
                }
                else {
                    cout << "������� ������ ����� ��������! ������� ����� �� 1 �� 4." << endl;
                }
            }
        }
        else {
            cout << endl << "[ERROR]: ������� � ������� �������� ������ �" << record_book_number << "� �� ������.";
            cout << endl << "[INFO]: ������� ����� ������� ����� ��������� � ���� ����������" << endl;
            system("pause");
            students_menu();
        }

    }
    void print_academic_perfomance(string session_number, Student Student_structure) {
        string fio = string(Student_structure.get_surname()) + " " + string(Student_structure.get_name())[0] + ". " + string(Student_structure.get_middlename())[0] + ".";
        int arr_size = check_db_file_size("Exam_marks_db.bin");
        Exam_mark_list Exam_marks_db;
        fill_exam_mark_list(Exam_marks_db, arr_size);
        print_table_line(80);
        string title = "|������ ������ �������� " + fio + " �� " + string(session_number) + " ������";
        cout.fill(' '); cout.width(79); cout << left << title; cout << " | " << endl;
        print_table_line(80);
        cout.width(3); cout.fill(' '); cout << left << "|�";
        cout << left << "|"; cout.width(45); cout << "�������";
        cout << left << "|"; cout.width(30); cout << "������";
        cout << left << "|" << endl;
        print_table_line(80);
        int mark_count = 0;
        for (int i = 0; i < arr_size; i++) {
            if (Exam_marks_db[i].get_record_book_number()==Student_structure.get_record_book_number() && Exam_marks_db[i].get_session_number() == stoi(session_number)) {
                mark_count += 1;
                cout << "|";
                cout.width(2); cout.fill(' '); cout << left << mark_count;
                cout << left << "|"; cout.width(45); cout << Exam_marks_db[i].get_subject_name();
                cout << left << "|"; cout.width(30); cout << Exam_marks_db[i].get_mark();
                cout << left << "|" << endl;
                print_table_line(80);
            }
        }

    }
    void add_new_exam_mark(string session_number, Student Student_info) {
        cout << endl << "------- �������� ������ �� ������ -------" << endl;
        string subject_name;
        while (1) {
            cout << "������� �������� ��������: ";
            cin.seekg(cin.eof());
            getline(cin, subject_name);
            if (subject_name.length() < 1 || subject_name.length() > 45) {
                cout << "[ERROR]: ������� ������� �������� ��������! �������� �������� ������ ���������� �� 1 �� 45 ��������" << endl;
            }
            else {
                int arr_size = check_db_file_size("Exam_marks_db.bin");
                Exam_mark_list Exam_marks_db;
                fill_exam_mark_list(Exam_marks_db, arr_size);
                bool subject_in_list = false;
                int subjects_count = 0;
                for (int i = 0; i < arr_size; i++) {
                    if (Student_info.get_record_book_number() == Exam_marks_db[i].get_record_book_number() && Exam_marks_db[i].get_session_number() == stoi(session_number)) {
                        subjects_count++;
                    }
                    if (Student_info.get_record_book_number() == Exam_marks_db[i].get_record_book_number() && Exam_marks_db[i].get_session_number() == stoi(session_number) && Exam_marks_db[i].get_subject_name() == subject_name) {
                        subject_in_list = true;
                        cout << "[ERROR]: ������ �� ������� �������� ��� ����������! ������� ������ �������� ��������" << endl;
                    }
                }
                if (subjects_count > 9) {
                    cout << "[ERROR]: ������������ ���������� ������ �� ���� ������ - 10 ����. ������� ������ ������ ����� �������� �����"<<endl;
                    cout <<"[INFO]: ������� ����� ������� ����� ��������� � ����" << endl;
                    system("pause");
                    academic_performance(session_number, Student_info.get_record_book_number());
                }
                if (subject_in_list == false && subjects_count<10) {
                    break;
                }
            }
        } 
        string mark;
        while (1) {
            cout << "�������� ������ (1-6): " << endl;
            cout << "1. ������ 5" << endl;
            cout << "2. ������ 4" << endl;
            cout << "3. ������ 3" << endl;
            cout << "4. ������ 2" << endl;
            cout << "5. ������ ������" << endl;
            cout << "6. ������ ��������" << endl;
            cout << "������� ����� ������ (1-6): ";
            cin >> mark;
            if (is_number(mark) == false || stoi(mark) > 6 || stoi(mark) < 1) {
                cout << "[ERROR]: ������� ������ ����� ������! ������� ����� �� 1 �� 6" << endl;
            }
            else {
                break;
            }
        }
        if (mark == "1") {
            mark = "5";
        }
        else if (mark == "2") {
            mark = "4";
        }
        else if (mark == "3") {
            mark = "3";
        }
        else if (mark == "4") {
            mark = "2";
        }
        else if (mark == "5") {
            mark = "�����";
        }
        else if (mark == "6") {
            mark = "�������";
        }
        Exam_mark Exam_mark_structure;
        Exam_mark_structure.set_session_number(stoi(session_number));
        Exam_mark_structure.set_record_book_number(Student_info.get_record_book_number());
        Exam_mark_structure.set_subject_name(subject_name);
        Exam_mark_structure.set_mark(mark);
        ofstream exam_marks_db_file;
        exam_marks_db_file.open("Exam_marks_db.bin", ios::binary | ios::app);
        if (exam_marks_db_file.is_open()) {
            exam_marks_db_file.write((char*)&Exam_mark_structure, sizeof(Exam_mark_structure));
            cout << endl << "[SUCCESS]: ������ �� ������ ������� ���������! ������� ����� ������� ����� ��������� � ���� ������ ��������" << endl;
            exam_marks_db_file.close();
            system("pause");
            academic_performance(session_number, Student_info.get_record_book_number());
        }
        else {
            exam_marks_db_file.close();
            cout << "[ERROR]: ������ �������� �����!";
        }
    }
    void delete_exam_mark(string session_number, string record_book_number) {
        cout << endl << "------- ������� ������ �� ������ -------" << endl;
        string mark_number;
        while (1) {
            cout << "������� ���������� ����� ������ ������� ������� ������� (���������� ����� ������ ����� ���������� � ������� ����): ";
            cin >> mark_number;
            if (is_number(mark_number)) {
                int arr_size = check_db_file_size("Exam_marks_db.bin");
                Exam_mark_list Exam_marks_db;
                fill_exam_mark_list(Exam_marks_db, arr_size);
                Exam_mark_list New_exam_marks_db;
                int rows_count = 0;
                for (int i = 0; i < arr_size; i++) {
                    if (Exam_marks_db[i].get_record_book_number() == record_book_number && Exam_marks_db[i].get_session_number() == stoi(session_number)) {
                        New_exam_marks_db.push_back(Exam_marks_db[i]);
                        rows_count++;
                    }
                }
                if (rows_count >= stoi(mark_number) && rows_count > 0) {
                    cout << "�� ����������� ������� ���������� ������:" << endl << endl;
                    print_table_line(77);
                    string title = "|������ �� " + string(session_number) + " ������";
                    cout.fill(' '); cout.width(76); cout << left << title; cout << " | " << endl;
                    print_table_line(77);
                    cout.width(46); cout.fill(' '); cout << left << "|�������";
                    cout << left << "|"; cout.width(30); cout << "������";
                    cout << left << "|" << endl;
                    print_table_line(77);
                    cout << "|";
                    cout.width(45); cout.fill(' '); cout << left << New_exam_marks_db[stoi(mark_number) - 1].get_subject_name();
                    cout << left << "|"; cout.width(30); cout << New_exam_marks_db[stoi(mark_number) - 1].get_mark();
                    cout << left << "|" << endl;
                    print_table_line(77);
                    string temp_string;
                    while (1) {
                        cout << "�� ������� ��� ������ ������� ������ ������?" << endl;
                        cout << "1. ��" << endl;
                        cout << "2. ���" << endl;
                        cout << "������� ����� ������ (1-2): ";
                        cin >> temp_string;
                        if (temp_string == "1" || temp_string == "2") {
                            break;
                        }
                        else {
                            cout << "[ERROR]: ������� ������ ����� ������. ��������� �������." << endl;
                        }
                    }
                    if (temp_string == "2") {
                        cout << "[INFO]: �������� ������ ��������." << endl;
                        cout << "[INFO]: ������� ����� ������� ����� ��������� � ���� ������������..." << endl;
                        system("pause");
                        academic_performance(session_number, record_book_number);
                        break;
                    }
                    ofstream clear_file;
                    clear_file.open("Exam_marks_db.bin", std::ofstream::out | std::ofstream::trunc);
                    clear_file.close();
                    ofstream exam_marks_db_file;
                    exam_marks_db_file.open("Exam_marks_db.bin", ios::binary | ios::app);
                    if (exam_marks_db_file.is_open()) {
                        for (int i = 0; i < arr_size; i++) {
                            if (Exam_marks_db[i].get_subject_name()== New_exam_marks_db[stoi(mark_number) - 1].get_subject_name() && Exam_marks_db[i].get_record_book_number()==record_book_number && Exam_marks_db[i].get_session_number()==stoi(session_number)) {}
                            else {
                                exam_marks_db_file.write((char*)&Exam_marks_db[i], sizeof(Exam_marks_db[i]));
                            }
                        }
                        cout << endl << "[SUCCESS]: ������ �� ������ ������� �������! ������� ����� ������� ����� ��������� � ���� ������������" << endl;
                        exam_marks_db_file.close();
                        system("pause");
                        academic_performance(session_number, record_book_number);
                        break;
                    }
                }
                else {
                    cout << "[ERROR]: ������� ������ ����� ������. ��������� �������." << endl;
                }
            }
            else {
                cout << "[ERROR]: ������� ������ ����� ������. ��������� �������." << endl;
            }
        } 
    }
    void change_exam_mark(string session_number, string record_book_number) {
        cout << endl << "------- �������� ������ �� ������ -------" << endl;
        string mark_number;
        while (1) {
            cout << "������� ���������� ����� ������ ������� ������� �������� (���������� ����� ������ ����� ���������� � ������� ����): ";
            cin >> mark_number;
            if (is_number(mark_number)) {
                int arr_size = check_db_file_size("Exam_marks_db.bin");
                Exam_mark_list Exam_marks_db;
                fill_exam_mark_list(Exam_marks_db, arr_size);
                Exam_mark_list New_exam_marks_db;
                int rows_count = 0;
                for (int i = 0; i < arr_size; i++) {
                    if (Exam_marks_db[i].get_record_book_number() == record_book_number && Exam_marks_db[i].get_session_number() == stoi(session_number)) {
                        New_exam_marks_db.push_back(Exam_marks_db[i]);
                        rows_count++;
                    }
                }
                if (rows_count >= stoi(mark_number) && rows_count > 0) {
                    cout << "�� ����������� �������� ���������� ������:" << endl << endl;
                    print_table_line(77);
                    string title = "|������ �� " + string(session_number) + " ������";
                    cout.fill(' '); cout.width(76); cout << left << title; cout << " | " << endl;
                    print_table_line(77);
                    cout.width(46); cout.fill(' '); cout << left << "|�������";
                    cout << left << "|"; cout.width(30); cout << "������";
                    cout << left << "|" << endl;
                    print_table_line(77);
                    cout << "|";
                    cout.width(45); cout.fill(' '); cout << left << New_exam_marks_db[stoi(mark_number) - 1].get_subject_name();
                    cout << left << "|"; cout.width(30); cout << New_exam_marks_db[stoi(mark_number) - 1].get_mark();
                    cout << left << "|" << endl;
                    print_table_line(77);
                    cout << "����������?" << endl;
                    cout << "1. ��" << endl;
                    cout << "2. ���" << endl;
                    string temp_string;
                    while (1) {
                        cout << endl << "������� ����� ������ (1-2): ";
                        cin >> temp_string;
                        if (temp_string == "1" || temp_string == "2") {
                            break;
                        }
                        else {
                            cout << "[ERROR]: ������� ������ ����� ������. ��������� �������." << endl;
                        }
                    }
                    if (temp_string == "1") {
                        string mark;
                        while (1) {
                            cout << endl << "�������� ������ (1-6): " << endl;
                            cout << "1. ������ 5" << endl;
                            cout << "2. ������ 4" << endl;
                            cout << "3. ������ 3" << endl;
                            cout << "4. ������ 2" << endl;
                            cout << "5. ������ ������" << endl;
                            cout << "6. ������ ��������" << endl;
                            cout << endl << "������� ����� ����� ������ (1-6): ";
                            cin >> mark;
                            if (is_number(mark) == false || stoi(mark) > 6 || stoi(mark) < 1) {
                                cout << "[ERROR]: ������� ������ ����� ������! ������� ����� �� 1 �� 6";
                            }
                            else {
                                break;
                            }
                        }
                        if (mark == "1") {
                            mark = "5";
                        }
                        else if (mark == "2") {
                            mark = "4";
                        }
                        else if (mark == "3") {
                            mark = "3";
                        }
                        else if (mark == "4") {
                            mark = "2";
                        }
                        else if (mark == "5") {
                            mark = "�����";
                        }
                        else if (mark == "6") {
                            mark = "�������";
                        }
                        ofstream clear_file;
                        clear_file.open("Exam_marks_db.bin", std::ofstream::out | std::ofstream::trunc);
                        clear_file.close();
                        ofstream exam_marks_db_file;
                        exam_marks_db_file.open("Exam_marks_db.bin", ios::binary | ios::app);
                        for (int i = 0; i < arr_size; i++) {
                            if (Exam_marks_db[i].get_subject_name() == New_exam_marks_db[stoi(mark_number) - 1].get_subject_name() && Exam_marks_db[i].get_record_book_number() == record_book_number && Exam_marks_db[i].get_session_number() == stoi(session_number)) {
                                Exam_marks_db[i].set_mark(mark);
                            }
                        }                
                        if (exam_marks_db_file.is_open()) {
                            for (int i = 0; i < arr_size; i++) {
                                exam_marks_db_file.write((char*)&Exam_marks_db[i], sizeof(Exam_marks_db[i]));
                            }
                            cout << endl << "[SUCCESS]: ������ �� ������ ������� ��������! ������� ����� ������� ����� ��������� � ���� ������������" << endl;
                            exam_marks_db_file.close();
                            system("pause");
                            academic_performance(session_number, record_book_number);
                            break;
                        }
                        else {
                            cout << "������ �������� �����!";
                            exam_marks_db_file.close();
                        }
                    }
                    else if (temp_string == "2") {
                        cout << "[INFO]: ��������� ������ ��������." << endl;
                        cout << "[INFO]: ������� ����� ������� ����� ��������� � ���� ������������..." << endl;
                        system("pause");
                        academic_performance(session_number, record_book_number);
                        break;
                    }
                }
                else {
                    cout << "[ERROR]: ������� ������ ����� ������. ��������� �������." << endl;
                }
            }
            else {
                cout << "[ERROR]: ������� ������ ����� ������. ��������� �������." << endl;
            }
        }
    }
    void task_45() {
        system("cls");
        cout << endl << "------- ����� ����������, ����������, ���������� -------" << endl;
        string session_number;
        string group_number;
        string student_gender_str;
        int student_gender;
        while (true) {
            cout << "������� ����� ������: ";
            cin >> group_number;
            if (group_number.length() != 10) {
                cout << "������� ������ ����� ������. ��������� �������." << endl;
            }
            else {
                break;
            }
        }
        while (true) {
            cout << "������� ��� ��������� ��� �������(�/�): ";
            cin >> student_gender_str;
            if (student_gender_str == "�" || student_gender_str == "�") {
                student_gender = 1;
                break;
            }
            else if (student_gender_str == "�" || student_gender_str == "�") {
                student_gender = 0;
                break;
            }
            else {
                cout << "������� ������ ��� ���������. ������� �� ��� ��." << endl;
            }
        }
        while (true) {
            cout << "������� ����� ������ � ������� ����� �������� (1-9): ";
            cin >> session_number;
            if (is_number(session_number) == false || session_number.length() != 1 || stoi(session_number) > 9 || stoi(session_number) < 1) {
                cout << "[ERROR]: ������� ������ ����� ������! ������� ����� �� 1 �� 9" << endl;
            }
            else {
                break;
            }
        }
        int arr_size = check_db_file_size("Students_db.bin");
        Student_list Students_db;
        fill_student_list(Students_db, arr_size);
        Student_list Group_students;
        int i = 0;
        for (i = 0; i < arr_size; i++) {
            if (Students_db[i].get_group() == group_number && Students_db[i].get_gender() == student_gender) {
                Group_students.push_back(Students_db[i]);
            }
        }
        int new_arr_size = Group_students.get_size();
        Student_list best_Students;
        Student_list good_Students;
        Student_list bad_Students;
        for (i = 0; i < new_arr_size; i++) {
            bool best_student = true;
            bool good_student = false;
            bool bad_student = false;
            int marks_arr_size = check_db_file_size("Exam_marks_db.bin");
            Exam_mark_list Exam_marks_db;
            fill_exam_mark_list(Exam_marks_db, marks_arr_size);
            for (int q = 0; q < marks_arr_size; q++) {
                if (Exam_marks_db[q].get_record_book_number()==Group_students[i].get_record_book_number() && Exam_marks_db[q].get_session_number() == stoi(session_number)) {
                    if (Exam_marks_db[q].get_mark()=="4") {
                        good_student = true;
                    }
                    else if (Exam_marks_db[q].get_mark()=="3"|| Exam_marks_db[q].get_mark()=="�������" || Exam_marks_db[q].get_mark()=="2") {
                        bad_student = true;
                    }
                }
            }
            if (bad_student == true) {
                bad_Students.push_back(Group_students[i]);
            }
            else if (good_student == true) {
                good_Students.push_back(Group_students[i]);
            }
            else {
                best_Students.push_back(Group_students[i]);
            }
        }
        int best_student_count = best_Students.get_size();
        int good_student_count = good_Students.get_size();
        int bad_student_count = bad_Students.get_size();
        print_table_line(108);
        cout.fill(' '); cout.width(108); cout << left << "|���������"; cout << "|" << endl;
        print_table_line(108);
        cout.width(23); cout.fill(' '); cout << left << "|����� �������� ������";
        cout << left << "|"; cout.width(22); cout << "�������";
        cout << left << "|"; cout.width(22); cout << "���";
        cout << left << "|"; cout.width(22); cout << "��������";
        cout << left << "|"; cout.width(15); cout << "����� ������";
        cout << left << "|" << endl;
        print_table_line(108);
        for (i = 0; i < best_student_count; i++) {
            cout << "|"; cout.width(22); cout.fill(' '); cout << left << best_Students[i].get_record_book_number();
            cout << left << "|"; cout.width(22); cout << best_Students[i].get_surname();
            cout << left << "|"; cout.width(22); cout << best_Students[i].get_name();
            cout << left << "|"; cout.width(22); cout << best_Students[i].get_middlename();
            cout << left << "|"; cout.width(15); cout << best_Students[i].get_group() << "|" << endl;
            print_table_line(108);
        }
        cout << endl << endl;
        print_table_line(108);
        cout.fill(' '); cout.width(108); cout << left << "|���������"; cout << "|" << endl;
        print_table_line(108);
        cout.width(23); cout.fill(' '); cout << left << "|����� �������� ������";
        cout << left << "|"; cout.width(22); cout << "�������";
        cout << left << "|"; cout.width(22); cout << "���";
        cout << left << "|"; cout.width(22); cout << "��������";
        cout << left << "|"; cout.width(15); cout << "����� ������";
        cout << left << "|" << endl;
        print_table_line(108);
        for (i = 0; i < good_student_count; i++) {
            cout << "|"; cout.width(22); cout.fill(' '); cout << left << good_Students[i].get_record_book_number();
            cout << left << "|"; cout.width(22); cout << good_Students[i].get_surname();
            cout << left << "|"; cout.width(22); cout << good_Students[i].get_name();
            cout << left << "|"; cout.width(22); cout << good_Students[i].get_middlename();
            cout << left << "|"; cout.width(15); cout << good_Students[i].get_group() << "|" << endl;
            print_table_line(108);
        }
        cout << endl << endl;
        print_table_line(108);
        cout.fill(' '); cout.width(108); cout << left << "|���������"; cout << "|" << endl;
        print_table_line(108);
        cout.width(23); cout.fill(' '); cout << left << "|����� �������� ������";
        cout << left << "|"; cout.width(22); cout << "�������";
        cout << left << "|"; cout.width(22); cout << "���";
        cout << left << "|"; cout.width(22); cout << "��������";
        cout << left << "|"; cout.width(15); cout << "����� ������";
        cout << left << "|" << endl;
        print_table_line(108);
        for (i = 0; i < bad_student_count; i++) {
            cout << "|"; cout.width(22); cout.fill(' '); cout << left << bad_Students[i].get_record_book_number();
            cout << left << "|"; cout.width(22); cout << bad_Students[i].get_surname();
            cout << left << "|"; cout.width(22); cout << bad_Students[i].get_name();
            cout << left << "|"; cout.width(22); cout << bad_Students[i].get_middlename();
            cout << left << "|"; cout.width(15); cout << bad_Students[i].get_group() << "|" << endl;
            print_table_line(108);
        }
        cout << "[SUCCESS]: ������� ����������,���������� � ���������� ������� ��������!" << endl;
        cout << endl << "[INFO]: ������� ����� ������� ����� ��������� � ������� ����" << endl;
        system("pause");
        main_menu();
    }
    void main_menu() {
        string menu_number;
        while (1) {
            system("cls");
            cout << "------- ������� ���� -------" << endl;
            cout << "��������� ��������:" << endl;
            cout << "1. ��������" << endl;
            cout << "2. ��������� ������� (������� 45)" << endl;
            cout << "3. ����� �� ��������� � ����������� ��� ������" << endl;
            cout << "4. ����� �� ��������� ��� ���������� ��� ������" << endl;
            cout << "�������� �������� (1-4): ";
            cin >> menu_number;
            if (menu_number == "1" || menu_number == "2" || menu_number == "3" || menu_number == "4") {
                break;
            }
            else {
                cout << "[ERROR]: ����������� ������� ��������! ������� ����� �� 1 �� 4." << endl;
                cout << endl << "[INFO]: ������� ����� ������� ����� ��������� �������..." << endl;
                system("pause");
            }
        }
        
        if (menu_number == "1") {
            students_menu();
        }
        else if (menu_number == "2") {
            task_45();
        }
        else if (menu_number == "3") {
            system("cls");
            Database database;
            string password;
            while (1) {
                cout << "������� ������ ������� ������ ������������ ��� ���������� ��� ������: ";
                cin >> password;
                if (password.length() == 0 || password.length() > 20) {
                    cout << "[ERROR]: ������� ������ ������! ����� ������ ������ ���������� �� 1 �� 20 ��������. ��������� �������."<<endl;
                }
                else {
                    break;
                }
            }
            while (1) {
                if (database.encrypt_file(password, "Students_db.bin", "Students_db.bin.enc") && database.encrypt_file(password, "Exam_marks_db.bin", "Exam_marks_db.bin.enc")) {
                    cout << "[SUCCESS]: ����� ��� ������ ������� �����������!";
                    exit_from_program();
                    break;
                }
                else {
                    cout << "[ERROR]: ��� ���������� ������ ��������� ������! ����� ������ ������ ���������� �� 1 �� 20 ��������. ��������� �������."<<endl;
                    cout << endl << "[INFO]: ������� ����� ������� ����� ��������� � ����" << endl;
                    system("cls");
                    main_menu();
                    break;
                }
           }
        }
        else if (menu_number == "4") {
            exit_from_program();
        }
    }
};