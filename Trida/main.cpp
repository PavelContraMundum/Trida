#include <iostream>
#include<string>


class Student {
private:
    std::string firstName;
    std::string lastName;
    int age;
    
public:
    //Konstruktor
    Student(const std::string& fName, const std::string& lName, int a)
    : firstName(fName), lastName(lName), age(a){}
    
    
    //Metoda pro zobrazeni informaci o studentovi
    void displayInfo() const {
        std::cout << "Jméno: " << firstName << " " << lastName << ", Věk: " << age << std::endl;
    }
    
};


int main(int argc, const char * argv[]) {
    
    Student student1("A", "B", 14);
    Student student2("C", "D", 15);
    Student student3("E", "F", 15);
    Student student4("G", "H", 15);
    
    
    //Zobrazeni informaci o studentech
    
    student1.displayInfo();
    student2.displayInfo();
    student3.displayInfo();
    student4.displayInfo();
    
    
    
    return 0;
}
