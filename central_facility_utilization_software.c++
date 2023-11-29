#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

class Reservation {
public:
    string reservationId;
    string facilityId;
    string userId;
    time_t startTime;
    time_t endTime;

    Reservation(string id, string facility, string user, time_t start, time_t end)
        : reservationId(id), facilityId(facility), userId(user), startTime(start), endTime(end) {}

    void displayReservation() const {
        cout << "Reservation ID: " << reservationId << ", Facility ID: " << facilityId
             << ", User ID: " << userId << ", Start Time: " << ctime(&startTime)
             << ", End Time: " << ctime(&endTime);
    }
};

class Facility {
public:
    string facilityId;
    string name;
    int capacity;
    vector<Reservation> reservations;

    Facility(string id, string facilityName, int facilityCapacity)
        : facilityId(id), name(facilityName), capacity(facilityCapacity) {}

    void displayFacility() const {
        cout << "Facility ID: " << facilityId << ", Name: " << name << ", Capacity: " << capacity << endl;
    }
};

class FacilityManagementSystem {
public:
    vector<Facility> facilities;
    vector<Reservation> reservations;

    void addFacility(string facilityId, string facilityName, int capacity) {
        Facility newFacility(facilityId, facilityName, capacity);
        facilities.push_back(newFacility);
        cout << "Facility added successfully." << endl;
    }

    void displayAllFacilities() const {
        cout << "All Facilities:" << endl;
        for (const auto& facility : facilities) {
            facility.displayFacility();
        }
    }

    const Facility* findFacility(string facilityId) const; // Declaration

    bool isFacilityAvailable(string facilityId, time_t startTime, time_t endTime) const {
        const Facility* facility = findFacility(facilityId);
        if (facility != nullptr) {
            for (const auto& reservation : facility->reservations) {
                if ((startTime >= reservation.startTime && startTime < reservation.endTime) ||
                    (endTime > reservation.startTime && endTime <= reservation.endTime)) {
                    return false; // Facility is not available during the requested time
                }
            }
            return true; // Facility is available
        }
        return false; // Facility not found
    }

    void reserveFacility(string facilityId, string userId, time_t startTime, time_t endTime) {
        Facility* facility = const_cast<Facility*>(findFacility(facilityId));
        if (facility != nullptr) {
            if (isFacilityAvailable(facilityId, startTime, endTime)) {
                string reservationId = "R" + to_string(reservations.size() + 1);
                Reservation newReservation(reservationId, facilityId, userId, startTime, endTime);
                facility->reservations.push_back(newReservation);
                reservations.push_back(newReservation);
                cout << "Facility reserved successfully. Reservation ID: " << reservationId << endl;
            } else {
                cout << "Facility not available during the requested time." << endl;
            }
        } else {
            cout << "Facility not found." << endl;
        }
    }

    void displayAllReservations() const {
        cout << "All Reservations:" << endl;
        for (const auto& reservation : reservations) {
            reservation.displayReservation();
        }
    }
};

const Facility* FacilityManagementSystem::findFacility(string facilityId) const {
    for (const auto& facility : facilities) {
        if (facility.facilityId == facilityId) {
            return &facility;
        }
    }
    return nullptr;
}

int main() {
    FacilityManagementSystem facilitySystem;

    // Adding sample facilities
    facilitySystem.addFacility("F001", "Conference Room A", 20);
    facilitySystem.addFacility("F002", "Auditorium", 100);

    // Displaying all facilities
    facilitySystem.displayAllFacilities();

    // Reserving facilities
    time_t startTime = time(nullptr);  // Current time
    time_t endTime = startTime + 3600; // 1 hour later

    facilitySystem.reserveFacility("F001", "U001", startTime, endTime);
    facilitySystem.reserveFacility("F002", "U002", startTime, endTime);

    // Displaying all reservations
    facilitySystem.displayAllReservations();

    return 0;
}
