#include <iostream>
#include <string>

bool isValidCharacter(char ch, const std::string& validChars) {
    return validChars.find(ch) != std::string::npos;
}

bool isValidPart(const std::string& part, const std::string& validChars, int maxLength) {
    if (part.empty() || part.size() > maxLength) {
        return false;
    }
    if (part.front() == '.' || part.back() == '.') {
        return false;
    }
    if (part.find("..") != std::string::npos) {
        return false;
    }
    for (char ch : part) {
        if (!isValidCharacter(ch, validChars)) {
            return false;
        }
    }
    return true;
}

bool isValidEmail(const std::string& email) {
    int atPosition = email.find('@');
    if (atPosition == std::string::npos || atPosition != email.rfind('@')) {
        return false;
    }

    std::string localPart = email.substr(0, atPosition);
    std::string domainPart = email.substr(atPosition + 1);
    const std::string validLocalChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!#$%&'*+-/=?^_`{|}~.";
    const std::string validDomainChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-.";

    return isValidPart(localPart, validLocalChars, 64) && isValidPart(domainPart, validDomainChars, 63);
}

int main() {
    std::string email;
    std::cout << "Введите email адрес: ";
    std::cin >> email;
    if (isValidEmail(email)) {
        std::cout << "Корректный email";
    } else {
        std::cout << "Некорректный email";
    }
}