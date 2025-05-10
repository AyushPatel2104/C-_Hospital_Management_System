#include "appointment.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<Appointment> loadAppointments() {
    vector<Appointment> appts;
    ifstream file("appointments.dat", ios::binary);
    Appointment a;
    while(file.read((char*)&a, sizeof(Appointment))) {
        appts.push_back(a);
    }
    file.close();
    return appts;
}

void saveAppointments(const vector<Appointment>& appts) {
    ofstream file("appointments.dat", ios::binary | ios::trunc);
    for(const auto& a : appts) {
        file.write((char*)&a, sizeof(Appointment));
    }
    file.close();
}

void scheduleAppointment() {
    Appointment a;
    cout << "Enter Appointment ID: "; cin >> a.appointmentID;
    cout << "Enter Patient ID: "; cin >> a.patientID;
    cin.ignore();
    cout << "Date (DD/MM/YYYY): "; getline(cin, a.date);
    cout << "Time (HH:MM): "; getline(cin, a.time);
    cout << "Doctor's Name: "; getline(cin, a.doctor);

    ofstream file("appointments.dat", ios::binary | ios::app);
    file.write((char*)&a, sizeof(Appointment));
    file.close();

    cout << "Appointment scheduled successfully!\n";
}

void viewAppointments() {
    auto appts = loadAppointments();
    cout << "\n-- All Appointments --\n";
    for(const auto& a : appts) {
        cout << "Appointment ID: " << a.appointmentID
             << ", Patient ID: " << a.patientID
             << ", Date: " << a.date
             << ", Time: " << a.time
             << ", Doctor: " << a.doctor << "\n";
    }
}

void cancelAppointment() {
    int id;
    cout << "Enter Appointment ID to cancel: ";
    cin >> id;
    auto appts = loadAppointments();
    bool found = false;

    auto it = appts.begin();
    while(it != appts.end()) {
        if(it->appointmentID == id) {
            it = appts.erase(it);
            found = true;
        } else {
            ++it;
        }
    }

    if(found) {
        saveAppointments(appts);
        cout << "Appointment cancelled.\n";
    } else {
        cout << "Appointment not found.\n";
    }
}

void appointmentMenu() {
    int choice;
    do {
        cout << "\n--- Appointment Menu ---\n";
        cout << "1. Schedule Appointment\n";
        cout << "2. View Appointments\n";
        cout << "3. Cancel Appointment\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: scheduleAppointment(); break;
            case 2: viewAppointments(); break;
            case 3: cancelAppointment(); break;
            case 4: break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 4);
}

