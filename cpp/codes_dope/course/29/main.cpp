// Copyright 2018 Akash Kwatra

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

// 29
// templates in class
// Test out use of class templates
// Create template school, populate with kids and fish, teach them

template <class T>
class School {
    vector<T> students;
 public:
    T get_student(int i) {
        return students[i];
    }
    void teach_students() {
        for (int i = 0; i < students.size(); i++) {
            students[i].teach();
        }
    }
    void add_student(T student) {
        students.push_back(student);
    }
    void dismiss_class() {
        students.clear();
    }
};

class Kid {
    int intelligence;
 public:
    explicit Kid(int i) : intelligence(i) {}
    void show_intelligence() {
        cout << "This kid's intelligence is " << intelligence << endl;
    }
    void teach() {
        intelligence++;
    }
};

class Fish {
 public:
     void teach() {
         cout << "glug glug im a feesh" << endl;
     }
};

int main() {
    cout << endl << "29 - templates in class" << endl << endl;

    School<Kid> high_school = School<Kid>();
    Kid akash = Kid(6);
    Kid eshan = Kid(8);
    akash.show_intelligence();
    eshan.show_intelligence();
    cout << endl;
    cout << "Sending these kiddos to school" << endl;
    high_school.add_student(akash);
    high_school.add_student(eshan);
    high_school.teach_students();
    high_school.get_student(0).show_intelligence();
    high_school.get_student(1).show_intelligence();
    cout << endl;
    cout << "Makin a school of fish" << endl;
    School<Fish> fishies = School<Fish>();
    Fish nemo = Fish();
    Fish freddy = Fish();
    fishies.add_student(nemo);
    fishies.add_student(freddy);
    fishies.teach_students();

    cout << endl;
    return 0;
}

