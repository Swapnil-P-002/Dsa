#include <iostream>
#include <limits.h>
using namespace std;

class FlightNetwork {
    int n, adjacent[10][10];
    string city[10];

public:
    void input();
    void display();
    void Prims();
};

void FlightNetwork::input() {
    cout << "\nEnter number of cities: ";
    cin >> n;
    cout << "Enter city names:\n";
    for (int i = 0; i < n; i++) cin >> city[i];

    cout << "Enter flight costs:\n";
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            if (i == j) adjacent[i][j] = 0;
            else {
                cout << city[i] << " - " << city[j] << ": ";
                cin >> adjacent[i][j];
                adjacent[j][i] = adjacent[i][j];  // Mirror value
            }
        }
}

void FlightNetwork::display() {
    cout << "\nFlight Cost Matrix:\n";
    for (int i = 0; i < n; i++, cout << "\n")
        for (int j = 0; j < n; j++)
            cout << adjacent[i][j] << "\t";
}

void FlightNetwork::Prims() {
    int visit[10] = {0}, cost = 0;
    visit[0] = 1;  // Start with first city

    cout << "\nOptimal Flight Route:\n";

    for (int edges = 1; edges < n; edges++) {
        int minCost = INT_MAX, u = -1, v = -1;

        // Find the minimum edge that connects a visited node to an unvisited one
        for (int i = 0; i < n; i++) {
            if (visit[i]) {  // Node is already part of MST
                for (int j = 0; j < n; j++) {
                    if (!visit[j] && adjacent[i][j] && adjacent[i][j] < minCost) {
                        minCost = adjacent[i][j];
                        u = i;  // Source city
                        v = j;  // Destination city
                    }
                }
            }
        }

        if (v == -1) break;  // In case of disjoint graph

        visit[v] = 1;  // Mark the new city as visited
        cout << city[u] << " -> " << city[v] << " (" << minCost << ") -> ";
        cost += minCost;
    }

    cout << "End\nMinimum Total Flight Cost: " << cost << "\n";
}

int main() {
    FlightNetwork net;
    int choice;
    do {
        cout << "\n1. Enter number of Flights\n2. Display Flight Cost Matrix\n3. Find Optimal Flight Connections (MST)\n4. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) net.input();
        else if (choice == 2) net.display();
        else if (choice == 3) net.Prims();
    } while (choice != 4);
}