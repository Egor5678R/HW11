#include <iostream>
#include <string>

std::string encrypt_caesar(const std::string& str, int shift) {
    std::string result = "";
    for(char c : str) {
        if(std::isalpha(c)) {
            char base = (std::islower(c)) ? 'a' : 'A';
            result += (c - base + shift) % 26 + base;
        } else {
            result += c;
        }
    }
    return result;
}

std::string decrypt_caesar(const std::string& str, int shift) {
    return encrypt_caesar(str, 26 - shift); 
}

int main() {
    std::string message = "The quick brown fox jumps over the lazy dog";
    int shift = 5;
    std::string encrypted_message = encrypt_caesar(message, shift);
    std::cout << "Зашифрованное сообщение: " << encrypted_message << std::endl;
    std::string decrypted_message = decrypt_caesar(encrypted_message, shift);
    std::cout << "Разшифроанное сообщение: " << decrypted_message << std::endl;
}
