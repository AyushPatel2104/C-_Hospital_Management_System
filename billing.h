#ifndef BILLING_H
#define BILLING_H

#include <string>

struct Bill {
    int billID;
    int patientID;
    std::string treatment;
    double amount;
    std::string date;
};

void billingMenu();
void generateBill();
void viewAllBills();
void searchBillByPatientID();

#endif

