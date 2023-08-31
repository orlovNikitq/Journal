#include <iostream>
#include <vector>
#include <string>

class Discipline {
public:
    std::string name;
    std::vector<int> grades;

    Discipline(const std::string& name) {
        this->name = name;
    }
    void addGrade(int grade) {
        grades.push_back(grade);
    }
};

class Student {
public:
    int id;
    std::string fullName;
    std::vector<Discipline> disciplines;

    Student(int _id, const std::string& _fullName)
        : id(_id), fullName(_fullName) {}

    void addDisciplineAndGrade(const std::string& disciplineName, int grade) {
        Discipline newDiscipline(disciplineName);
        newDiscipline.addGrade(grade);
        disciplines.push_back(newDiscipline);
    }
};

class Group {
    std::vector<Student> students;
public:

    void addStudent(int id, const std::string& fullName) {
        students.push_back(Student(id, fullName));
    }

    void removeStudent(int id) {
        for (auto i = students.begin(); i != students.end(); i++) {
            if (i->id == id) {
                students.erase(i);
                break;
            }
        }
    }

    void printAllStudents() {
        for (auto& student : students) {
            std::cout << "ID: " << student.id << "   Name: " << student.fullName << std::endl;
        }
    }

    Student* search(int id) {
        for (auto& student : students) {
            if (student.id == id) {
                return &student;
            }
        }
        return nullptr;
    }

    void addDiscipline(int studentId, const std::string& disciplineName, int grade) { 
        if (auto student = search(studentId)) {
            student->addDisciplineAndGrade(disciplineName, grade);
        }
    }
};

int main() {
    Group group;

    group.addStudent(1, "Ivan Ivanov");
    group.addStudent(2, "Maria Petrova");

    group.addDiscipline(1, "Math", 4);    
    group.addDiscipline(2, "Physics", 2); 
    group.printAllStudents();
    group.removeStudent(2);
    std::cout << std::endl;
    group.printAllStudents();
    std::cout << std::endl;
    group.printAllStudents();
}
