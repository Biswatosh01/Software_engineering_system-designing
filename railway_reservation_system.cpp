#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

class Train {
public:
    string trainId;
    string name;
    int totalSeats;
    int availableSeats;

    Train(string id, string trainName, int seats)
        : trainId(id), name(trainName), totalSeats(seats), availableSeats(seats) {}

    void displayTrain() const {
        cout << "Train ID: " << trainId << ", Name: " << name
             << ", Total Seats: " << totalSeats << ", Available Seats: " << availableSeats << endl;
    }
};

class Passenger {
public:
    string passengerId;
    string name;

    Passenger(string id, string passengerName)
        : passengerId(id), name(passengerName) {}

    void displayPassenger() const {
        cout << "Passenger ID: " << passengerId << ", Name: " << name << endl;
    }
};

class Reservation {
public:
    string reservationId;
    string trainId;
    string passengerId;
    int numSeats;

    Reservation(string id, string train, string passenger, int seats)
        : reservationId(id), trainId(train), passengerId(passenger), numSeats(seats) {}

    void displayReservation() const {
        cout << "Reservation ID: " << reservationId << ", Train ID: " << trainId
             << ", Passenger ID: " << passengerId << ", Number of Seats: " << numSeats << endl;
    }
};

class RailwayReservationSystem {
public:
    vector<Train> trains;
    vector<Passenger> passengers;
    vector<Reservation> reservations;

    void addTrain(string trainId, string trainName, int totalSeats) {
        Train newTrain(trainId, trainName, totalSeats);
        trains.push_back(newTrain);
        cout << "Train added successfully." << endl;
    }

    void addPassenger(string passengerId, string passengerName) {
        Passenger newPassenger(passengerId, passengerName);
        passengers.push_back(newPassenger);
        cout << "Passenger added successfully." << endl;
    }

    void makeReservation(string reservationId, string trainId, string passengerId, int numSeats) {
        // Check if the train and passenger exist
        auto trainIt = find_if(trains.begin(), trains.end(), [trainId](const Train& t) {
            return t.trainId == trainId;
        });

        auto passengerIt = find_if(passengers.begin(), passengers.end(), [passengerId](const Passenger& p) {
            return p.passengerId == passengerId;
        });

        if (trainIt != trains.end() && passengerIt != passengers.end()) {
            // Check if there are enough available seats
            if (trainIt->availableSeats >= numSeats) {
                Reservation newReservation(reservationId, trainId, passengerId, numSeats);
                reservations.push_back(newReservation);

                // Update available seats in the train
                trainIt->availableSeats -= numSeats;

                cout << "Reservation made successfully." << endl;
            } else {
                cout << "Not enough available seats on the train." << endl;
            }
        } else {
            cout << "Train or passenger not found." << endl;
        }
    }

    void displayAllTrains() const {
        cout << "All Trains:" << endl;
        for (const auto& train : trains) {
            train.displayTrain();
        }
    }

    void displayAllPassengers() const {
        cout << "All Passengers:" << endl;
        for (const auto& passenger : passengers) {
            passenger.displayPassenger();
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
    RailwayReservationSystem reservationSystem;

    // Adding sample trains, passengers, and reservations
    reservationSystem.addTrain("T001", "Express 1", 50);
    reservationSystem.addTrain("T002", "Local 2", 30);
    reservationSystem.addPassenger("P001", "John Doe");
    reservationSystem.addPassenger("P002", "Jane Smith");
    reservationSystem.makeReservation("RES001", "T001", "P001", 3);
    reservationSystem.makeReservation("RES002", "T002", "P002", 2);

    // Displaying all trains, passengers, and reservations
    reservationSystem.displayAllTrains();
    reservationSystem.displayAllPassengers();
    reservationSystem.displayAllReservations();

    return 0;
}
