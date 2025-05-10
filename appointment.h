#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>

struct Appointment {
    int appointmentID;
    int patientID;
    std::string date;
    std::string time;
    std::string doctor;
};

void appointmentMenu();
void scheduleAppointment();
void viewAppointments();
void cancelAppointment();

#endif

