#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student {
    int roll;
    char name[20];
    char div;
    char address[30];
};

void addStudent() {
    ofstream out("students.dat", ios::binary | ios::app);
    Student s;
    char choice;
    do {
        cout << "\nEnter Roll No: "; cin >> s.roll;
        cout << "Enter Name: "; cin >> s.name;
        cout << "Enter Division: "; cin >> s.div;
        cout << "Enter Address: "; cin >> s.address;
        out.write((char*)&s, sizeof(s));
        cout << "Add another record? (y/n): "; cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    out.close();
}

void displayStudents() {
    ifstream in("students.dat", ios::binary);
    Student s;
    cout << "\nRoll\tName\tDiv\tAddress\n";
    while (in.read((char*)&s, sizeof(s))) {
        if (s.roll != -1)
            cout << s.roll << "\t" << s.name << "\t" << s.div << "\t" << s.address << "\n";
    }
    in.close();
}

void searchStudent() {
    ifstream in("students.dat", ios::binary);
    Student s;
    int rollNo, found = 0;
    cout << "\nEnter Roll No to search: ";
    cin >> rollNo;
    while (in.read((char*)&s, sizeof(s))) {
        if (s.roll == rollNo) {
            cout << "\nRecord Found:\n";
            cout << "Roll: " << s.roll << "\nName: " << s.name << "\nDiv: " << s.div << "\nAddress: " << s.address << "\n";
            found = 1;
            break;
        }
    }
    if (!found)
        cout << "Record not found.\n";
    in.close();
}

void deleteStudent() {
    fstream file("students.dat", ios::in | ios::out | ios::binary);
    Student s;
    int rollNo, pos = 0, found = 0;
    cout << "\nEnter Roll No to delete: ";
    cin >> rollNo;
    while (file.read((char*)&s, sizeof(s))) {
        if (s.roll == rollNo) {
            s.roll = -1;
            strcpy(s.name, "NULL");
            s.div = 'N';
            strcpy(s.address, "NULL");
            file.seekp(pos * sizeof(s));
            file.write((char*)&s, sizeof(s));
            found = 1;
            cout << "Record deleted.\n";
            break;
        }
        pos++;
    }
    if (!found)
        cout << "Record not found.\n";
    file.close();
}

int main() {
    int choice;
    char cont;
    do {
        cout << "\n--- Student Record System ---";
        cout << "\n1. Add\n2. Display\n3. Search\n4. Delete\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: return 0;
            default: cout << "Invalid choice.\n";
        }
        cout << "Continue? (y/n): ";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');
    return 0;
}