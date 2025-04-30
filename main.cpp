#include <iostream>
#include "auth.h"
#include "manager.h"

using namespace std;

int main() {
    cout << "====== Welcome to Password Manager ======\n";

    // First, login
    if (!login()) {
        cout << "❌ Login failed. Exiting program.\n";
        return 0;
    }

    // If login successful, show main menu
    showMenu();

    return 0;
}
