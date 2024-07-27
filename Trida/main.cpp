#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Class {
private:
    std::string name;
    int grade;

public:
    Class(const std::string& className, int classGrade)
        : name(className), grade(classGrade) {}

    std::string getName() const {
        return name;
    }

    int getGrade() const {
        return grade;
    }

    void promote() {
        grade++;
        name[0] = '0' + grade;
    }
};

class Student {
private:
    std::string firstName;
    std::string lastName;
    int age;
    Class& studentClass;

public:
    Student(const std::string& fName, const std::string& lName, int a, Class& sClass)
        : firstName(fName), lastName(lName), age(a), studentClass(sClass) {}

    void displayInfo() const {
        std::cout << "Jméno: " << firstName << " " << lastName << ", Věk: " << age
                  << ", Třída: " << studentClass.getName() << std::endl;
    }

    void promote() {
        studentClass.promote();
    }

    std::string getClassName() const {
        return studentClass.getName();
    }
};

std::vector<Student> filterStudentsByClass(const std::vector<Student>& students, const std::string& className) {
    std::vector<Student> filteredStudents;
    for (const auto& student : students) {
        if (student.getClassName() == className) {
            filteredStudents.push_back(student);
        }
    }
    return filteredStudents;
}

int main() {
    Class class1A("1A", 1);
    Class class1B("1B", 1);
    Class class2A("2A", 2);

    std::vector<Student> students;
    students.emplace_back("Jan", "Novák", 16, class1A);
    students.emplace_back("Petra", "Svobodová", 17, class1B);
    students.emplace_back("Lukáš", "Král", 15, class2A);
    students.emplace_back("Eva", "Kučerová", 16, class1A);
    students.emplace_back("Petra", "Jirásková", 14, class1A);

    std::cout << "Všichni studenti:\n";
    for (const auto& student : students) {
        student.displayInfo();
    }

    std::cout << "\nStudenti ve třídě 1A:\n";
    auto studentsIn1A = filterStudentsByClass(students, "1A");
    for (const auto& student : studentsIn1A) {
        student.displayInfo();
    }

    return 0;
}
