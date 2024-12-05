// Group.cpp
#include "Group.h"
#include <iostream>

Group::Group(int groupNumber) : groupNumber(groupNumber), studentCount(0), students(nullptr) {
    cout << "����������� Group ������ ��� ������ " << groupNumber << "\n";
}

Group::~Group() {
    cout << "���������� Group ������ ��� ������ " << groupNumber << "\n";
    delete[] students;
}

void Group::addStudent(const Student& student) {
    Student* newStudents = new Student[studentCount + 1];
    for (int i = 0; i < studentCount; ++i) {
        newStudents[i] = students[i];
    }
    newStudents[studentCount] = student; // ���������� ������ ��������
    delete[] students;
    students = newStudents;
    studentCount++;
}

void Group::removeStudent(int index) {
    if (index < 0 || index >= studentCount) throw out_of_range("������ ��� ���������");

    Student* newStudents = new Student[studentCount - 1];
    for (int i = 0, j = 0; i < studentCount; ++i) {
        if (i != index) {
            newStudents[j++] = students[i];
        }
    }
    delete[] students;
    students = newStudents;
    studentCount--;
}

void Group::editStudent(int index, const Student& student) {
    if (index < 0 || index >= studentCount) throw out_of_range("������ ��� ���������");
    students[index] = student;
}

void Group::displayStudentsWithHighGrades(double threshold) const {
    bool found = false;
    cout << "�������� � ������� ������ ���� " << threshold << ":\n";
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].getAverageGrade() > threshold) {
            cout << students[i] << " (������: " << groupNumber << ")\n";
            found = true;
        }
    }
    if (!found) {
        cout << "��� ��������� � �������� �������� ������� � ������ " << groupNumber << ".\n";
    }
}

void Group::printStudents() const {
    cout << "�������� � ������ " << groupNumber << ":\n";
    for (int i = 0; i < studentCount; ++i) {
        cout << i << ": " << students[i] << "\n";
    }
}