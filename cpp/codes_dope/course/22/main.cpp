// Copyright 2018 Akash Kwatra

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::transform;

// 22
// flying first class
// Test out classes, as well as vectors and structs
// Creates a plane, adds, removes, and prints passengers

struct passenger {
    string name;
    int age;
    string job;
};

class Airplane {
 private:
    string airline;
    int num_seats;
    int flight_number;
    vector<passenger> passengers;

 public:
    Airplane(string airline, int num_seats, int flight_number) {
        this->airline = airline;
        this->num_seats = num_seats;
        this->flight_number = flight_number;
    }

    void add_passenger(string name, int age, string job) {
        cout << "Attempting to add " << name << " to "
             << airline << " Flight " << flight_number << endl;
        if (passengers.size() >= num_seats) {
            cout << "-- This plane is at capacity" << endl;
        } else {
            transform(job.begin(), job.end(), job.begin(), tolower);
            passengers.push_back(passenger {name, age, job});
            cout << "-- Success" << endl;
        }
    }

    void kick_passenger(int passenger_num) {
        cout << "Kicking " << passengers[passenger_num].name
             << " off of this flight" << endl << endl;
        passengers.erase(passengers.begin() + passenger_num);
    }

    void print_passengers() {
        cout << "Printing Passengers for " << airline
             << " Flight " << flight_number << endl << endl;
        int total_printed = 0;
        for (const passenger &p : passengers) {
            cout << "    Passenger Number :: " << total_printed << endl
                 << "     - " << p.name << " is a " << p.age
                 << " year old " << p.job << endl << endl;
            total_printed++;
        }
        while (total_printed++ < num_seats) {
            cout << "    Passenger Number :: " << total_printed << endl
                 << "     - This seat is empty" << endl << endl;
        }
    }
};

int main() {
    cout << endl << "22 - flying first class" << endl << endl;

    Airplane nyc_flight("JetBlue", 5, 1256);

    nyc_flight.add_passenger("Akash Kwatra", 20, "Student");
    nyc_flight.add_passenger("Sue Anne Davis", 21, "Creature");
    nyc_flight.add_passenger("Benny Singer", 21, "Benny");
    nyc_flight.add_passenger("Donald Trump", 72, "President");
    cout << endl;
    nyc_flight.print_passengers();
    nyc_flight.kick_passenger(3);
    nyc_flight.print_passengers();
    nyc_flight.add_passenger("Avery Jennings", 21, "Student");
    nyc_flight.add_passenger("Fat Tony", 63, "Mobster");
    nyc_flight.add_passenger("Eshan Kwatra", 15, "Student");
    cout << endl;
    nyc_flight.print_passengers();

    cout << endl;
    return 0;
}

