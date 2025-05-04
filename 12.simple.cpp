#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Employee {
    int id;
    char name[30];
    float salary;
};

void addEmployee() {
    ofstream out("employee.dat", ios::app | ios::binary);
    Employee e;

    cout << "\nEnter Employee ID: "; cin >> e.id;
    cout << "Enter Name: "; cin.ignore(); cin.getline(e.name, 30);
    cout << "Enter Salary: "; cin >> e.salary;

    out.write((char*)&e, sizeof(e));
    out.close();
}

void displayEmployee(int id) {
    ifstream in("employee.dat", ios::binary);
    Employee e;

    bool found = false;
    while (in.read((char*)&e, sizeof(e))) {
        if (e.id == id) {
            cout << "\nID: " << e.id << "\nName: " << e.name << "\nSalary: " << e.salary << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Employee not found!" << endl;
    }
    in.close();
}

int main() {
    int choice, id;
    do {
        cout << "\n1. Add Employee\n2. Display Employee\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            addEmployee();
        } else if (choice == 2) {
            cout << "Enter Employee ID to display: ";
            cin >> id;
            displayEmployee(id);
        }
    } while (choice != 3);

    return 0;
}
