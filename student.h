// Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Student {
private:
    string surname;
    string initials;
    double* grades;
    int gradeCount;

public:
    // ������������ � ����������
    Student();
    Student(const string& surname, const string& initials, double* grades, int count);
    Student(const Student& other);
    ~Student();

    // ���������
    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& is, Student& student);

    // ������
    double getAverageGrade() const;
    const string& getSurname() const;
    void setSurname(const string& surname);
    void setGrades(double* grades, int count);
};

#endif // STUDENT_H