#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Room {
public:
    string roomId;
    int capacity;
    bool isOccupied;

    Room(string id, int roomCapacity)
        : roomId(id), capacity(roomCapacity), isOccupied(false) {}

    void displayRoom() const {
        cout << "Room ID: " << roomId << ", Capacity: " << capacity
             << ", Status: " << (isOccupied ? "Occupied" : "Vacant") << endl;
    }
};

class Guest {
public:
    string guestId;
    string name;

    Guest(string id, string guestName)
        : guestId(id), name(guestName) {}

    void displayGuest() const {
        cout << "Guest ID: " << guestId << ", Name: " << name << endl;
    }
};

class Reservation {
public:
    string reservationId;
    string guestId;
    string roomId;
    string checkInDate;
    string checkOutDate;

    Reservation(string id, string guest, string room, string checkIn, string checkOut)
        : reservationId(id), guestId(guest), roomId(room), checkInDate(checkIn), checkOutDate(checkOut) {}

    void displayReservation() const {
        cout << "Reservation ID: " << reservationId << ", Guest ID: " << guestId
             << ", Room ID: " << roomId << ", Check-In: " << checkInDate
             << ", Check-Out: " << checkOutDate << endl;
    }
};

class HotelManagementSystem {
public:
    vector<Room> rooms;
    vector<Guest> guests;
    vector<Reservation> reservations;

    void addRoom(string roomId, int capacity) {
        Room newRoom(roomId, capacity);
        rooms.push_back(newRoom);
        cout << "Room added successfully." << endl;
    }

    void addGuest(string guestId, string guestName) {
        Guest newGuest(guestId, guestName);
        guests.push_back(newGuest);
        cout << "Guest added successfully." << endl;
    }

    void makeReservation(string reservationId, string guestId, string roomId, string checkIn, string checkOut) {
        Reservation newReservation(reservationId, guestId, roomId, checkIn, checkOut);
        reservations.push_back(newReservation);

        // Mark the room as occupied
        for (auto& room : rooms) {
            if (room.roomId == roomId) {
                room.isOccupied = true;
                break;
            }
        }

        cout << "Reservation made successfully." << endl;
    }

    void displayAllRooms() const {
        cout << "All Rooms:" << endl;
        for (const auto& room : rooms) {
            room.displayRoom();
        }
    }

    void displayAllGuests() const {
        cout << "All Guests:" << endl;
        for (const auto& guest : guests) {
            guest.displayGuest();
        }
    }

    void displayAllReservations() const {
        cout << "All Reservations:" << endl;
        for (const auto& reservation : reservations) {
            reservation.displayReservation();
        }
    }
};

int main() {
    HotelManagementSystem hotelSystem;

    // Adding sample rooms, guests, and reservations
    hotelSystem.addRoom("R001", 2);
    hotelSystem.addRoom("R002", 4);
    hotelSystem.addGuest("G001", "John Doe");
    hotelSystem.addGuest("G002", "Jane Smith");
    hotelSystem.makeReservation("RES001", "G001", "R001", "2023-01-15", "2023-01-20");
    hotelSystem.makeReservation("RES002", "G002", "R002", "2023-02-01", "2023-02-07");

    // Displaying all rooms, guests, and reservations
    hotelSystem.displayAllRooms();
    hotelSystem.displayAllGuests();
    hotelSystem.displayAllReservations();

    return 0;
}
