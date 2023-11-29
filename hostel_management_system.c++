#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    string studentId;
    string name;
    string course;
    int roomNumber;

    Student(string id, string studentName, string studentCourse)
        : studentId(id), name(studentName), course(studentCourse), roomNumber(-1) {}

    void displayStudent() const {
        cout << "Student ID: " << studentId << ", Name: " << name << ", Course: " << course
             << ", Room Number: " << (roomNumber != -1 ? to_string(roomNumber) : "Not Assigned") << endl;
    }
};

class Room {
public:
    int roomNumber;
    int capacity;
    vector<Student*> occupants;

    Room(int number, int roomCapacity)
        : roomNumber(number), capacity(roomCapacity) {}

    void displayRoom() const {
        cout << "Room Number: " << roomNumber << ", Capacity: " << capacity << ", Occupants: " << occupants.size() << endl;
    }
};

class Hostel {
public:
    vector<Student> students;
    vector<Room> rooms;

    void admitStudent(string studentId, string studentName, string studentCourse) {
        Student newStudent(studentId, studentName, studentCourse);
        students.push_back(newStudent);
        cout << "Student admitted successfully." << endl;
    }

    void createRoom(int roomNumber, int roomCapacity) {
        Room newRoom(roomNumber, roomCapacity);
        rooms.push_back(newRoom);
        cout << "Room created successfully." << endl;
    }

    void displayAllStudents() const {
        cout << "All Students:" << endl;
        for (const auto& student : students) {
            student.displayStudent();
        }
    }

    void displayAllRooms() const {
        cout << "All Rooms:" << endl;
        for (const auto& room : rooms) {
            room.displayRoom();
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

    Room* findAvailableRoom() {
        for (auto& room : rooms) {
            if (room.occupants.size() < room.capacity) {
                return &room;
            }
        }
        return nullptr;
    }

    void assignRoom(string studentId) {
        Student* student = findStudent(studentId);
        if (student != nullptr) {
            Room* room = findAvailableRoom();
            if (room != nullptr) {
                student->roomNumber = room->roomNumber;
                room->occupants.push_back(student);
                cout << "Room assigned successfully." << endl;
            } else {
                cout << "No available rooms." << endl;
            }
        } else {
            cout << "Student not found." << endl;
        }
    }
};

int main() {
    Hostel hostel;

    // Admitting students and creating rooms
    hostel.admitStudent("S001", "John Doe", "Computer Science");
    hostel.admitStudent("S002", "Jane Smith", "Electrical Engineering");
    hostel.createRoom(101, 2);
    hostel.createRoom(102, 3);

    // Displaying all students and rooms
    hostel.displayAllStudents();
    hostel.displayAllRooms();

    // Assigning rooms to students
    hostel.assignRoom("S001");
    hostel.assignRoom("S002");

    // Displaying updated information
    hostel.displayAllStudents();
    hostel.displayAllRooms();

    return 0;
}
