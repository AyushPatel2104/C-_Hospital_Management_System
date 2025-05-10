#include <iostream>
#include <fstream>
#include <cstring>
#include "staff.h"
using namespace std;

void addStaff() {
    Staff s;
    cout << "\nEnter Staff ID: ";
    cin >> s.id;
    cin.ignore();
    cout << "Enter Name: ";
    cin.getline(s.name, 50);
    cout << "Enter Role (e.g., Nurse, Technician): ";
    cin.getline(s.role, 30);
    cout << "Enter Contact Number: ";
    cin.getline(s.contact, 15);

    ofstream file("staff.dat", ios::binary | ios::app);
    file.write(reinterpret_cast<char*>(&s), sizeof(s));
    file.close();

    cout << "\n? Staff added successfully.\n";
}

void viewAllStaff() {
    Staff s;
    ifstream file("staff.dat", ios::binary);
    cout << "\n?? Staff List:\n";

    while (file.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        cout << "ID: " << s.id << "\n"
             << "Name: " << s.name << "\n"
             << "Role: " << s.role << "\n"
             << "Contact: " << s.contact << "\n"
             << "-----------------------------\n";
    }

    file.close();
}

void searchStaff(int id) {
    Staff s;
    bool found = false;
    ifstream file("staff.dat", ios::binary);

    while (file.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        if (s.id == id) {
            cout << "\n?? Staff Found:\n"
                 << "ID: " << s.id << "\n"
                 << "Name: " << s.name << "\n"
                 << "Role: " << s.role << "\n"
                 << "Contact: " << s.contact << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\n? Staff with ID " << id << " not found.\n";
    }

    file.close();
}

void deleteStaff(int id) {
    Staff s;
    ifstream infile("staff.dat", ios::binary);
    ofstream outfile("temp.dat", ios::binary);
    bool deleted = false;

    while (infile.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        if (s.id != id) {
            outfile.write(reinterpret_cast<char*>(&s), sizeof(s));
        } else {
            deleted = true;
        }
    }

    infile.close();
    outfile.close();
    remove("staff.dat");
    rename("temp.dat", "staff.dat");

    if (deleted) {
        cout << "\n? Staff with ID " << id << " deleted successfully.\n";
    } else {
        cout << "\n? Staff not found.\n";
    }
}

