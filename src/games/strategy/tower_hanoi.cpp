#include "games/strategy/tower_hanoi.h"
#include "utils.h"
#include <iostream>

void TowerHanoi::initialize() {
    towers_.resize(3);
    numDisks_ = 4;
    moves_ = 0;
    
    // Initialize first tower with disks (largest to smallest)
    for (int i = numDisks_; i >= 1; --i) {
        towers_[0].push(i);
    }
}

void TowerHanoi::run() {
    Utils::clearScreen();
    Utils::printBox(getName(), 3);
    std::cout << "\n" << getDescription() << "\n\n";
    
    std::cout << "Move all disks from Tower 1 to Tower 3.\n";
    std::cout << "Rules: Only one disk at a time, larger disk cannot be on smaller disk.\n\n";
    
    while (!isSolved()) {
        displayTowers();
        
        int from = Utils::getIntInput("\nMove from tower (1-3, 0 to quit): ", 0, 3);
        if (from == 0) break;
        
        int to = Utils::getIntInput("Move to tower (1-3): ", 1, 3);
        
        from--; to--;  // Convert to 0-indexed
        
        if (isValidMove(from, to)) {
            moveDisk(from, to);
            moves_++;
            
            if (isSolved()) {
                Utils::clearScreen();
                displayTowers();
                std::cout << "\n🎉 Congratulations! You solved it in " << moves_ << " moves!\n";
                std::cout << "Minimum possible moves: " << ((1 << numDisks_) - 1) << "\n\n";
            }
        } else {
            std::cout << "Invalid move! Try again.\n";
            Utils::pauseScreen();
        }
    }
    
    Utils::pauseScreen();
}

void TowerHanoi::cleanup() {
    towers_.clear();
}

void TowerHanoi::displayTowers() {
    Utils::clearScreen();
    std::cout << "\nTower of Hanoi - Moves: " << moves_ << "\n\n";
    
    // Find max height
    int maxHeight = 0;
    for (const auto& tower : towers_) {
        maxHeight = std::max(maxHeight, static_cast<int>(tower.size()));
    }
    
    // Display towers from top to bottom
    for (int level = maxHeight - 1; level >= 0; --level) {
        for (size_t t = 0; t < 3; ++t) {
            std::cout << "   ";
            
            std::vector<int> disks;
            std::stack<int> temp = towers_[t];
            while (!temp.empty()) {
                disks.push_back(temp.top());
                temp.pop();
            }
            
            if (level < static_cast<int>(disks.size())) {
                int disk = disks[disks.size() - 1 - level];
                std::string diskStr(disk * 2, '=');
                std::cout << "[" << diskStr << "]";
            } else {
                std::cout << " | ";
            }
            std::cout << "   ";
        }
        std::cout << "\n";
    }
    
    std::cout << "  -------   -------   -------\n";
    std::cout << "  Tower 1   Tower 2   Tower 3\n";
}

bool TowerHanoi::isValidMove(int from, int to) {
    if (from < 0 || from >= 3 || to < 0 || to >= 3) return false;
    if (from == to) return false;
    if (towers_[from].empty()) return false;
    if (towers_[to].empty()) return true;
    return towers_[from].top() < towers_[to].top();
}

void TowerHanoi::moveDisk(int from, int to) {
    int disk = towers_[from].top();
    towers_[from].pop();
    towers_[to].push(disk);
}

bool TowerHanoi::isSolved() {
    return towers_[2].size() == static_cast<size_t>(numDisks_);
}
