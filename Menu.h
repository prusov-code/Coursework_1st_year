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
            cout << "------- СТУДЕНТЫ -------" << endl;
            cout << "Возможные действия:" << endl;
            cout << "1. Посмотреть список всех студентов" << endl;
            cout << "2. Посмотреть список студентов по номеру группы" << endl;
            cout << "3. Подробная информация о студенте" << endl;
            cout << "4. Добавить студента" << endl;
            cout << "5. Изменить данные студента" << endl;
            cout << "6. Удалить студента" << endl;
            cout << "7. Успеваемость студента" << endl;
            cout << "8. Вернуться в главное меню" << endl;
            cout << "Выберите действие (1-8): ";
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
            cout << "------- СПИСОК СТУДЕНТОВ ПО НОМЕРУ ГРУППЫ -------" << endl;
            bool repeat = true;
            while (repeat == true) {
                string group;
                cout << "Введите номер группы: ";
                cin >> group;
                if (group.length() > 10 || group.length() < 1) {
                    cout << "[ERROR]: Неверно введен номер группы. Длина должна составлять от 1 до 10 символов" << endl;
                }
                else {
                    students_table(group);
                }
            }
        }
        else if (menu_number == "3") {
            system("cls");
            cout << "------- ПОДРОБНАЯ ИНФОРМАЦИЯ О СТУДЕНТЕ -------" << endl;
            string record_book_number = "";
            while (1) {
                cout << "Введите номер зачетной книжки студента для поиска: ";
                cin >> record_book_number;
                if (record_book_number.length() == 7) {
                    break;
                }
                else {
                    cout << endl << "[ERROR]: Неверно введен номер зачетной книжки! Длина должна составлять 7 символов" << endl;
                }
            }
            bool record_book_state = check_record_book_number(record_book_number);
            if (record_book_state == true) {
                Student Student_info = find_student_by_record_book_number(record_book_number);
                system("cls");
                print_student_info(Student_info);
                cout << endl << "[SUCCESS]: Студент успешно найден!";
                cout << endl << "[INFO]: Нажмите любую клавишу чтобы вернуться в меню «Студенты»" << endl;
                system("pause");
                students_menu();
            }
            else {
                cout << endl << "[ERROR]: Студент с номером зачетной книжки «" << record_book_number << "» не найден.";
                cout << endl << "[INFO]: Нажмите любую клавишу чтобы вернуться в меню «Студенты»" << endl;
                system("pause");
                students_menu();
            }
        }
        else if (menu_number == "4") {
            add_new_student();
        }
        else if (menu_number == "5") {
            system("cls");
            cout << "------- ИЗМЕНЕНИЕ ИНФОРМАЦИИ О СТУДЕНТЕ -------" << endl;
            string record_book_number = "";
            while (true) {
                cout << "Введите номер зачетной книжки студента для поиска: ";
                cin >> record_book_number;
                if (record_book_number.length() == 7) {
                    break;
                }
                else {
                    cout << endl << "[ERROR]: Неверно введен номер зачетной книжки! Длина должна составлять 7 символов" << endl;
                }
            }
                bool record_book_state = check_record_book_number(record_book_number);
                if (record_book_state == true) {
                    Student Student_info = find_student_by_record_book_number(record_book_number);
                    while (true) {
                        system("cls");
                        print_student_info(Student_info);
                        cout << endl << "------- ИЗМЕНЕНИЕ ИНФОРМАЦИИ О СТУДЕНТЕ -------" << endl;
                        cout << endl << "Возможные действия:" << endl;
                        cout << "1. Изменить имя" << endl;
                        cout << "2. Изменить фамилию" << endl;
                        cout << "3. Изменить отчество" << endl;
                        cout << "4. Изменить дату рождения" << endl;
                        cout << "5. Изменить год поступления в университет" << endl;
                        cout << "6. Изменить факультет (институт)" << endl;
                        cout << "7. Изменить кафедру" << endl;
                        cout << "8. Изменить группу" << endl;
                        cout << "9. Изменить пол" << endl;
                        cout << "10. Выйти в меню" << endl;
                        string sub_menu_number;
                        while (true) {
                            cout << "Выберите действие (1-10): ";
                            cin >> sub_menu_number;
                            if (sub_menu_number == "1" || sub_menu_number == "2" || sub_menu_number == "3" || sub_menu_number == "4" || sub_menu_number == "5" || sub_menu_number == "6" || sub_menu_number == "7" || sub_menu_number == "8" || sub_menu_number == "9" || sub_menu_number == "10") {
                                break;
                            }
                            else {
                                cout << endl << "[ERROR]: Неверно выбрано действие. Введите число от 1 до 10" << endl;
                            }
                        }
                        while (true) {
                            string temp_string;
                            if (sub_menu_number == "1") {
                                cout << "Введите новое имя студента: ";
                                cin >> temp_string;
                                if (temp_string.length() < 1 || temp_string.length() > 20) {
                                    cout << "[ERROR]: Неверно введено имя! Длина должна составлять от 1 до 20 символов"<<endl;
                                }
                                else {
                                    Student_info.set_name(temp_string);
                                    break;
                                }
                            }
                            else if (sub_menu_number == "2") {
                                cout << "Введите новую фамилию студента: ";
                                cin >> temp_string;
                                if (temp_string.length() < 1 || temp_string.length() > 20) {
                                    cout << "[ERROR]: Неверно введена фамилия! Длина должна составлять от 1 до 20 символов" << endl;
                                }
                                else {
                                    Student_info.set_surname(temp_string);
                                    break;
                                }
                            }
                            else if (sub_menu_number == "3") {
                                cout << "Введите новое отчество студента: ";
                                cin >> temp_string;
                                if (temp_string.length() < 1 || temp_string.length() > 20) {
                                    cout << "[ERROR]: Неверно введено отчество! Длина должна составлять от 1 до 20 символов" << endl;
                                }
                                else {
                                    Student_info.set_middlename(temp_string);
                                    break;
                                }
                            }
                            else if (sub_menu_number == "4") {
                                cout << "Введите новый день рождения студента (в формате 09.09.2009): ";
                                cin >> temp_string;
                                if (temp_string.length() < 1 || temp_string.length() > 10) {
                                    cout << "[ERROR]: Неверно введен день рождения! Длина должна составлять 10 символов" << endl;
                                }
                                else {
                                    if (check_date(temp_string) == true) {
                                        Student_info.set_birthday(temp_string);
                                        break;
                                    }
                                    else {
                                        cout << endl << "[ERROR]: Неверно введена дата рождения студента! Введите дату в формате 01.10.2010" << endl;
                                    }
                                }
                            }
                            else if (sub_menu_number == "5") {
                                cout << "Введите новый год поступления в университет студента: ";
                                cin >> temp_string;
                                if (temp_string.length() != 4 || is_number(temp_string) == false) {
                                    cout << "[ERROR]: Неверно введен год поступления в университет! Длина должна составлять 4 символа" << endl;
                                }
                                else {
                                    Student_info.set_starting_year(stoi(temp_string));
                                    break;
                                }
                            }
                            else if (sub_menu_number == "6") {
                                cout << "Введите новый факультет: ";
                                cin >> temp_string;
                                if (temp_string.length() < 1 || temp_string.length() > 5) {
                                    cout << "[ERROR]: Неверно введен факультет! Длина должна составлять от 1 до 5 символов" << endl;
                                }
                                else {
                                    Student_info.set_faculty(temp_string);
                                    break;
                                }
                            }
                            else if (sub_menu_number == "7") {
                                cout << "Введите новую кафедру: ";
                                cin >> temp_string;
                                if (temp_string.length() < 1 || temp_string.length() > 6) {
                                    cout << "[ERROR]: Неверно введена кафедра! Длина должна составлять от 1 до 6 символов" << endl;
                                }
                                else {
                                    Student_info.set_department(temp_string);
                                    break;
                                }
                            }
                            else if (sub_menu_number == "8") {
                                cout << "Введите новую группу: ";
                                cin >> temp_string;
                                if (temp_string.length() != 10) {
                                    cout << "[ERROR]: Неверно введена группа! Длина должна составлять 10 символов" << endl;
                                }
                                else {
                                    Student_info.set_group(temp_string);
                                    break;
                                }
                            }
                            else if (sub_menu_number == "9") {
                                cout << "Введите пол студента (м/ж): ";
                                cin >> temp_string;
                                if (temp_string == "м" || temp_string == "М") {
                                    Student_info.set_gender(1);
                                    break;
                                }
                                else if (temp_string == "ж" || temp_string == "Ж") {
                                    Student_info.set_gender(0);
                                    break;
                                }
                                else {
                                    cout << endl << "[ERROR]: Неверно введен пол студента! Необходимо ввести «М» или «Ж»" << endl;
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
                    cout << endl << "[ERROR]: Студент с номером зачетной книжки «" << record_book_number << "» не найден.";
                    cout << endl << "[INFO]: Нажмите любую клавишу чтобы вернуться в меню «Студенты»" << endl;
                    system("pause");
                    students_menu();
                }

        }
        else if (menu_number == "6") {
            system("cls");
            cout << "------- УДАЛЕНИЕ СТУДЕНТА -------" << endl;
            string record_book_number = "";
            while (true) {
                cout << "Введите номер зачетной книжки студента которого необходимо удалить: ";
                cin >> record_book_number;
                if (record_book_number.length() == 7) {
                    break;
                }
                else {
                    cout << endl << "[ERROR]: Неверно введен номер зачетной книжки! Длина должна составлять 7 символов" << endl;
                }
            }
                bool record_book_state = check_record_book_number(record_book_number);
                if (record_book_state == true) {
                    Student Student_info = find_student_by_record_book_number(record_book_number);
                    system("cls");
                    print_student_info(Student_info);
                    cout << "------- УДАЛЕНИЕ СТУДЕНТА -------" << endl;
                    cout << "Вы уверены что хотите удалить студента?" << endl;
                    cout << "1. Да" << endl << "2. Нет" << endl;
                    string temp_string;
                    while (true) {
                        cout << "Введите 1 или 2 для подтверждения или отмены удаления: ";
                        cin >> temp_string;
                        if (temp_string == "1" || temp_string == "2") {
                            break;
                        }
                        else {
                            cout << "Неверно введена команда. Введите 1 или 2 для подтверждения или отмены удаления данных студента." << endl;
                        }
                    }
                    if (temp_string == "1") {
                        delete_student(record_book_number);
                    }
                    else if (temp_string == "2") {
                        cout << endl << "[INFO]: Удаление студента отменено." << endl;
                        cout << endl << "[INFO]: Нажмите любую клавишу чтобы вернуться в меню «Студенты»" << endl;
                        system("pause");
                        students_menu();
                    }
                }
                else {
                    cout << endl << "[ERROR]: Студент с номером зачетной книжки «" << record_book_number << "» не найден.";
                    cout << endl << "[INFO]: Нажмите любую клавишу чтобы вернуться в меню «Студенты»" << endl;
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
            title = "|СПИСОК ВСЕХ СТУДЕНТОВ " + group;
        }
        else {
            title = "|СПИСОК ВСЕХ СТУДЕНТОВ";
        }
        print_table_line(108);

        cout.fill(' '); cout.width(108); cout << left << title; cout << "|" << endl;
        print_table_line(108);
        cout.width(23); cout.fill(' '); cout << left << "|Номер зачетной книжки";
        cout << left << "|"; cout.width(22); cout << "Фамилия";
        cout << left << "|"; cout.width(22); cout << "Имя";
        cout << left << "|"; cout.width(22); cout << "Отчество";
        cout << left << "|"; cout.width(15); cout << "Номер группы";
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
        cout << endl << "[INFO]: Для подробной информации о студенте воспользуйтесь пунктом «Подробная информация о студенте» в меню «Студенты»";
        cout << endl << "[SUCCESS]: Нажмите любую клавишу чтобы вернуться в меню «Студенты»" << endl;
        system("pause");
        students_menu();
    }
    void print_student_info(Student Student_info) {
        cout << "------- ИНФОРМАЦИЯ О СТУДЕНТЕ -------" << endl;
        cout << "Номер зачетной книжки: " << Student_info.get_record_book_number() << endl;
        cout << "ФИО студента: " << Student_info.get_surname() << " " << Student_info.get_name() << " " << Student_info.get_middlename() << endl;
        cout << "Дата рождения: " << Student_info.get_birthday() << endl;
        cout << "Год поступления в университет: " << Student_info.get_starting_year() << endl;
        cout << "Факультет (институт): " << Student_info.get_faculty() << endl;
        cout << "Кафедра: " << Student_info.get_department() << endl;
        cout << "Группа: " << Student_info.get_group() << endl;
        char student_gender[8];
        if (Student_info.get_gender() == 1) {
            strcpy_s(student_gender, "мужской");
        }
        else {
            strcpy_s(student_gender, "женский");
        }
        cout << "Пол: " << student_gender << endl;
    }
    void print_table_line(int length) {
        cout.fill('-'); cout.width(length); cout << left << "|"; cout << right << "|" << endl;
    }
    void add_new_student() {
        system("cls");
        string file_path = "Students_db.bin";
        cout << "------- ДОБАВЛЕНИЕ НОВОГО СТУДЕНТА -------" << endl;
        string temp_string;
        Student Student_info;
        while (1) {
            cout << "Введите фамилию студента: ";
            cin >> temp_string;
            if (temp_string.length() > 20 || temp_string.length() < 1) {
                cout << endl << "[ERROR]: Неверно введена фамилия студента! Длина должна составлять от 1 до 20 символов" << endl;
            }
            else {
                Student_info.set_surname(temp_string);
                break;
            }
        }
        while (1) {
            cout << "Введите имя студента: ";
            cin >> temp_string;
            if (temp_string.length() > 20 || temp_string.length() < 1) {
                cout << endl << "[ERROR]: Неверно введено имя студента! Длина должна составлять от 1 до 20 символов" << endl;
            }
            else {
                Student_info.set_name(temp_string);
                break;
            }
        }
        while (1) {
            cout << "Введите отчество студента: ";
            cin >> temp_string;
            if (temp_string.length() > 20 || temp_string.length() < 1) {
                cout << endl << "[ERROR]: Неверно введено отчество студента! Длина должна составлять от 1 до 20 символов" << endl;
            }
            else {
                Student_info.set_middlename(temp_string);
                break;
            }
        }
        while (1) {
            cout << "Введите число,месяц,год рождения студента (в формате 09.09.2000): ";
            cin >> temp_string;
            if (temp_string.length() > 10 || temp_string.length() < 1) {
                cout << endl << "[ERROR]: Неверно введена дата рождения студента! Длина должна составлять 10 символов" << endl;
            }
            else {
                if (check_date(temp_string)==true) {
                    Student_info.set_birthday(temp_string);
                    break;
                }
                else {
                    cout << endl << "[ERROR]: Неверно введена дата рождения студента! Введите дату в формате 01.10.2010" << endl;
                }   
            }
        }
       
        while (1) {
            cout << "Введите факультет (институт) студента: ";
            cin >> temp_string;
            if (temp_string.length() > 5 || temp_string.length() < 1) {
                cout << endl << "[ERROR]: Неверно введен факультет (институт)! Длина должна составлять от 1 до 5 символов" << endl;
            }
            else {
                Student_info.set_faculty(temp_string);
                break;
            }
        }
        while (1) {
            cout << "Введите кафедру студента: ";
            cin >> temp_string;
            if (temp_string.length() > 6 || temp_string.length() < 1) {
                cout << endl << "[ERROR]: Неверно введена кафедра! Длина должна составлять от 1 до 6 символов" << endl;
            }
            else {
                Student_info.set_department(temp_string);
                break;
            }
        }
        while (1) {
            cout << "Введите группу студента: ";
            cin >> temp_string;
            if (temp_string.length() != 10) {
                cout << endl << "[ERROR]: Неверно введена группа! Длина должна составлять 10 символов" << endl;
            }
            else {
                Student_info.set_group(temp_string);
                break;
            }
        }
        while (1) {
            cout << "Введите номер зачетной книжки студента (в формате 12А4567): ";
            cin >> temp_string;
            if (temp_string.length() != 7) {
                cout << endl << "[ERROR]: Неверно введен номер зачетной книжки! Длина должна составлять 7 символов" << endl;
            }
            else {
                bool record_book_state = check_record_book_number(temp_string);
                if (record_book_state == true) {
                    cout << endl << "[ERROR]: Студент с таким номером зачетной книжки уже есть в базе данных!" << endl;
                }
                else {
                    Student_info.set_record_book_number(temp_string);
                    break;
                }
            }
        }
        while (1) {
            cout << "Введите год поступления в институт: ";
            cin >> temp_string;
            if (temp_string.length() != 4 || is_number(temp_string) == false) {
                cout << endl << "[ERROR]: Неверно введен год поступления в институт! Длина должна составлять 4 символа" << endl;
            }
            else {
                Student_info.set_starting_year(stoi(temp_string));
                break;
            }
        }
        while (1) {
            cout << "Введите пол студента (м/ж): ";
            cin >> temp_string;
            if (temp_string == "м" || temp_string == "М") {
                Student_info.set_gender(1);
                break;
            }
            else if (temp_string == "ж" || temp_string == "Ж") {
                Student_info.set_gender(0);
                break;
            }
            else {
                cout << endl << "[ERROR]: Неверно введен пол студента! Необходимо ввести «М» или «Ж»" << endl;
            }
        }
        ofstream students_db_file;
        students_db_file.open(file_path, ios::binary | ios::app);
        if (students_db_file.is_open()) {
            students_db_file.write((char*)&Student_info, sizeof(Student_info));
            cout << endl << "[SUCCESS]: Студент успешно добавлен! Нажмите любую клавишу чтобы вернуться в меню" << endl;
            students_db_file.close();
            system("pause");
            students_menu();
        }
        else {
            students_db_file.close();
            cout << "[ERROR]: Ошибка открытия файла!";
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
            cout << endl << "[SUCCESS]: Студент успешно удален!" << endl;
            cout << endl << "[INFO]: Нажмите любую клавишу чтобы вернуться в меню «Студенты»" << endl;
            students_db_write_file.close();
            system("pause");
            students_menu();

        }
        else {
            cout << endl << "[ERROR]: Ошибка открытия файла!";
            cout << endl << "[INFO]: Нажмите любую клавишу чтобы вернуться в меню «Студенты»" << endl;
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
            cout << endl << "[SUCCESS]: Информация о студенте успешно изменена!" << endl;
            cout << endl << "[INFO]: Нажмите любую клавишу чтобы вернуться в меню изменения студента" << endl;
            students_db_write_file.close();
            system("pause");
        }
        else {
            cout << endl << "[ERROR]: Ошибка открытия файла!";
            cout << endl << "[INFO]: Нажмите любую клавишу чтобы вернуться в меню изменения студента" << endl;
            students_db_write_file.close();
            system("pause");
            students_menu();
        }
    }
    void academic_performance(string session_number, string record_book_number) {
        system("cls");
        bool record_book_state = false;
        if (session_number == "") {
            cout << "------- УСПЕВАЕМОСТЬ СТУДЕНТА -------" << endl;
            while (1) {
                cout << "Введите номер зачетной книжки студента: ";
                record_book_number = "";
                cin >> record_book_number;
                if (record_book_number.length() == 7) {
                    record_book_state = check_record_book_number(record_book_number);
                    break;
                }
                else {
                    cout << endl << "[ERROR]: Неверно введен номер зачетной книжки! Длина должна составлять 7 символов" << endl;
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
            cout << endl << "------- УСПЕВАЕМОСТЬ СТУДЕНТА -------" << endl;
            if (session_number == "") {
                while (1) {
                    cout << "Введите номер сессии с которой нужно работать (1-9): ";
                    cin >> session_number;
                    if (is_number(session_number) == false || stoi(session_number) > 9 || stoi(session_number) < 1) {
                        cout << "[ERROR]: Неверно введен номер сессии! Введите число от 1 до 9" << endl;
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
                cout << endl << "------- ДЕЙСТВИЯ С УСПЕВАЕМОСТЬЮ СТУДЕНТА -------" << endl;
                cout << "1. Добавить новую оценку за " << session_number << " сессию" << endl;
                cout << "2. Изменить оценку за " << session_number << " сессию" << endl;
                cout << "3. Удалить оценку за " << session_number << " сессию" << endl;
                cout << "4. Выбрать другую сессию" << endl;
                cout << "5. Выйти в меню" << endl;
                cout << endl << "Выберите действие (1-4): ";
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
                        cout << "Введите номер сессии с которой нужно работать (1-9): ";
                        cin >> session_number;
                        if (is_number(session_number) == false || stoi(session_number) > 9 || stoi(session_number) < 1) {
                            cout << "[ERROR]: Неверно введен номер сессии! Введите число от 1 до 9" << endl;
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
                    cout << "Неверно введен номер действия! Введите число от 1 до 4." << endl;
                }
            }
        }
        else {
            cout << endl << "[ERROR]: Студент с номером зачетной книжки «" << record_book_number << "» не найден.";
            cout << endl << "[INFO]: Нажмите любую клавишу чтобы вернуться в меню «Студенты»" << endl;
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
        string title = "|СПИСОК ОЦЕНОК СТУДЕНТА " + fio + " ЗА " + string(session_number) + " СЕССИЮ";
        cout.fill(' '); cout.width(79); cout << left << title; cout << " | " << endl;
        print_table_line(80);
        cout.width(3); cout.fill(' '); cout << left << "|№";
        cout << left << "|"; cout.width(45); cout << "Предмет";
        cout << left << "|"; cout.width(30); cout << "Оценка";
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
        cout << endl << "------- ДОБАВИТЬ ОЦЕНКУ ЗА СЕССИЮ -------" << endl;
        string subject_name;
        while (1) {
            cout << "Введите название предмета: ";
            cin.seekg(cin.eof());
            getline(cin, subject_name);
            if (subject_name.length() < 1 || subject_name.length() > 45) {
                cout << "[ERROR]: Неверно введено название предмета! Название предмета должно составлять от 1 до 45 символов" << endl;
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
                        cout << "[ERROR]: Оценка по данному предмету уже выставлена! Введите другое название предмета" << endl;
                    }
                }
                if (subjects_count > 9) {
                    cout << "[ERROR]: Максимальное количество оценок за одну сессию - 10 штук. Удалите другие оценки чтобы добавить новую"<<endl;
                    cout <<"[INFO]: Нажмите любую клавишу чтобы вернуться в меню" << endl;
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
            cout << "Выберите оценку (1-6): " << endl;
            cout << "1. Оценка 5" << endl;
            cout << "2. Оценка 4" << endl;
            cout << "3. Оценка 3" << endl;
            cout << "4. Оценка 2" << endl;
            cout << "5. Оценка «Зачет»" << endl;
            cout << "6. Оценка «Незачет»" << endl;
            cout << "Введите номер оценки (1-6): ";
            cin >> mark;
            if (is_number(mark) == false || stoi(mark) > 6 || stoi(mark) < 1) {
                cout << "[ERROR]: Неверно введен номер оценки! Введите число от 1 до 6" << endl;
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
            mark = "Зачет";
        }
        else if (mark == "6") {
            mark = "Незачет";
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
            cout << endl << "[SUCCESS]: Оценка за сессию успешно добавлена! Нажмите любую клавишу чтобы вернуться в меню оценок студента" << endl;
            exam_marks_db_file.close();
            system("pause");
            academic_performance(session_number, Student_info.get_record_book_number());
        }
        else {
            exam_marks_db_file.close();
            cout << "[ERROR]: Ошибка открытия файла!";
        }
    }
    void delete_exam_mark(string session_number, string record_book_number) {
        cout << endl << "------- УДАЛИТЬ ОЦЕНКУ ЗА СЕССИЮ -------" << endl;
        string mark_number;
        while (1) {
            cout << "Введите порядковый номер оценки которую желаете удалить (порядковый номер оценки можно посмотреть в таблице выше): ";
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
                    cout << "Вы собираетесь удалить следующуюю оценку:" << endl << endl;
                    print_table_line(77);
                    string title = "|ОЦЕНКА ЗА " + string(session_number) + " СЕССИЮ";
                    cout.fill(' '); cout.width(76); cout << left << title; cout << " | " << endl;
                    print_table_line(77);
                    cout.width(46); cout.fill(' '); cout << left << "|Предмет";
                    cout << left << "|"; cout.width(30); cout << "Оценка";
                    cout << left << "|" << endl;
                    print_table_line(77);
                    cout << "|";
                    cout.width(45); cout.fill(' '); cout << left << New_exam_marks_db[stoi(mark_number) - 1].get_subject_name();
                    cout << left << "|"; cout.width(30); cout << New_exam_marks_db[stoi(mark_number) - 1].get_mark();
                    cout << left << "|" << endl;
                    print_table_line(77);
                    string temp_string;
                    while (1) {
                        cout << "Вы уверены что хотите удалить данную оценку?" << endl;
                        cout << "1. Да" << endl;
                        cout << "2. Нет" << endl;
                        cout << "Введите номер пункта (1-2): ";
                        cin >> temp_string;
                        if (temp_string == "1" || temp_string == "2") {
                            break;
                        }
                        else {
                            cout << "[ERROR]: Неверно введен номер пункта. Повторите попытку." << endl;
                        }
                    }
                    if (temp_string == "2") {
                        cout << "[INFO]: Удаление оценки отменено." << endl;
                        cout << "[INFO]: Нажмите любую клавишу чтобы вернуться в меню успеваемости..." << endl;
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
                        cout << endl << "[SUCCESS]: Оценка за сессию успешно удалена! Нажмите любую клавишу чтобы вернуться в меню успеваемости" << endl;
                        exam_marks_db_file.close();
                        system("pause");
                        academic_performance(session_number, record_book_number);
                        break;
                    }
                }
                else {
                    cout << "[ERROR]: Неверно введен номер оценки. Повторите попытку." << endl;
                }
            }
            else {
                cout << "[ERROR]: Неверно введен номер оценки. Повторите попытку." << endl;
            }
        } 
    }
    void change_exam_mark(string session_number, string record_book_number) {
        cout << endl << "------- Изменить ОЦЕНКУ ЗА СЕССИЮ -------" << endl;
        string mark_number;
        while (1) {
            cout << "Введите порядковый номер оценки которую желаете изменить (порядковый номер оценки можно посмотреть в таблице выше): ";
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
                    cout << "Вы собираетесь изменить следующуюю оценку:" << endl << endl;
                    print_table_line(77);
                    string title = "|ОЦЕНКА ЗА " + string(session_number) + " СЕССИЮ";
                    cout.fill(' '); cout.width(76); cout << left << title; cout << " | " << endl;
                    print_table_line(77);
                    cout.width(46); cout.fill(' '); cout << left << "|Предмет";
                    cout << left << "|"; cout.width(30); cout << "Оценка";
                    cout << left << "|" << endl;
                    print_table_line(77);
                    cout << "|";
                    cout.width(45); cout.fill(' '); cout << left << New_exam_marks_db[stoi(mark_number) - 1].get_subject_name();
                    cout << left << "|"; cout.width(30); cout << New_exam_marks_db[stoi(mark_number) - 1].get_mark();
                    cout << left << "|" << endl;
                    print_table_line(77);
                    cout << "Продолжить?" << endl;
                    cout << "1. Да" << endl;
                    cout << "2. Нет" << endl;
                    string temp_string;
                    while (1) {
                        cout << endl << "Введите номер пункта (1-2): ";
                        cin >> temp_string;
                        if (temp_string == "1" || temp_string == "2") {
                            break;
                        }
                        else {
                            cout << "[ERROR]: Неверно введен номер пункта. Повторите попытку." << endl;
                        }
                    }
                    if (temp_string == "1") {
                        string mark;
                        while (1) {
                            cout << endl << "Выберите оценку (1-6): " << endl;
                            cout << "1. Оценка 5" << endl;
                            cout << "2. Оценка 4" << endl;
                            cout << "3. Оценка 3" << endl;
                            cout << "4. Оценка 2" << endl;
                            cout << "5. Оценка «Зачет»" << endl;
                            cout << "6. Оценка «Незачет»" << endl;
                            cout << endl << "Введите номер новой оценки (1-6): ";
                            cin >> mark;
                            if (is_number(mark) == false || stoi(mark) > 6 || stoi(mark) < 1) {
                                cout << "[ERROR]: Неверно введен номер оценки! Введите число от 1 до 6";
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
                            mark = "Зачет";
                        }
                        else if (mark == "6") {
                            mark = "Незачет";
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
                            cout << endl << "[SUCCESS]: Оценка за сессию успешно изменена! Нажмите любую клавишу чтобы вернуться в меню успеваемости" << endl;
                            exam_marks_db_file.close();
                            system("pause");
                            academic_performance(session_number, record_book_number);
                            break;
                        }
                        else {
                            cout << "Ошибка открытия файла!";
                            exam_marks_db_file.close();
                        }
                    }
                    else if (temp_string == "2") {
                        cout << "[INFO]: Изменение оценки отменено." << endl;
                        cout << "[INFO]: Нажмите любую клавишу чтобы вернуться в меню успеваемости..." << endl;
                        system("pause");
                        academic_performance(session_number, record_book_number);
                        break;
                    }
                }
                else {
                    cout << "[ERROR]: Неверно введен номер оценки. Повторите попытку." << endl;
                }
            }
            else {
                cout << "[ERROR]: Неверно введен номер оценки. Повторите попытку." << endl;
            }
        }
    }
    void task_45() {
        system("cls");
        cout << endl << "------- ПОИСК ОТЛИЧНИКОВ, ХОРОШИСТОВ, ТРОЕЧНИКОВ -------" << endl;
        string session_number;
        string group_number;
        string student_gender_str;
        int student_gender;
        while (true) {
            cout << "Введите номер группы: ";
            cin >> group_number;
            if (group_number.length() != 10) {
                cout << "Неверно введен номер группы. Повторите попытку." << endl;
            }
            else {
                break;
            }
        }
        while (true) {
            cout << "Введите пол студентов для выборки(м/ж): ";
            cin >> student_gender_str;
            if (student_gender_str == "м" || student_gender_str == "М") {
                student_gender = 1;
                break;
            }
            else if (student_gender_str == "ж" || student_gender_str == "Ж") {
                student_gender = 0;
                break;
            }
            else {
                cout << "Неверно введен пол студентов. Введите «м» или «ж»." << endl;
            }
        }
        while (true) {
            cout << "Введите номер сессии с которой нужно работать (1-9): ";
            cin >> session_number;
            if (is_number(session_number) == false || session_number.length() != 1 || stoi(session_number) > 9 || stoi(session_number) < 1) {
                cout << "[ERROR]: Неверно введен номер сессии! Введите число от 1 до 9" << endl;
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
                    else if (Exam_marks_db[q].get_mark()=="3"|| Exam_marks_db[q].get_mark()=="Незачет" || Exam_marks_db[q].get_mark()=="2") {
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
        cout.fill(' '); cout.width(108); cout << left << "|ОТЛИЧНИКИ"; cout << "|" << endl;
        print_table_line(108);
        cout.width(23); cout.fill(' '); cout << left << "|Номер зачетной книжки";
        cout << left << "|"; cout.width(22); cout << "Фамилия";
        cout << left << "|"; cout.width(22); cout << "Имя";
        cout << left << "|"; cout.width(22); cout << "Отчество";
        cout << left << "|"; cout.width(15); cout << "Номер группы";
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
        cout.fill(' '); cout.width(108); cout << left << "|ХОРОШИСТЫ"; cout << "|" << endl;
        print_table_line(108);
        cout.width(23); cout.fill(' '); cout << left << "|Номер зачетной книжки";
        cout << left << "|"; cout.width(22); cout << "Фамилия";
        cout << left << "|"; cout.width(22); cout << "Имя";
        cout << left << "|"; cout.width(22); cout << "Отчество";
        cout << left << "|"; cout.width(15); cout << "Номер группы";
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
        cout.fill(' '); cout.width(108); cout << left << "|ТРОЕЧНИКИ"; cout << "|" << endl;
        print_table_line(108);
        cout.width(23); cout.fill(' '); cout << left << "|Номер зачетной книжки";
        cout << left << "|"; cout.width(22); cout << "Фамилия";
        cout << left << "|"; cout.width(22); cout << "Имя";
        cout << left << "|"; cout.width(22); cout << "Отчество";
        cout << left << "|"; cout.width(15); cout << "Номер группы";
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
        cout << "[SUCCESS]: Таблица Отличников,Хорошистов и Троечников успешно выведена!" << endl;
        cout << endl << "[INFO]: Нажмите любую клавишу чтобы вернуться в главное меню" << endl;
        system("pause");
        main_menu();
    }
    void main_menu() {
        string menu_number;
        while (1) {
            system("cls");
            cout << "------- ГЛАВНОЕ МЕНЮ -------" << endl;
            cout << "Возможные действия:" << endl;
            cout << "1. Студенты" << endl;
            cout << "2. Выполнить задание (вариант 45)" << endl;
            cout << "3. Выйти из программы с шифрованием баз данных" << endl;
            cout << "4. Выйти из программы без шифрования баз данных" << endl;
            cout << "Выберите действие (1-4): ";
            cin >> menu_number;
            if (menu_number == "1" || menu_number == "2" || menu_number == "3" || menu_number == "4") {
                break;
            }
            else {
                cout << "[ERROR]: Неправильно выбрано действие! Введите число от 1 до 4." << endl;
                cout << endl << "[INFO]: Нажмите любую клавишу чтобы повторить попытку..." << endl;
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
                cout << "Введите пароль который хотите использовать для шифрования баз данных: ";
                cin >> password;
                if (password.length() == 0 || password.length() > 20) {
                    cout << "[ERROR]: Неверно введен пароль! Длина пароля должна составлять от 1 до 20 символов. Повторите попытку."<<endl;
                }
                else {
                    break;
                }
            }
            while (1) {
                if (database.encrypt_file(password, "Students_db.bin", "Students_db.bin.enc") && database.encrypt_file(password, "Exam_marks_db.bin", "Exam_marks_db.bin.enc")) {
                    cout << "[SUCCESS]: Файлы баз данных успешно зашифрованы!";
                    exit_from_program();
                    break;
                }
                else {
                    cout << "[ERROR]: При шифровании файлов произошла ошибка! Длина пароля должна составлять от 1 до 20 символов. Повторите попытку."<<endl;
                    cout << endl << "[INFO]: Нажмите любую клавишу чтобы вернуться в меню" << endl;
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