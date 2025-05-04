#include <iostream>
#include <climits>
using namespace std;

int optCost(int freq[], int n) {
    int cost[n][n] = {0};
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                cost[i][j] = min(cost[i][j], (r > i ? cost[i][r-1] : 0) + (r < j ? cost[r+1][j] : 0) + freq[r]);
            }
        }
    }
    return cost[0][n-1];
}

int main() {
    int n;
    cin >> n;
    int freq[n];
    for (int i = 0; i < n; i++) cin >> freq[i];
    cout << optCost(freq, n) << endl;
    return 0;
}
