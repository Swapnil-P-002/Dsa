#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
public:
    vector<vector<int>> adjList;
    int n;

    Graph(int n) {
        this->n = n;
        adjList.resize(n);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // Undirected graph
    }

    // BFS using adjacency list
    void BFS(int start) {
        vector<bool> visited(n, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int neighbor : adjList[v]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // DFS using adjacency list
    void DFS(int start) {
        vector<bool> visited(n, false);
        stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int v = s.top();
            s.pop();
            if (!visited[v]) {
                visited[v] = true;
                cout << v << " ";

                // Push neighbors in reverse order for proper DFS
                for (int i = adjList[v].size() - 1; i >= 0; --i) {
                    if (!visited[adjList[v][i]]) {
                        s.push(adjList[v][i]);
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    Graph g(n);

    cout << "Enter number of edges: ";
    cin >> m;
    cout << "Enter edges (u v) (0-indexed):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter the starting vertex for BFS: ";
    cin >> start;
    cout << "BFS Traversal: ";
    g.BFS(start);

    cout << "Enter the starting vertex for DFS: ";
    cin >> start;
    cout << "DFS Traversal: ";
    g.DFS(start);

    return 0;
}
