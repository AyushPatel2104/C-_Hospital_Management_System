#include "patient.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<Patient> loadPatients() {
    vector<Patient> patients;
    ifstream file("patients.dat", ios::binary);
    Patient p;
    while(file.read((char*)&p, sizeof(Patient))) {
        patients.push_back(p);
    }
    file.close();
    return patients;
}

void savePatients(const vector<Patient>& patients) {
    ofstream file("patients.dat", ios::binary | ios::trunc);
    for(const auto& p : patients) {
        file.write((char*)&p, sizeof(Patient));
    }
    file.close();
}

void addPatient() {
    Patient p;
    cout << "Enter Patient ID: "; cin >> p.id;
    cin.ignore();
    cout << "Name: "; getline(cin, p.name);
    cout << "Age: "; cin >> p.age;
    cin.ignore();
    cout << "Gender: "; getline(cin, p.gender);
    cout << "Disease: "; getline(cin, p.disease);

    ofstream file("patients.dat", ios::binary | ios::app);
    file.write((char*)&p, sizeof(Patient));
    file.close();

    cout << "Patient added successfully!\n";
}

void viewPatients() {
    auto patients = loadPatients();
    cout << "\n-- All Patients --\n";
    for(const auto& p : patients) {
        cout << "ID: " << p.id << ", Name: " << p.name << ", Age: " << p.age
             << ", Gender: " << p.gender << ", Disease: " << p.disease << "\n";
    }
}

void updatePatient() {
    int id;
    cout << "Enter Patient ID to update: ";
    cin >> id;
    auto patients = loadPatients();
    bool found = false;

    for(auto& p : patients) {
        if(p.id == id) {
            cin.ignore();
            cout << "New Name: "; getline(cin, p.name);
            cout << "New Age: "; cin >> p.age;
            cin.ignore();
            cout << "New Gender: "; getline(cin, p.gender);
            cout << "New Disease: "; getline(cin, p.disease);
            found = true;
            break;
        }
    }

    if(found) {
        savePatients(patients);
        cout << "Patient updated successfully!\n";
    } else {
        cout << "Patient not found.\n";
    }
}

void deletePatient() {
    int id;
    cout << "Enter Patient ID to delete: ";
    cin >> id;
    auto patients = loadPatients();
    bool found = false;

    auto it = patients.begin();
    while(it != patients.end()) {
        if(it->id == id) {
            it = patients.erase(it);
            found = true;
        } else {
            ++it;
        }
    }

    if(found) {
        savePatients(patients);
        cout << "Patient deleted successfully!\n";
    } else {
        cout << "Patient not found.\n";
    }
}

void patientMenu() {
    int choice;
    do {
        cout << "\n--- Patient Menu ---\n";
        cout << "1. Add Patient\n";
        cout << "2. View Patients\n";
        cout << "3. Update Patient\n";
        cout << "4. Delete Patient\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: updatePatient(); break;
            case 4: deletePatient(); break;
            case 5: break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 5);
}

