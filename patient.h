#ifndef PATIENT_H
#define PATIENT_H

#include <string>

struct Patient {
    int id;
    std::string name;
    int age;
    std::string gender;
    std::string disease;
};

void patientMenu();
void addPatient();
void viewPatients();
void updatePatient();
void deletePatient();

#endif

