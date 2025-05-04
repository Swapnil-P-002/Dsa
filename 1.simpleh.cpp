#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int SIZE = 10;
vector<list<pair<string, string>>> table(SIZE);

int hashFunction(string name) {
    int h = 0;
    for (char ch : name) h = (h + ch) % SIZE;
    return h;
}

void insert(string name, string phone) {
    int index = hashFunction(name);
    table[index].push_back({name, phone});
}

void search(string name) {
    int index = hashFunction(name);
    for (auto& entry : table[index]) {
        if (entry.first == name) {
            cout << "Found: " << name << " -> " << entry.second << endl;
            return;
        }
    }
    cout << name << " not found.\n";
}

int main() {
    int choice;
    string name, phone;

    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Name: ";
            cin >> name;
            cout << "Phone: ";
            cin >> phone;
            insert(name, phone);
        } else if (choice == 2) {
            cout << "Search Name: ";
            cin >> name;
            search(name);
        } else if (choice == 3) {
            break;
        }
    }

    return 0;
}