#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Define priority levels
enum Priority {
    SERIOUS = 3,   // Top priority
    NON_SERIOUS = 2, // Medium priority
    GENERAL_CHECKUP = 1 // Least priority
};

// Patient struct to store patient information
struct Patient {
    string name;
    Priority priority;
    
    // Constructor to initialize Patient details
    Patient(string n, Priority p) : name(n), priority(p) {}

    // For priority queue to compare patients based on priority
    bool operator<(const Patient& p) const {
        return priority < p.priority; // Higher priority comes first
    }
};

int main() {
    priority_queue<Patient> pq;

    pq.push(Patient("John", SERIOUS));
    pq.push(Patient("Alice", NON_SERIOUS));
    pq.push(Patient("Bob", GENERAL_CHECKUP));
    pq.push(Patient("Eve", SERIOUS));
    pq.push(Patient("Mike", NON_SERIOUS));

    cout << "Patients being attended to in order of priority:\n";
    while (!pq.empty()) {
        Patient p = pq.top();
        pq.pop();
        cout << p.name << " (Priority: " << p.priority << ")\n";
    }

    return 0;
}
