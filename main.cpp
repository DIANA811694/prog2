// main.cpp
#include "Group.h"
#include <iostream>
#include <vector> // ��� ������������� ��������� �������� �����

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    vector<Group*> groups; // ���������� ������ ��� �������� �����

    while (true) {
        cout << "\n����:\n";
        cout << "1. �������� ������\n";
        cout << "2. �������� �������� � ������\n";
        cout << "3. ������� �������� �� ������\n";
        cout << "4. ��������������� ��������\n";
        cout << "5. ���������� ��������� � ������� ������� ������\n";
        cout << "6. �������� ���� ��������� � ������\n";
        cout << "7. �����\n";
        cout << "�����: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            int groupNumber;
            cout << "������� ����� ������: ";
            cin >> groupNumber;

            Group* newGroup = new Group(groupNumber);
            groups.push_back(newGroup);
            break;
        }
        case 2: {
            int groupIndex;
            cout << "������� ������ ������: ";
            cin >> groupIndex;

            if (groupIndex < 0 || groupIndex >= groups.size()) {
                cout << "������ �� �������.\n";
                break;
            }

            Student student;
            cin >> student; // ��������� ������������� �������� �����
            groups[groupIndex]->addStudent(student);
            break;
        }
        case 3: {
            int groupIndex, studentIndex;
            cout << "������� ������ ������ � ��������: ";
            cin >> groupIndex >> studentIndex;

            if (groupIndex < 0 || groupIndex >= groups.size()) {
                cout << "������ �� �������.\n";
                break;
            }

            groups[groupIndex]->removeStudent(studentIndex);
            break;
        }
        case 4: {
            int groupIndex, studentIndex;
            cout << "������� ������ ������ � �������� ��� ��������������: ";
            cin >> groupIndex >> studentIndex;

            if (groupIndex < 0 || groupIndex >= groups.size()) {
                cout << "������ �� �������.\n";
                break;
            }

            Student student;
            cin >> student;
            groups[groupIndex]->editStudent(studentIndex, student);
            break;
        }
        case 5: {
            int groupIndex;
            cout << "������� ������ ������: ";
            cin >> groupIndex;

            if (groupIndex < 0 || groupIndex >= groups.size()) {
                cout << "������ �� �������.\n";
                break;
            }

            groups[groupIndex]->displayStudentsWithHighGrades(4.0);
            break;
        }
        case 6: {
            int groupIndex;
            cout << "������� ������ ������: ";
            cin >> groupIndex;

            if (groupIndex < 0 || groupIndex >= groups.size()) {
                cout << "������ �� �������.\n";
                break;
            }

            groups[groupIndex]->printStudents();
            break;
        }
        case 7:
            // ����������� ������ ����� �������
            for (auto group : groups) {
                delete group;
            }
            return 0;
        default:
            cout << "�������� �����, ���������� �����.\n";
        }
    }

    return 0;
}