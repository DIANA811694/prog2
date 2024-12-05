// Student.cpp
#include "Student.h"

// Конструкторы и деструктор
Student::Student() : surname(""), initials(""), grades(nullptr), gradeCount(0) {}

Student::Student(const string& surname, const string& initials, double* grades, int count)
    : surname(surname), initials(initials), gradeCount(count) {
    if (count <= 0) throw invalid_argument("Количество оценок должно быть положительным");
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

// Перегрузка операторов
ostream& operator<<(ostream& os, const Student& student) {
    os << student.surname << " " << student.initials << " | Средний балл: " << student.getAverageGrade();
    return os;
}

istream& operator>>(istream& is, Student& student) {
    cout << "Введите фамилию: ";
    is >> student.surname;
    cout << "Введите инициалы: ";
    is >> student.initials;

    cout << "Введите количество оценок: ";
    is >> student.gradeCount;

    if (student.gradeCount <= 0) {
        throw invalid_argument("Количество оценок должно быть положительным");
    }

    student.grades = new double[student.gradeCount];
    for (int i = 0; i < student.gradeCount; ++i) {
        cout << "Введите оценку " << i + 1 << ": ";
        is >> student.grades[i];
    }

    return is;
}

// Метод для подсчета среднего балла
double Student::getAverageGrade() const {
    if (gradeCount == 0) return 0.0; // Если нет оценок, возвращаем 0
    double sum = 0.0;
    for (int i = 0; i < gradeCount; ++i) {
        sum += grades[i]; // Суммируем все оценки
    }
    return sum / gradeCount; // Возвращаем среднее
}

const string& Student::getSurname() const {
    return surname;
}

void Student::setSurname(const string& surname) {
    this->surname = surname;
}

void Student::setGrades(double* grades, int count) {
    delete[] this->grades; // освобождаем старый массив
    this->gradeCount = count;
    this->grades = new double[count];
    for (int i = 0; i < count; ++i) {
        this->grades[i] = grades[i];
    }
}