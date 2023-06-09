#include <iostream>
#include <string>
#include <cctype>


/*
    Program to verify a safe password:

    At least 8 characters long
    Contains at least one uppercase letter
    Contains at least one lowercase letter
    Contains at least one digit
    Contains at least one special character (e.g., @, #, $)


    This is purely academic exercise of enum class and cctype header.
*/


enum class PasswordStatus{
    invalid_lenght,
    missing_uppercase,
    missing_lowercase,
    missing_digit,
    missing_special_character,
    ok
};


bool isValidLenght(const std::string& st){
    return st.length() >= 8;
}

bool hasUppercase(const std::string& st){
    for (auto &&i : st){
        if (isupper(i)){
            return true;
        }
    }

    return false;
}

bool hasLowercase(const std::string& st){
    for (auto &&i : st){
        if (islower(i)){
            return true;
        }
    }

    return false;
}

bool hasDigit(const std::string& st){
    for (auto &&i : st){
        if (isdigit(i)){
            return true;
        }
    }

    return false;
}

bool hasSpecialCharacter(const std::string& st){
    for (auto &&i : st){
        if (!isalnum(i)){
            return true;
        }
    }

    return false;
}


PasswordStatus getPasswordStatus(const std::string& st){
    PasswordStatus status {};

    if (!isValidLenght(st)){
        status = PasswordStatus::invalid_lenght;
    }
    else if (!hasLowercase(st)){
        status = PasswordStatus::missing_lowercase;
    }
    else if (!hasUppercase(st)){
        status = PasswordStatus::missing_uppercase;
    }
    else if (!hasDigit(st)){
        status = PasswordStatus::missing_digit;
    }
    else if (!hasSpecialCharacter(st)){
        status = PasswordStatus::missing_special_character;
    }
    else {
        status = PasswordStatus::ok;
    }

    return status;
}

std::string passwordStatusToString(PasswordStatus pw){
    switch (pw)
    {
        case PasswordStatus::invalid_lenght:
            return "Password needs to be 8 chars long";
        case PasswordStatus::missing_digit:
            return "Password must contain at least 1 digit";
        case PasswordStatus::missing_lowercase:
            return "Password must contain at least 1 lowercase char";
        case PasswordStatus::missing_uppercase:
            return "Password must contain at least 1 uppercase char";
        case PasswordStatus::missing_special_character:
            return "Password must contain at least 1 special char";
        case PasswordStatus::ok:
            return "Password ok!";
        default: return "Unknown error";
    }
}


bool validatePassword(const std::string pw){
    PasswordStatus pwStatus = getPasswordStatus(pw);
    std::cout << passwordStatusToString(pwStatus) << "\n";
    return pwStatus == PasswordStatus::ok;
}


int main(){

    std::string inputString {};
    bool passwordAccepted {false};

    std::cout << "Welcome to reverse string program" << "\n\n";
    while (!passwordAccepted){

        std::cout << "Give a password to verify: ";

        std::cin >> inputString;
        passwordAccepted = validatePassword(inputString);

    }

    return 0;
}