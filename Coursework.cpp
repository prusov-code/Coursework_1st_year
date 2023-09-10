//Прусов Никита Романович, БАСО-04-22.
//Курсовая работа, вариант 45

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <windows.h>

#include "Database.h"
#include "Menu.h"

using namespace std;

int main()
{
    Menu menu;
    Database database;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    if (database.is_file_exist("Students_db.bin") && database.is_file_exist("Exam_marks_db.bin")) {
        menu.main_menu();
    } 
    else if (database.is_file_exist("Students_db.bin.enc") && database.is_file_exist("Exam_marks_db.bin.enc")) {
        string password;
        while (true) {
            cout << "Файлы баз данных зашифрованы. Введите пароль который использовали для шифрования: ";
            cin >> password;
            if (database.decrypt_file(password, "Students_db.bin.enc", "Students_db.bin") && database.decrypt_file(password, "Exam_marks_db.bin.enc", "Exam_marks_db.bin")) {
                break;
            }
            else {
                cout << "Введен неверный пароль! Повторите попытку" << endl;
            }
        }
        cout << "[SUCCESS]: Файлы баз данных успешно расшифрованы!"<<endl;
        cout << "[INFO]: Нажмите любую клавишу чтобы перейти в главное меню";
        system("pause");
        menu.main_menu();
    }
    else {
        if (!database.is_file_exist("Students_db.bin")) {
            ofstream new_file("Students_db.bin");
            cout << "[INFO]: Файл базы данных студентов «Students_db.bin» отсутствует" << endl;
            cout << "[SUCCESS]: Для корректной работы программы файл был создан в директории проекта" << endl;
        }
        if (!database.is_file_exist("Exam_marks_db.bin")) {
            ofstream new_file("Exam_marks_db.bin");
            cout << "[INFO]: Файл базы данных оценок за сессию «Exam_marks_db.bin» отсутствует" << endl;
            cout << "[SUCCESS]: Для корректной работы программы файл был создан в директории проекта" << endl;
        }
        cout << "[INFO]: Нажмите любую клавишу чтобы перейти в главное меню";
        system("pause");
        menu.main_menu();
    }
    return 0;
}
