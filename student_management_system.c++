#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Course {
public:
    string courseId;
    string courseName;

    Course(string id, string name)
        : courseId(id), courseName(name) {}

    void displayCourse() const {
        cout << "Course ID: " << courseId << ", Name: " << courseName << endl;
    }
};

class Student {
public:
    string studentId;
    string name;
    vector<Course> enrolledCourses;

    Student(string id, string studentName)
        : studentId(id), name(studentName) {}

    void displayStudent() const {
        cout << "Student ID: " << studentId << ", Name: " << name << endl;
        cout << "Enrolled Courses:" << endl;
        for (const auto& course : enrolledCourses) {
            course.displayCourse();
        }
    }

    void enrollCourse(const Course& course) {
        enrolledCourses.push_back(course);
        cout << "Enrolled in course: " << course.courseName << endl;
    }
};

class StudentManagementSystem {
public:
    vector<Student> students;
    vector<Course> courses;

    void addStudent(string studentId, string studentName) {
        Student newStudent(studentId, studentName);
        students.push_back(newStudent);
        cout << "Student added successfully." << endl;
    }

    void addCourse(string courseId, string courseName) {
        Course newCourse(courseId, courseName);
        courses.push_back(newCourse);
        cout << "Course added successfully." << endl;
    }

    void displayAllStudents() const {
        cout << "All Students:" << endl;
        for (const auto& student : students) {
            student.displayStudent();
        }
    }

    void displayAllCourses() const {
        cout << "All Courses:" << endl;
        for (const auto& course : courses) {
            course.displayCourse();
        }
    }

    Student* findStudent(string studentId) {
        for (auto& student : students) {
            if (student.studentId == studentId) {
                return &student;
            }
        }
        return nullptr;
    }

    Course* findCourse(string courseId) {
        for (auto& course : courses) {
            if (course.courseId == courseId) {
                return &course;
            }
        }
        return nullptr;
    }
};

int main() {
    StudentManagementSystem studentSystem;

    // Adding sample students and courses
    studentSystem.addStudent("S001", "John Doe");
    studentSystem.addStudent("S002", "Jane Smith");
    studentSystem.addCourse("C001", "Computer Science");
    studentSystem.addCourse("C002", "Mathematics");

    // Displaying all students and courses
    studentSystem.displayAllStudents();
    studentSystem.displayAllCourses();

    // Enrolling students in courses
    Student* johnDoe = studentSystem.findStudent("S001");
    Course* computerScience = studentSystem.findCourse("C001");

    if (johnDoe != nullptr && computerScience != nullptr) {
        johnDoe->enrollCourse(*computerScience);
    }

    // Displaying updated information
    studentSystem.displayAllStudents();

    return 0;
}
