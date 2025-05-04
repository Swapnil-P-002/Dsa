#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, string> dict;
    int choice;
    string key, value;

    while (true) {
        cout << "\n1. Insert/Update\n2. Find\n3. Delete\n4. Exit\nChoose: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Key: ";
            cin >> key;
            cout << "Value: ";
            cin >> value;
            dict[key] = value;
            cout << "Saved\n";

        } else if (choice == 2) {
            cout << "Key: ";
            cin >> key;
            if (dict.count(key))
                cout << key << " -> " << dict[key] << "\n";
            else
                cout << "Not found\n";

        } else if (choice == 3) {
            cout << "Key: ";
            cin >> key;
            if (dict.erase(key))
                cout << "Deleted\n";
            else
                cout << "Not found\n";

        } else if (choice == 4) {
            break;

        } else {
            cout << "Invalid\n";
        }
    }

    return 0;
}
