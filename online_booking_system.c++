#include <iostream>
#include <vector>
#include <string>

using namespace std;

class User {
public:
    string userId;
    string name;

    User(string id, string userName)
        : userId(id), name(userName) {}

    void displayUser() const {
        cout << "User ID: " << userId << ", Name: " << name << endl;
    }
};

class Booking {
public:
    string bookingId;
    string userId;
    string venue;
    string date;

    Booking(string id, string user, string venueName, string bookingDate)
        : bookingId(id), userId(user), venue(venueName), date(bookingDate) {}

    void displayBooking() const {
        cout << "Booking ID: " << bookingId << ", User ID: " << userId
             << ", Venue: " << venue << ", Date: " << date << endl;
    }
};

class OnlineBookingSystem {
public:
    vector<User> users;
    vector<Booking> bookings;

    void addUser(string userId, string userName) {
        User newUser(userId, userName);
        users.push_back(newUser);
        cout << "User added successfully." << endl;
    }

    void addBooking(string bookingId, string userId, string venue, string date) {
        Booking newBooking(bookingId, userId, venue, date);
        bookings.push_back(newBooking);
        cout << "Booking added successfully." << endl;
    }

    void displayAllUsers() const {
        cout << "All Users:" << endl;
        for (const auto& user : users) {
            user.displayUser();
        }
    }

    void displayAllBookings() const {
        cout << "All Bookings:" << endl;
        for (const auto& booking : bookings) {
            booking.displayBooking();
        }
    }
};

int main() {
    OnlineBookingSystem bookingSystem;

    // Adding sample users and bookings
    bookingSystem.addUser("U001", "John Doe");
    bookingSystem.addUser("U002", "Jane Smith");
    bookingSystem.addBooking("B001", "U001", "Conference Room A", "2023-01-15");
    bookingSystem.addBooking("B002", "U002", "Auditorium", "2023-01-20");

    // Displaying all users and bookings
    bookingSystem.displayAllUsers();
    bookingSystem.displayAllBookings();

    return 0;
}
