// Group.h
#ifndef GROUP_H
#define GROUP_H

#include "Student.h"

using namespace std;

class Group {
private:
    Student* students; // Массив студентов
    int studentCount;
    int groupNumber;

public:
    // Конструкторы и деструктор
    Group(int groupNumber);
    ~Group();

    // Методы
    void addStudent(const Student& student);
    void removeStudent(int index);
    void displayStudentsWithHighGrades(double threshold) const;
    void editStudent(int index, const Student& student);
    void printStudents() const; // Метод для отображения списка студентов
};

#endif // GROUP_H