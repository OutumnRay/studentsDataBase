#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Функция для добавления студента в базу данных
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Введите имя студента: ";
    std::cin >> student.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> student.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

// Функция для вывода всех студентов из базы данных
void displayStudents(const std::vector<Student>& database) {
    std::cout << "Список студентов:\n";
    for (const Student& student : database) {
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

// Функция для поиска студента с наименьшим и наибольшим баллом
void findMinMaxGPA(const std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "Список студентов пуст.\n";
        return;
    }

    double minGPA = std::numeric_limits<double>::max();
    double maxGPA = std::numeric_limits<double>::lowest();
    Student minStudent;
    Student maxStudent;

    for (const Student& student : database) {
        if (student.gpa < minGPA) {
            minGPA = student.gpa;
            minStudent = student;
        }
        if (student.gpa > maxGPA) {
            maxGPA = student.gpa;
            maxStudent = student;
        }
    }

    std::cout << "Студент с наименьшим баллом:\n";
    std::cout << "Имя: " << minStudent.name << "\n";
    std::cout << "Возраст: " << minStudent.age << "\n";
    std::cout << "Специальность: " << minStudent.major << "\n";
    std::cout << "Средний балл: " << minStudent.gpa << "\n\n";

    std::cout << "Студент с наибольшим баллом:\n";
    std::cout << "Имя: " << maxStudent.name << "\n";
    std::cout << "Возраст: " << maxStudent.age << "\n";
    std::cout << "Специальность: " << maxStudent.major << "\n";
    std::cout << "Средний балл: " << maxStudent.gpa << "\n\n";
}

int main() {
    std::vector<Student> database;

    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Найти студента с наименьшим и наибольшим баллом\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(database);
                break;
            case 2:
                displayStudents(database);
                break;
            case 3:
                findMinMaxGPA(database);
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
