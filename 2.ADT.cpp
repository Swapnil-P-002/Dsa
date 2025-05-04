#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Dictionary {
private:
unordered_map<string, string> hashTable; // Stores key-value pairs

public:
// Insert a key-value pair into the dictionary
void insert(const string &key, const string &value) {
if (hashTable.find(key) != hashTable.end()) {
cout << "Key '" << key << "' already exists. Updating its value.\n";
}
hashTable[key] = value;
cout << "Inserted/Updated: (" << key << ", " << value << ")\n";
}

// Find a value by its key
void find(const string &key) {
if (hashTable.find(key) != hashTable.end()) {
cout << "Found: (" << key << ", " << hashTable[key] << ")\n";
} else {
cout << "Key '" << key << "' not found.\n";
    }
}

// Delete a key-value pair by its key
void remove(const string &key) {
if (hashTable.erase(key)) {
cout << "Key '" << key << "' deleted successfully.\n";
} else {
cout << "Key '" << key << "' not found.\n";
    }
}

// Display all key-value pairs in the dictionary
void display() {
if (hashTable.empty()) {
cout << "The dictionary is empty.\n";
} else {
cout << "Current dictionary contents:\n";
for (const auto &pair : hashTable) {
cout << "(" << pair.first << ", " << pair.second << ")\n";
                                }   
        }
    }
};


int main() {
Dictionary dict;
int choice;
string key, value;

do {
cout << "\nDictionary Operations:\n";
cout << "1. Insert\n";
cout << "2. Find\n";
cout << "3. Delete\n";
cout << "4. Display\n";
cout << "5. Exit\n";
cout << "Enter your choice: ";
cin >> choice;

switch (choice) {
case 1:
cout << "Enter key: ";
cin >> key;
cout << "Enter value: ";
cin >> value;
dict.insert(key, value);
break;

case 2:
cout << "Enter key to find: ";
cin >> key;
dict.find(key);
break;

case 3:
cout << "Enter key to delete: ";
cin >> key;
dict.remove(key);
break;

case 4:
dict.display();
break;

case 5:
cout << "Exiting program.\n";
break;
default:
cout << "Invalid choice. Please try again.\n";
    }   
} while (choice != 5);
return 0;
}