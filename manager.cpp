#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "auth.h"
#include "utils.h"
#include "manager.h"

using namespace std;

void storePassword();
void retrievePassword();
void updatePassword();
void masterPasswordAccess();
void checkPasswordStrength();

void showMenu() {
    int choice;
    do {
        cout << "\n===== Password Manager Menu =====" << endl;
        cout << "1. Store Password" << endl;
        cout << "2. Retrieve Password" << endl;
        cout << "3. Update Password" << endl;
        cout << "4. Master Password Access (OTP)" << endl;
        cout << "5. Check Password Strength" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: storePassword(); break;
            case 2: retrievePassword(); break;
            case 3: updatePassword(); break;
            case 4: masterPasswordAccess(); break;
            case 5: checkPasswordStrength(); break;
            case 6: cout << "Exiting Password Manager. Bye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
}

// ✅ Store password function
void storePassword() {
    string account, password;
    cout << "\nEnter account name: ";
    cin >> account;
    cout << "Enter password: ";
    cin >> password;

    if (!isStrongPassword(password)) {
        cout << "❌ Weak password. Try again.\n";
        return;
    }

    ofstream outFile("stored_passwords.txt", ios::app);
    outFile << account << " " << password << endl;
    outFile.close();

    cout << "✅ Password stored successfully.\n";
}

// ✅ Retrieve password function
void retrievePassword() {
    string account, storedAccount, storedPassword;
    bool found = false;

    cout << "\nEnter account name to retrieve password: ";
    cin >> account;

    ifstream inFile("stored_passwords.txt");
    while (inFile >> storedAccount >> storedPassword) {
        if (storedAccount == account) {
            cout << "🔐 Password for " << account << ": " << storedPassword << endl;
            found = true;
            break;
        }
    }
    inFile.close();

    if (!found) {
        cout << "❌ Account not found.\n";
    }
}

// ✅ Update password function
void updatePassword() {
    string account, newPassword, storedAccount, storedPassword;
    bool updated = false;

    cout << "\nEnter account name to update password: ";
    cin >> account;
    cout << "Enter new password: ";
    cin >> newPassword;

    if (!isStrongPassword(newPassword)) {
        cout << "❌ Weak password. Try again.\n";
        return;
    }

    ifstream inFile("stored_passwords.txt");
    ofstream tempFile("temp.txt");

    while (inFile >> storedAccount >> storedPassword) {
        if (storedAccount == account) {
            tempFile << storedAccount << " " << newPassword << endl;
            updated = true;
        } else {
            tempFile << storedAccount << " " << storedPassword << endl;
        }
    }

    inFile.close();
    tempFile.close();

    remove("stored_passwords.txt");
    rename("temp.txt", "stored_passwords.txt");

    if (updated)
        cout << "✅ Password updated successfully.\n";
    else
        cout << "❌ Account not found.\n";
}

// ✅ Master password with OTP
void masterPasswordAccess() {
    string masterPassword;
    cout << "\nEnter your master password: ";
    cin >> masterPassword;

    int otp = generateOTP();  // generateOTP() returns int
    cout << "OTP sent: " << otp << endl;  // Simulate OTP send

    int enteredOtp;
    cout << "Enter OTP: ";
    cin >> enteredOtp;

    if (enteredOtp == otp) {
        cout << "✅ Master access granted! Secret password is: " << masterPassword << endl;
    } else {
        cout << "❌ Incorrect OTP.\n";
    }
}

// ✅ Check password strength
void checkPasswordStrength() {
    string password;
    cout << "\nEnter password to check strength: ";
    cin >> password;

    if (isStrongPassword(password)) {
        cout << "✅ Strong password.\n";
    } else {
        cout << "❌ Weak password. Use mix of upper, lower, digits, and symbols.\n";
    }
}
int otp = generateOTP();  

