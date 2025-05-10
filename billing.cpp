#include "billing.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<Bill> loadBills() {
    vector<Bill> bills;
    ifstream file("bills.dat", ios::binary);
    Bill b;
    while (file.read((char*)&b, sizeof(Bill))) {
        bills.push_back(b);
    }
    file.close();
    return bills;
}

void saveBills(const vector<Bill>& bills) {
    ofstream file("bills.dat", ios::binary | ios::trunc);
    for (const auto& b : bills) {
        file.write((char*)&b, sizeof(Bill));
    }
    file.close();
}

void generateBill() {
    Bill b;
    cout << "Enter Bill ID: "; cin >> b.billID;
    cout << "Enter Patient ID: "; cin >> b.patientID;
    cin.ignore();
    cout << "Enter Treatment Name: "; getline(cin, b.treatment);
    cout << "Enter Amount: "; cin >> b.amount;
    cin.ignore();
    cout << "Enter Date (DD/MM/YYYY): "; getline(cin, b.date);

    ofstream file("bills.dat", ios::binary | ios::app);
    file.write((char*)&b, sizeof(Bill));
    file.close();

    cout << "Bill generated successfully!\n";
}

void viewAllBills() {
    auto bills = loadBills();
    cout << "\n-- All Bills --\n";
    for (const auto& b : bills) {
        cout << "Bill ID: " << b.billID
             << ", Patient ID: " << b.patientID
             << ", Treatment: " << b.treatment
             << ", Amount: " << b.amount
             << ", Date: " << b.date << "\n";
    }
}

void searchBillByPatientID() {
    int id;
    cout << "Enter Patient ID to search bill: ";
    cin >> id;
    auto bills = loadBills();
    bool found = false;
    for (const auto& b : bills) {
        if (b.patientID == id) {
            cout << "Bill ID: " << b.billID
                 << ", Treatment: " << b.treatment
                 << ", Amount: " << b.amount
                 << ", Date: " << b.date << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No bills found for the given Patient ID.\n";
    }
}

void billingMenu() {
    int choice;
    do {
        cout << "\n--- Billing Menu ---\n";
        cout << "1. Generate Bill\n";
        cout << "2. View All Bills\n";
        cout << "3. Search Bill by Patient ID\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: generateBill(); break;
            case 2: viewAllBills(); break;
            case 3: searchBillByPatientID(); break;
            case 4: break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);
}

