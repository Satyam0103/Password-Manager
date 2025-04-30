#include "utils.h"
#include <cstdlib>
#include <ctime>
#include <cctype>

bool isStrongPassword(const std::string &password) {
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    for (char ch : password) {
        if (isupper(ch)) hasUpper = true;
        else if (islower(ch)) hasLower = true;
        else if (isdigit(ch)) hasDigit = true;
        else hasSpecial = true;
    }
    return password.length() >= 8 && hasUpper && hasLower && hasDigit && hasSpecial;
}

int generateOTP() {   // ✅ make sure this returns int, not string
    srand(time(0));
    return rand() % 900000 + 100000; // 6-digit OTP
}
