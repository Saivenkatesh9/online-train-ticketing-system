#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Train {
public:
    string name;
    int capacity;
    int availableSeats;

    Train(string n, int cap) : name(n), capacity(cap), availableSeats(cap) {}

    bool bookTicket(int numTickets) {
        if (numTickets > 0 && numTickets <= availableSeats) {
            availableSeats -= numTickets;
            return true;
        }
        return false;
    }

    string getInfo() const {
        string info = "Train: " + name + "\n";
        info += "Available Seats: " + to_string(availableSeats) + "/" + to_string(capacity) + "\n";
        return info;
    }
};

class TicketBookingSystem {
public:
    vector<Train> trains;

    void addTrain(const Train& train) {
        trains.push_back(train);
    }

    Train* findTrain(const string& trainName) {
        for (auto& train : trains) {
            if (train.name == trainName) {
                return &train;
            }
        }
        return nullptr;
    }
};

int main() {
    TicketBookingSystem ticketSystem;

    // Adding trains to the system
    ticketSystem.addTrain(Train("Express 101", 50));
    ticketSystem.addTrain(Train("Local 202", 30));

    // Display available trains
    cout << "Available Trains:\n";
    for (const auto& train : ticketSystem.trains) {
        cout << train.getInfo() << "\n";
    }

    // User booking a ticket
    string selectedTrain;
    cout << "Enter the name of the train you want to book: ";
    getline(cin, selectedTrain);

    Train* selectedTrainPtr = ticketSystem.findTrain(selectedTrain);

    if (selectedTrainPtr) {
        int numTickets;
        cout << "Enter the number of tickets you want to book: ";
        cin >> numTickets;

        if (selectedTrainPtr->bookTicket(numTickets)) {
            cout << "Booking successful!\n";
        } else {
            cout << "Booking failed. Insufficient seats or invalid input.\n";
        }

        // Display updated train information
        cout << selectedTrainPtr->getInfo();
    } else {
        cout << "Train not found.\n";
    }

    return 0;
}

