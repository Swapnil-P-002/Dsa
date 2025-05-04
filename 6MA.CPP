#include <iostream>
#include <cstdlib>
using namespace std;

int cost[10][10], i, j, k, n, qu[10], front = 0, rear = 0, v;
int visit[10] = {0}, visited[10] = {0}; // BFS tracking
int stk[10], top = 0, visit1[10] = {0}, visited1[10] = {0}; // DFS tracking

int main()
{
    int m;
    cout << "Enter number of vertices : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> m;
    
    // Initialize adjacency matrix with 0
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cost[i][j] = 0;
    
    cout << "\nEnter edges (vertex1 vertex2):\n";
    for (k = 0; k < m; k++)  // Use 0-based indexing
    {
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1;
    }
    
    // Display adjacency matrix
    cout << "The adjacency matrix of the graph is:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }
    
    // BFS Implementation
    cout << "Enter initial vertex for BFS (0-based): ";
    cin >> v;
    cout << "The BFS traversal is: \n";
    
    cout << v << " ";
    visited[v] = 1;
    qu[rear++] = v;
    
    while (front < rear)
    {
        v = qu[front++];
        for (j = 0; j < n; j++)
        {
            if (cost[v][j] != 0 && visited[j] == 0)
            {
                cout << j << " ";
                visited[j] = 1;
                qu[rear++] = j;
            }
        }
    }
    
    // DFS Implementation
    cout << "\nEnter initial vertex for DFS (0-based): ";
    cin >> v;
    cout << "The DFS traversal is: \n";
    
    cout << v << " ";
    visited1[v] = 1;
    stk[top++] = v;
    
    while (top > 0)
    {
        v = stk[--top];
        for (j = n - 1; j >= 0; j--)
        {
            if (cost[v][j] != 0 && visited1[j] == 0)
            {
                cout << j << " ";
                visited1[j] = 1;
                stk[top++] = v; // Push current node again
                stk[top++] = j; // Push the next node
                break;
            }
        }
    }

    return 0;
}