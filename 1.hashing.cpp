#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int TABLE_SIZE = 10; //Here we are implementing size of table

// Entry structure
struct Entry { 
    string name; //name in for of alphabate hence here we use string data type
    string phone;
};

// Linear Probing Hash Table
class LinearProbingHashTable {
    vector<Entry> table; //entry for table
    vector<bool> occupied; //bool for get the value ie. bucket is full or not

public:
    LinearProbingHashTable() : table(TABLE_SIZE), occupied(TABLE_SIZE, false) {}

    int hashFunction(const string& key) {
        int hash = 0;
        for (char ch : key) {
            hash = (hash + ch) % TABLE_SIZE;
        }
        return hash;
    }
//Insertion 
    void insert(const string& name, const string& phone) {
        int index = hashFunction(name);
        int originalIndex = index;
        while (occupied[index]) {
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) {
                cout << "Hash table is full!\n";
                return;
            }
        }
        table[index] = {name, phone};
        occupied[index] = true;
    }
//Searching
    bool search(const string& name, string& phone, int& comparisons) {
        int index = hashFunction(name);
        int originalIndex = index;
        comparisons = 0;
        while (occupied[index]) {
            comparisons++;
            if (table[index].name == name) {
                phone = table[index].phone;
                return true;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) break;
        }
        return false;
    }
};

// Chaining Hash Table
class ChainingHashTable {
    vector<list<Entry>> table;

public:
    ChainingHashTable() : table(TABLE_SIZE) {}

    int hashFunction(const string& key) {
        int hash = 0;
        for (char ch : key) {
            hash = (hash + ch) % TABLE_SIZE;
        }
        return hash;
    }

    void insert(const string& name, const string& phone) {
        int index = hashFunction(name);
        table[index].push_back({name, phone});
    }

    bool search(const string& name, string& phone, int& comparisons) {
        int index = hashFunction(name);
        comparisons = 0;
        for (const auto& entry : table[index]) {
            comparisons++;
            if (entry.name == name) {
                phone = entry.phone;
                return true;
            }
        }
        return false;
    }
};

int main() {
    LinearProbingHashTable linearTable;
    ChainingHashTable chainingTable;

    int choice;
    string name, phone;

    do {
        cout << "\nTelephone Book Menu:\n";
        cout << "1. Insert\n2. Search\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter phone number: ";
                cin >> phone;
                linearTable.insert(name, phone);
                chainingTable.insert(name, phone);
                break;

            case 2:
                cout << "Enter name to search: ";
                cin >> name;
                int linearComparisons, chainingComparisons;
                if (linearTable.search(name, phone, linearComparisons)) {
                    cout << "Linear Probing: Found \"" << name << "\" with phone " << phone << " in " << linearComparisons << " comparisons.\n";
                } else {
                    cout << "Linear Probing: \"" << name << "\" not found.\n";
                }
                if (chainingTable.search(name, phone, chainingComparisons)) {
                    cout << "Chaining: Found \"" << name << "\" with phone " << phone << " in " << chainingComparisons << " comparisons.\n";
                } else {
                    cout << "Chaining: \"" << name << "\" not found.\n";
                }
                break;

            case 3:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}