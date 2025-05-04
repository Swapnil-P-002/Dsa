#include <iostream>
#include <fstream>
#include <cstring> // for string comparison
using namespace std;

struct Student {
    int roll;
    char name[20];
    char division[10];
    char address[50];
};

// Function to add a student to the file
void addStudent() {
    ofstream out("students.dat", ios::binary | ios::app);
    Student s;
    cout << "\nEnter Roll No: "; cin >> s.roll;
    cout << "Enter Name: "; cin.ignore(); cin.getline(s.name, 20);
    cout << "Enter Division: "; cin.getline(s.division, 10);
    cout << "Enter Address: "; cin.getline(s.address, 50);

    out.write((char*)&s, sizeof(s));
    out.close();
}

// Function to display all students
void displayStudents() {
    ifstream in("students.dat", ios::binary);
    Student s;
    bool found = false;

    while (in.read((char*)&s, sizeof(s))) {
        cout << "\nRoll No: " << s.roll << "\nName: " << s.name << "\nDivision: " << s.division << "\nAddress: " << s.address << endl;
        found = true;
    }

    if (!found) {
        cout << "No student records found.\n";
    }

    in.close();
}

// Function to search and display a specific student by roll number
void displayStudentByRoll(int roll) {
    ifstream in("students.dat", ios::binary);
    Student s;
    bool found = false;

    while (in.read((char*)&s, sizeof(s))) {
        if (s.roll == roll) {
            cout << "\nRoll No: " << s.roll << "\nName: " << s.name << "\nDivision: " << s.division << "\nAddress: " << s.address << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with roll number " << roll << " not found.\n";
    }

    in.close();
}

int main() {
    int choice, roll;

    do {
        cout << "\n1. Add Student\n2. Display All Students\n3. Display Student by Roll Number\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                addStudent(); 
                break;
            case 2: 
                displayStudents(); 
                break;
            case 3: 
                cout << "Enter Roll No to display: "; 
                cin >> roll; 
                displayStudentByRoll(roll); 
                break;
            case 4: 
                cout << "Exiting...\n"; 
                break;
            default: 
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
