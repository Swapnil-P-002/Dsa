#include <iostream>
#include <vector>
using namespace std;

struct Node {
    string name;
    vector<Node*> kids;
};

Node* make() {
    Node* n = new Node;
    cout << "Name of Chapter: ";
    getline(cin, n->name);
    int c;
    cout << "How many subparts? ";
    cin >> c;
    cin.ignore();
    for (int i = 0; i < c; ++i) {
        n->kids.push_back(make());
    }
    return n;
}

void show(Node* n, int d = 0) {
    for (int i = 0; i < d; ++i) cout << "  ";
    cout << n->name << endl;
    for (auto k : n->kids) {
        show(k, d + 1);
    }
}

int main() {
    cout << "HIT ENTER TO START CHAPTER STRUCTURE\n";
    cin.ignore();
    Node* root = make();
    cout << "\nDisplaying chapter hierarchy:\n";
    show(root);
    return 0;
}