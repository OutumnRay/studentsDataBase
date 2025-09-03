#include <gtest/gtest.h>
#include "student_database.h"


class StudentDatabaseTest : public ::testing::Test {
protected:
    std::vector<Student> database;

    void SetUp() override {
        database.clear();
    }
};

// Юнит-тест для добавления студента
TEST_F(StudentDatabaseTest, AddStudentTest) {
    Student student = {"Иван", 20, "Программирование", 3.5};
    addStudent(database, student);
    ASSERT_EQ(database.size(), 1);
    ASSERT_EQ(database[0].name, "Иван");
}

// Юнит-тест для проверки работы функции поиска минимума и максимума GPA
TEST_F(StudentDatabaseTest, FindMinMaxGPATest) {
    Student student1 = {"Алексей", 22, "Математика", 4.0};
    Student student2 = {"Мария", 21, "Физика", 3.8};
    Student student3 = {"Дмитрий", 23, "Химия", 2.5};

    addStudent(database, student1);
    addStudent(database, student2);
    addStudent(database, student3);

    auto [minStudent, maxStudent] = findMinMaxGPA(database);
    
    ASSERT_EQ(minStudent.gpa, 2.5);
    ASSERT_EQ(maxStudent.gpa, 4.0);
}

// Тест для вывода списка студентов
TEST_F(StudentDatabaseTest, DisplayStudentsTest) {
    Student student1 = {"Иван", 20, "Программирование", 3.5};
    Student student2 = {"Анна", 21, "Литература", 4.0};

    addStudent(database, student1);
    addStudent(database, student2);

    // Можно перенаправить вывод, чтобы проверить его содержание
    testing::internal::CaptureStdout();
    displayStudents(database);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_TRUE(output.find("Иван") != std::string::npos);
    ASSERT_TRUE(output.find("Анна") != std::string::npos);
}

// Тест на добавление нескольких студентов
TEST_F(StudentDatabaseTest, MultipleAddStudentsTest) {
    for (int i = 0; i < 5; ++i) {
        Student student = {"Student" + std::to_string(i), 18 + i, "Специальность" + std::to_string(i), 3.0 + i * 0.1};
        addStudent(database, student);
    }
    ASSERT_EQ(database.size(), 5);
}

// Тест на работу с пустой базой данных
TEST_F(StudentDatabaseTest, EmptyDatabaseTest) {
    auto [minStudent, maxStudent] = findMinMaxGPA(database);

    ASSERT_EQ(minStudent.gpa, 0); 
    ASSERT_EQ(maxStudent.gpa, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
