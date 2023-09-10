#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Simulated ambulance data
struct Ambulance {
    string name;
    string hospital;
    string contact;
};

// User class to represent user profiles
class User {
public:
    string username;
    string password;
    vector<pair<string, string>> bookings;

    User(string uname, string pwd) : username(uname), password(pwd) {}
};
// Function to find the nearest ambulance
Ambulance findNearestAmbulance() {
    // Simulated ambulance data
    vector<Ambulance> ambulances = {
        {"Ambulance A", "Hospital 1", "+9892384291"},
        {"Ambulance B", "Hospital 2", "+9876543210"},
        {"Ambulance C", "Hospital 3", "+9988776655"}
    };

    // Simulate random selection for demonstration purposes
    int index = rand() % ambulances.size();
    return ambulances[index];
}
// Function to register a new user
void registerUser(vector<User>& users) {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    for (const User& user : users) {
        if (user.username == username) {
            cout << "Username already exists. Please choose another.\n";
            return;
        }
    }

    users.push_back(User(username, password));
    cout << "Registration successful!\n";
}
// Function to log in
User* login(vector<User>& users) {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    for (User& user : users) {
        if (user.username == username && user.password == password) {
            return &user;
        }
    }

    cout << "Invalid credentials. Please try again.\n";
    return nullptr;
}
// Function to book an ambulance
void bookAmbulance(User* user) {
    string ambulance_size, pickup_point, hospital, date, time;
    cout << "Enter ambulance size (Small/Medium/Large): ";
    cin >> ambulance_size;
    cout << "Enter pickup point: ";
    cin >> pickup_point;
    cout << "Enter hospital: ";
    cin >> hospital;
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> date;
    cout << "Enter time (HH:MM): ";
    cin >> time;

    // Find the nearest ambulance
    Ambulance nearestAmbulance = findNearestAmbulance();

    // Display booking details and nearest ambulance information
    cout << "Booking successful!\n";
    cout << "Ambulance Name: " << nearestAmbulance.name << endl;
    cout << "Hospital: " << nearestAmbulance.hospital << endl;
    cout << "Contact: " << nearestAmbulance.contact << endl;
    cout << "Estimated Time of Arrival: " << "15 minutes (example)\n";

    // Record the booking for the user
    user->bookings.push_back(make_pair(ambulance_size, pickup_point));
}
// Function to view user's bookings
void viewBookings(const User* user) {
    cout << "Your Bookings:\n";
    for (const pair<string, string>& booking : user->bookings) {
        cout << "Ambulance Size: " << booking.first << ", Pickup Point: " << booking.second << endl;
    }
}
int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    vector<User> users;
    User* currentUser = nullptr;

    while (true) {
        // ... (Menu and user interaction code)
    }

    return 0;
}
