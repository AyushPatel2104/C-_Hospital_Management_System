# 🏥 C++ Hospital Management System

<p align="center">
  <img src="https://img.shields.io/badge/C++-OOP-blue?style=flat-square" />
  <img src="https://img.shields.io/github/repo-size/AyushPatel2104/C++_Hospital_Management_System?style=flat-square" />
  <img src="https://img.shields.io/github/last-commit/AyushPatel2104/C++_Hospital_Management_System?style=flat-square" />
  <img src="https://img.shields.io/github/license/AyushPatel2104/C++_Hospital_Management_System?style=flat-square" />
</p>

---

## 📌 About the Project

This **Hospital Management System** is an advanced, modular C++ project featuring patient records, appointment scheduling, billing, staff management, password-protected access, and basic file encryption — designed to mimic real-world hospital workflows.

---

## 🚀 Features

- 👨‍⚕️ **Patient Management**: Add, view, update, delete
- 📅 **Appointment Scheduling**: Book/cancel slots
- 💳 **Billing System**: Create & manage bills
- 👥 **Staff Records**: Manage hospital staff
- 🔐 **Admin Login**: Password protection (with file encryption)
- 📁 **File Handling**: Persistent storage for all data
- 📦 **Modular OOP**: Code organized into reusable components

---

## 🛠️ Tech Stack

| Tech/Tool    | Usage                       |
|--------------|-----------------------------|
| `C++`        | Programming language         |
| `OOP`        | Project design structure     |
| `File I/O`   | Persistent data handling     |
| `XOR Encryption` | Basic password security |

---

## 📁 File Structure

📦 C++_Hospital_Management_System
├── main.cpp
├── patient.cpp / patient.h
├── appointment.cpp / appointment.h
├── billing.cpp / billing.h
├── staff.cpp / staff.h
├── utils.cpp / utils.h
├── Makefile
├── run.sh
└── README.md


---

## 🖥️ How to Compile & Run

### 💻 Using Terminal / Git Bash

```bash
g++ main.cpp patient.cpp appointment.cpp billing.cpp staff.cpp utils.cpp -o hospital
./hospital

🔁 Or use:

./run.sh         # for Linux/Git Bash
make run         # if using the Makefile

🔐 Default Admin Credentials

Username: admin
Password: admin123

📄 License
This project is licensed under the MIT License

👤 Author
Made with ❤️ by Ayush Patel
🌐 GitHub • LinkedIn
