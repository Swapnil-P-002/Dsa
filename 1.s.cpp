#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, string> phoneBook;

    // Inserting clients
    phoneBook["Alice"] = "9876543210";
    phoneBook["Bob"] = "9123456780";

    // Looking up clients
    string name;
    cout << "Enter name to look up: ";
    cin >> name;

    if (phoneBook.find(name) != phoneBook.end()) {
        cout << name << "'s number: " << phoneBook[name] << endl;
    } else {
        cout << "Number not found for " << name << endl;
    }

    return 0;
}