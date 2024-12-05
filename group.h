// Group.h
#ifndef GROUP_H
#define GROUP_H

#include "Student.h"

using namespace std;

class Group {
private:
    Student* students; // ������ ���������
    int studentCount;
    int groupNumber;

public:
    // ������������ � ����������
    Group(int groupNumber);
    ~Group();

    // ������
    void addStudent(const Student& student);
    void removeStudent(int index);
    void displayStudentsWithHighGrades(double threshold) const;
    void editStudent(int index, const Student& student);
    void printStudents() const; // ����� ��� ����������� ������ ���������
};

#endif // GROUP_H