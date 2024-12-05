// main.cpp
#include "Group.h"
#include <iostream>
#include <vector> // Для динамического выделения массивов групп

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    vector<Group*> groups; // Используем вектор для хранения групп

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Добавить группу\n";
        cout << "2. Добавить студента в группу\n";
        cout << "3. Удалить студента из группы\n";
        cout << "4. Отредактировать студента\n";
        cout << "5. Отобразить студентов с высоким средним баллом\n";
        cout << "6. Показать всех студентов в группе\n";
        cout << "7. Выход\n";
        cout << "Выбор: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            int groupNumber;
            cout << "Введите номер группы: ";
            cin >> groupNumber;

            Group* newGroup = new Group(groupNumber);
            groups.push_back(newGroup);
            break;
        }
        case 2: {
            int groupIndex;
            cout << "Введите индекс группы: ";
            cin >> groupIndex;

            if (groupIndex < 0 || groupIndex >= groups.size()) {
                cout << "Группа не найдена.\n";
                break;
            }

            Student student;
            cin >> student; // Используя перегруженный оператор ввода
            groups[groupIndex]->addStudent(student);
            break;
        }
        case 3: {
            int groupIndex, studentIndex;
            cout << "Введите индекс группы и студента: ";
            cin >> groupIndex >> studentIndex;

            if (groupIndex < 0 || groupIndex >= groups.size()) {
                cout << "Группа не найдена.\n";
                break;
            }

            groups[groupIndex]->removeStudent(studentIndex);
            break;
        }
        case 4: {
            int groupIndex, studentIndex;
            cout << "Введите индекс группы и студента для редактирования: ";
            cin >> groupIndex >> studentIndex;

            if (groupIndex < 0 || groupIndex >= groups.size()) {
                cout << "Группа не найдена.\n";
                break;
            }

            Student student;
            cin >> student;
            groups[groupIndex]->editStudent(studentIndex, student);
            break;
        }
        case 5: {
            int groupIndex;
            cout << "Введите индекс группы: ";
            cin >> groupIndex;

            if (groupIndex < 0 || groupIndex >= groups.size()) {
                cout << "Группа не найдена.\n";
                break;
            }

            groups[groupIndex]->displayStudentsWithHighGrades(4.0);
            break;
        }
        case 6: {
            int groupIndex;
            cout << "Введите индекс группы: ";
            cin >> groupIndex;

            if (groupIndex < 0 || groupIndex >= groups.size()) {
                cout << "Группа не найдена.\n";
                break;
            }

            groups[groupIndex]->printStudents();
            break;
        }
        case 7:
            // Освобождаем память перед выходом
            for (auto group : groups) {
                delete group;
            }
            return 0;
        default:
            cout << "Неверный выбор, попробуйте снова.\n";
        }
    }

    return 0;
}