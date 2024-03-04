#include <iostream>
#include <vector>
#include <string>
void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "  1 2 3" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
        if (i < 2) {
            std::cout << "  -----" << std::endl;
        }
    }
}
char checkWinner(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return '-';
}
bool isBoardFull(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == '-') {
                return false;
            }
        }
    }
    return true;
}
int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, '-'));
    char currentPlayer = 'X';
    char winner = '-';
    while (winner == '-' && !isBoardFull(board)) {
        std::cout << std::endl;
        displayBoard(board);
        int row, col;
        std::cout << "Player " << currentPlayer << "'s turn. Enter row and column (1-3): ";
        std::cin >> row >> col;
        row--;
        col--;
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-') {
            board[row][col] = currentPlayer;
            winner = checkWinner(board);
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            std::cout << "Invalid move! Please try again." << std::endl;
        }
    }
    std::cout << std::endl;
    displayBoard(board);
    if (winner != '-') {
        std::cout << "Player " << winner << " wins!" << std::endl;
    } else {
        std::cout << "It's a draw!" << std::endl;
    }

    return 0;
}

