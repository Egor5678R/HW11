#include <iostream>
#include <string>

bool validNumber(const std::string& number) {
    if (number.size() > 1 && number[0] == '0') {
        return false;
    }
    for (char c : number) {
        if (c < '0' || c > '9') {
            return false;
        }
    }
    int num = std::stoi(number);
    return num >= 0 && num <= 255;
}

bool validateIP(const std::string& ip) {
    int count = 0;
    std::string number;
    for (char c : ip) {
        if (c == '.') {
            count++;
            if (count > 3 || number.empty() || !validNumber(number)) {
                return false;
            }
            number.clear();
        } else if (c >= '0' && c <= '9') {
            number.push_back(c);
        } else {
            return false;
        }
    }
    if (count != 3 || number.empty() || !validNumber(number)) {
        return false;
    }
    return true;
}

int main() {
    std::string ip;
    std::cout << "Введите IP: ";
    std::cin >> ip;
    if (validateIP(ip)) {
        std::cout << "Корректный IP" << std::endl;
    } else {
        std::cout << "Некорректный IP" << std::endl;
    }
}