#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class Person {
public:
    virtual void getDescription() const {
        std::cout << "Toto je osoba." << std::endl;
    }
    virtual ~Person() = default; // Virtuální destruktor
};


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


class Ucitel : public Person {
private:
    std::string firstName;
    std::string lastName;
    std::string subject;

public:
    Ucitel(const std::string& fName, const std::string& lName, const std::string& subj)
        : firstName(fName), lastName(lName), subject(subj) {}

    void getDescription() const override {
        std::cout << "Jméno: " << firstName << " " << lastName << ", Předmět: " << subject << std::endl;
    }
};


class Student : public Person {
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
    
    void getDescription() const override {
           std::cout << "Jméno: " << firstName << " " << lastName << ", Věk: " << age
                     << ", Třída: " << studentClass.getName() << std::endl;
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

   // std::vector<Student> students;
    std::vector<Person*> people;
    people.push_back(new Person());
    people.push_back(new Student("Jan", "Novák", 16, class1A));
    people.push_back(new Student("Petra", "Svobodová", 17, class1B));
    people.push_back(new Student("Lukáš", "Král", 15, class2A));
    people.push_back(new Student("Eva", "Kučerová", 16, class1A));
    people.push_back(new Ucitel("Martin", "Černý", "Matematika"));
    people.push_back(new Ucitel("Jana", "Horáková", "Fyzika"));

    

   // std::cout << "Všichni studenti:\n";
   // for (const auto& student : students) {
   //     student.displayInfo();
   // }

   // std::cout << "\nStudenti ve třídě 1A:\n";
   // auto studentsIn1A = filterStudentsByClass(students, "1A");
   // for (const auto& student : studentsIn1A) {
   //     student.displayInfo();
  //  }
    
    for (const auto& person : people) {
            person->getDescription();
        }

        // Uvolnění paměti
        for (auto& person : people) {
            delete person;
        }
    

    return 0;
}
