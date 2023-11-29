#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Doctor {
public:
    string doctorId;
    string name;
    string specialization;

    Doctor(string id, string doctorName, string spec)
        : doctorId(id), name(doctorName), specialization(spec) {}

    void displayDoctor() const {
        cout << "Doctor ID: " << doctorId << ", Name: " << name
             << ", Specialization: " << specialization << endl;
    }
};

class Patient {
public:
    string patientId;
    string name;
    int age;

    Patient(string id, string patientName, int patientAge)
        : patientId(id), name(patientName), age(patientAge) {}

    void displayPatient() const {
        cout << "Patient ID: " << patientId << ", Name: " << name
             << ", Age: " << age << endl;
    }
};

class Appointment {
public:
    string appointmentId;
    string doctorId;
    string patientId;
    string date;

    Appointment(string id, string docId, string patId, string appointmentDate)
        : appointmentId(id), doctorId(docId), patientId(patId), date(appointmentDate) {}

    void displayAppointment() const {
        cout << "Appointment ID: " << appointmentId << ", Doctor ID: " << doctorId
             << ", Patient ID: " << patientId << ", Date: " << date << endl;
    }
};

class HospitalManagementSystem {
public:
    vector<Doctor> doctors;
    vector<Patient> patients;
    vector<Appointment> appointments;

    void addDoctor(string doctorId, string doctorName, string specialization) {
        Doctor newDoctor(doctorId, doctorName, specialization);
        doctors.push_back(newDoctor);
        cout << "Doctor added successfully." << endl;
    }

    void addPatient(string patientId, string patientName, int age) {
        Patient newPatient(patientId, patientName, age);
        patients.push_back(newPatient);
        cout << "Patient added successfully." << endl;
    }

    void scheduleAppointment(string appointmentId, string doctorId, string patientId, string date) {
        Appointment newAppointment(appointmentId, doctorId, patientId, date);
        appointments.push_back(newAppointment);
        cout << "Appointment scheduled successfully." << endl;
    }

    void displayAllDoctors() const {
        cout << "All Doctors:" << endl;
        for (const auto& doctor : doctors) {
            doctor.displayDoctor();
        }
    }

    void displayAllPatients() const {
        cout << "All Patients:" << endl;
        for (const auto& patient : patients) {
            patient.displayPatient();
        }
    }

    void displayAllAppointments() const {
        cout << "All Appointments:" << endl;
        for (const auto& appointment : appointments) {
            appointment.displayAppointment();
        }
    }
};

int main() {
    HospitalManagementSystem hospitalSystem;

    // Adding sample doctors, patients, and appointments
    hospitalSystem.addDoctor("D001", "Dr. Smith", "Cardiology");
    hospitalSystem.addDoctor("D002", "Dr. Johnson", "Orthopedics");
    hospitalSystem.addPatient("P001", "John Doe", 30);
    hospitalSystem.addPatient("P002", "Jane Smith", 25);
    hospitalSystem.scheduleAppointment("A001", "D001", "P001", "2023-01-15");
    hospitalSystem.scheduleAppointment("A002", "D002", "P002", "2023-01-20");

    // Displaying all doctors, patients, and appointments
    hospitalSystem.displayAllDoctors();
    hospitalSystem.displayAllPatients();
    hospitalSystem.displayAllAppointments();

    return 0;
}

