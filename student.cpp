// Student.cpp
#include "Student.h"

// ������������ � ����������
Student::Student() : surname(""), initials(""), grades(nullptr), gradeCount(0) {}

Student::Student(const string& surname, const string& initials, double* grades, int count)
    : surname(surname), initials(initials), gradeCount(count) {
    if (count <= 0) throw invalid_argument("���������� ������ ������ ���� �������������");
    this->grades = new double[count];
    for (int i = 0; i < count; ++i) {
        this->grades[i] = grades[i];
    }
}

Student::Student(const Student& other) : surname(other.surname), initials(other.initials), gradeCount(other.gradeCount) {
    grades = new double[gradeCount];
    for (int i = 0; i < gradeCount; ++i) {
        grades[i] = other.grades[i];
    }
}

Student::~Student() {
    delete[] grades;
}

// ���������� ����������
ostream& operator<<(ostream& os, const Student& student) {
    os << student.surname << " " << student.initials << " | ������� ����: " << student.getAverageGrade();
    return os;
}

istream& operator>>(istream& is, Student& student) {
    cout << "������� �������: ";
    is >> student.surname;
    cout << "������� ��������: ";
    is >> student.initials;

    cout << "������� ���������� ������: ";
    is >> student.gradeCount;

    if (student.gradeCount <= 0) {
        throw invalid_argument("���������� ������ ������ ���� �������������");
    }

    student.grades = new double[student.gradeCount];
    for (int i = 0; i < student.gradeCount; ++i) {
        cout << "������� ������ " << i + 1 << ": ";
        is >> student.grades[i];
    }

    return is;
}

// ����� ��� �������� �������� �����
double Student::getAverageGrade() const {
    if (gradeCount == 0) return 0.0; // ���� ��� ������, ���������� 0
    double sum = 0.0;
    for (int i = 0; i < gradeCount; ++i) {
        sum += grades[i]; // ��������� ��� ������
    }
    return sum / gradeCount; // ���������� �������
}

const string& Student::getSurname() const {
    return surname;
}

void Student::setSurname(const string& surname) {
    this->surname = surname;
}

void Student::setGrades(double* grades, int count) {
    delete[] this->grades; // ����������� ������ ������
    this->gradeCount = count;
    this->grades = new double[count];
    for (int i = 0; i < count; ++i) {
        this->grades[i] = grades[i];
    }
}