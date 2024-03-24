#include <iostream>
#include <string>

bool checkWinner(const std::string& line, char player) {
    int count = 0;
    for (char c : line) {
        if (c == player) {
            count++;
        }
    }
    return count == 3;
}

char getWinner(const std::string& row, const std::string& col, const std::string& diag1, const std::string& diag2) {
    if (checkWinner(row, 'X') || checkWinner(col, 'X') || checkWinner(diag1, 'X') || checkWinner(diag2, 'X')) {
        return 'X';
    } 
    else if (checkWinner(row, 'O') || checkWinner(col, 'O') || checkWinner(diag1, 'O') || checkWinner(diag2, 'O')) {
        return 'O';
    }
    return '.';
}

int main() {
    std::string row1, row2, row3;
    std::cin >> row1 >> row2 >> row3;

    if (row1.size() != 3 || row2.size() != 3 || row3.size() != 3) {
        std::cout << "Incorrect" << std::endl;
        return 0;
    }

    std::string col1, col2, col3;
    col1 += row1[0]; 
    col1 += row2[0]; 
    col1 += row3[0];
    col2 += row1[1]; 
    col2 += row2[1]; 
    col2 += row3[1];
    col3 += row1[2]; 
    col3 += row2[2]; 
    col3 += row3[2];

    std::string diag1, diag2;
    diag1 += row1[0]; 
    diag1 += row2[1]; 
    diag1 += row3[2];
    diag2 += row1[2]; 
    diag2 += row2[1]; 
    diag2 += row3[0];

    char winner = getWinner(row1, col1, diag1, diag2);

    if (winner == 'X') {
        std::cout << "Petya won" << std::endl;
    } 
    else if (winner == 'O') {
        std::cout << "Vanya won" << std::endl;
    } else {
        std::cout << "Nobody" << std::endl;
    }
}
