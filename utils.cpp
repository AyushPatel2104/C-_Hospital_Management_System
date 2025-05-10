#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include "utils.h"

using namespace std;

bool loginSystem() {
    string input, stored;
    ifstream fin("password.txt");
    if (!fin) {
        cout << "\nNo password found! Setting default password: admin123\n";
        ofstream fout("password.txt");
        fout << encrypt("admin123");
        fout.close();
        return true;
    }

    getline(fin, stored);
    fin.close();
    stored = decrypt(stored);

    cout << "?? Enter password: ";
    cin >> input;

    if (input == stored) {
        cout << "? Access Granted\n";
        return true;
    } else {
        cout << "? Wrong Password!\n";
        return false;
    }
}

void changePassword() {
    string newPass;
    cout << "?? Enter New Password: ";
    cin >> newPass;

    ofstream fout("password.txt");
    fout << encrypt(newPass);
    fout.close();

    cout << "? Password Changed Successfully!\n";
}

string encrypt(const string &data, char key) {
    string enc = data;
    for (char &c : enc) {
        c ^= key;
    }
    return enc;
}

string decrypt(const string &data, char key) {
    return encrypt(data, key); // XOR again to decrypt
}

void loadingBar() {
    cout << "\nLoading ";
    for (int i = 0; i < 15; i++) {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << "\n";
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

