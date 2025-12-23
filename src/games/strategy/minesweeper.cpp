#include "games/strategy/minesweeper.h"
#include "utils.h"
#include <iostream>

void Minesweeper::initialize() {
    mines_.assign(SIZE, std::vector<bool>(SIZE, false));
    revealed_.assign(SIZE, std::vector<bool>(SIZE, false));
    flagged_.assign(SIZE, std::vector<bool>(SIZE, false));
    cellsRevealed_ = 0;
    gameOver_ = false;
    won_ = false;
}

void Minesweeper::run() {
    Utils::clearScreen();
    Utils::printBox(getName(), 3);
    std::cout << "\n" << getDescription() << "\n\n";
    
    initializeBoard();
    
    std::cout << "Commands: 'r <row> <col>' to reveal, 'f <row> <col>' to flag\n";
    std::cout << "Rows and columns are 0-" << (SIZE-1) << "\n\n";
    
    while (!gameOver_) {
        displayBoard();
        
        std::string input = Utils::getInput("\nYour move: ");
        auto parts = Utils::split(input, ' ');
        
        if (parts.size() != 3) {
            std::cout << "Invalid input! Use: r <row> <col> or f <row> <col>\n";
            continue;
        }
        
        char cmd = parts[0][0];
        try {
            int row = std::stoi(parts[1]);
            int col = std::stoi(parts[2]);
            
            if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
                std::cout << "Invalid coordinates!\n";
                continue;
            }
            
            if (cmd == 'r') {
                if (!revealed_[row][col]) {
                    revealCell(row, col);
                    if (mines_[row][col]) {
                        gameOver_ = true;
                        std::cout << "\n💥 BOOM! You hit a mine!\n";
                    } else if (checkWin()) {
                        gameOver_ = true;
                        won_ = true;
                        std::cout << "\n🎉 Congratulations! You won!\n";
                    }
                }
            } else if (cmd == 'f') {
                if (!revealed_[row][col]) {
                    flagged_[row][col] = !flagged_[row][col];
                }
            }
        } catch (...) {
            std::cout << "Invalid input!\n";
        }
    }
    
    displayBoard();
    Utils::pauseScreen();
}

void Minesweeper::cleanup() {
    mines_.clear();
    revealed_.clear();
    flagged_.clear();
}

void Minesweeper::initializeBoard() {
    int placedMines = 0;
    while (placedMines < MINES) {
        int row = Utils::randomInt(0, SIZE - 1);
        int col = Utils::randomInt(0, SIZE - 1);
        if (!mines_[row][col]) {
            mines_[row][col] = true;
            placedMines++;
        }
    }
}

void Minesweeper::displayBoard() {
    std::cout << "\n   ";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    
    for (int i = 0; i < SIZE; ++i) {
        std::cout << i << "  ";
        for (int j = 0; j < SIZE; ++j) {
            if (flagged_[i][j]) {
                std::cout << "F ";
            } else if (!revealed_[i][j]) {
                std::cout << "▓ ";
            } else if (mines_[i][j]) {
                std::cout << "* ";
            } else {
                int count = countAdjacentMines(i, j);
                std::cout << (count > 0 ? std::to_string(count) : ".") << " ";
            }
        }
        std::cout << "\n";
    }
}

int Minesweeper::countAdjacentMines(int row, int col) {
    int count = 0;
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            int nr = row + dr;
            int nc = col + dc;
            if (nr >= 0 && nr < SIZE && nc >= 0 && nc < SIZE && mines_[nr][nc]) {
                count++;
            }
        }
    }
    return count;
}

void Minesweeper::revealCell(int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || revealed_[row][col]) {
        return;
    }
    
    revealed_[row][col] = true;
    cellsRevealed_++;
    
    if (countAdjacentMines(row, col) == 0 && !mines_[row][col]) {
        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                revealCell(row + dr, col + dc);
            }
        }
    }
}

bool Minesweeper::checkWin() {
    return cellsRevealed_ == (SIZE * SIZE - MINES);
}
