#ifndef STAFF_H
#define STAFF_H

#include <string>

struct Staff {
    int id;
    char name[50];
    char role[30];
    char contact[15];
};

void addStaff();
void viewAllStaff();
void searchStaff(int id);
void deleteStaff(int id);

#endif

