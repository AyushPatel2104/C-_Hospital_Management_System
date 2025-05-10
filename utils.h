#ifndef UTILS_H
#define UTILS_H

#include <string>

// Password system
bool loginSystem();
void changePassword();

// Encryption (basic XOR-based)
std::string encrypt(const std::string &data, char key = '#');
std::string decrypt(const std::string &data, char key = '#');

// Utilities
void loadingBar();
void clearScreen();

#endif

