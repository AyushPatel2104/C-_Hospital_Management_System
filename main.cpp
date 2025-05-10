#include <iostream>
#include "patient.h"
#include "appointment.h"
#include "billing.h"
#include "utils.h"

using namespace std;

int main() {
    if (!loginSystem()) {
        cout << "Access Denied. Exiting...\n";
        return 0;
    }

    int choice;
    do {
        cout << "\n=== HOSPITAL MANAGEMENT SYSTEM ===\n";
        cout << "1. Manage Patients\n";
        cout << "2. Appointments\n";
        cout << "3. Billing\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                patientMenu();
                break;
            case 2:
                appointmentMenu();
                break;
            case 3:
                billingMenu();
                break;
            case 4:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 4);

    return 0;
}

