#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Subject class
class Subject {
public:
    string subjectName;
    int credit;
    float gradePoint;

    Subject(string name, int cr, float gp) {
        subjectName = name;
        credit = cr;
        gradePoint = gp;
    }
};

// Student class
class Student {
public:
    string name;
    vector<Subject> subjects;

    Student(string studentName) {
        name = studentName;
    }

    void addSubject(string subjectName, int credit, float gradePoint) {
        Subject newSubject(subjectName, credit, gradePoint);
        subjects.push_back(newSubject);
    }

    float calculateCGPA() {
        int totalCredit = 0;
        float weightedGradePoint = 0;
        for (const Subject &subj : subjects) {
            totalCredit += subj.credit;
            weightedGradePoint += subj.credit * subj.gradePoint;
        }
        return (totalCredit != 0) ? (weightedGradePoint / totalCredit) : 0;
    }

    void display() {
        cout << "\nStudent Name: " << name << endl;
        cout << "Course Details:\n";
        cout << "----------------------------\n";
        cout << "Subject\t\tCredit\tGrade\n";
        for (const Subject &subj : subjects) {
            cout << subj.subjectName << "\t\t" << subj.credit << "\t" << subj.gradePoint << endl;
        }
        cout << "----------------------------\n";
        float cgpa = calculateCGPA();
        cout << "Final CGPA: " << cgpa << endl;
    }
};

// Main function
int main() {
    string studentName;
    int numSub;

    cout << "Enter student's name: ";
    getline(cin, studentName);

    Student student(studentName);

    cout << "Enter the number of courses: ";
    cin >> numSub;

    for (int i = 0; i < numSub; i++) {
        string subjectName;
        int credit;
        float gradePoint;

        cout << "\nEnter name of course " << (i + 1) << ": ";
        cin.ignore();
        getline(cin, subjectName);

        cout << "Enter credit hours: ";
        cin >> credit;

        cout << "Enter grade (e.g., 4.0 for A): ";
        cin >> gradePoint;

        student.addSubject(subjectName, credit, gradePoint);
    }

    student.display();

    return 0;
}
