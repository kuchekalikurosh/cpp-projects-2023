#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    vector<string> course; 
};

struct Courses {
    string n;
    vector<string> student;
};

void printStudent(Student s);
void printCourse(Courses c);

int main() {
    Student stu1, stu2, stu3;
    Courses cor1, cor2, cor3;

    stu1.name = "Hitoshi Namasaki";
    stu2.name = "Kotaro Miyanaka";
    stu3.name = "Erkia Meyer";

    cor1.n = "History";
    cor2.n = "Biology";
    cor3.n = "Calculus";

    cor1.student.push_back(stu1.name);
    cor1.student.push_back(stu2.name);
    cor1.student.push_back(stu3.name);
    cor2.student.push_back(stu1.name);
    cor2.student.push_back(stu3.name);
    cor3.student.push_back(stu1.name);
    cor3.student.push_back(stu2.name);

    stu1.course.push_back(cor1.n);
    stu1.course.push_back(cor2.n);
    stu1.course.push_back(cor3.n);
    stu2.course.push_back(cor1.n);
    stu2.course.push_back(cor3.n);
    stu3.course.push_back(cor1.n);
    stu3.course.push_back(cor2.n);

    printStudent(stu1);
    printStudent(stu2);
    printStudent(stu3);

    printCourse(cor1);
    printCourse(cor2);
    printCourse(cor3);
}

void printStudent(Student s) {
    string temp;

    temp = s.name;

    cout << temp << "\n";

    for(int i = 0; i < s.course.size(); i++) {
        cout << s.course[i] << ", ";
    }

    cout << "\n\n";
}

void printCourse(Courses c) {
    string temp;

    temp = c.n;

    cout << temp << ":\n";

    for(int i = 0; i < c.student.size(); i++) {
        cout << c.student[i] << ", ";
    }
    
    cout << "\n\n";
}