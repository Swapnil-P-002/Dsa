#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    int n, cost[10][10], visited[10] = {0}, totalCost = 0;
    string city[10];

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter flight costs:\n";
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) cost[i][j] = 0;
            else {
                cout << "Cost from city " << i+1 << " to city " << j+1 << ": ";
                cin >> cost[i][j];
                cost[j][i] = cost[i][j];
            }
        }
    }

    visited[0] = 1;  // Start with the first city
    for (int edges = 1; edges < n; edges++) {
        int minCost = INT_MAX, u = -1, v = -1;
        
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] && cost[i][j] < minCost) {
                        minCost = cost[i][j];
                        u = i; v = j;
                    }
                }
            }
        }

        visited[v] = 1;  // Mark city v as visited
        totalCost += minCost;
    }

    cout << "Minimum Total Flight Cost: " << totalCost << endl;

    return 0;
}
