#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool checkSecurityQuestion() {
    string answer, storedAnswer;
    cout << "Security Question: What is your favorite color? ";
    cin >> answer;

    ifstream file("security.txt");
    if (file.is_open()) {
        getline(file, storedAnswer);
        file.close();
        return answer == storedAnswer;
    }
    return false;
}

bool login() {
    string username, password, fileUser, filePass;
    int attempts = 0;

    while (attempts < 3) {
        cout << "\nEnter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

        ifstream file("credentials.txt");
        bool success = false;

        if (file.is_open()) {
            while (file >> fileUser >> filePass) {
                if (fileUser == username && filePass == password) {
                    success = true;
                    break;
                }
            }
            file.close();
        }

        if (success) {
            cout << "Login successful.\n";
            if (checkSecurityQuestion()) {
                cout << "Security check passed.\n";
                return true;
            } else {
                cout << "Wrong answer to security question.\n";
                return false;
            }
        } else {
            cout << "Invalid login. Try again.\n";
            attempts++;
        }
    }

    cout << "Too many invalid attempts.\n";
    return false;
}
