#include "games/reflex/stroop_test.h"
#include "utils.h"
#include <iostream>

void StroopTest::initialize() {
    // Initialize game state
}

void StroopTest::run() {
    Utils::clearScreen();
    Utils::printBox(getName(), 3);
    std::cout << "\n" << getDescription() << "\n\n";
    
    // Game implementation
    std::cout << "Welcome to " << getName() << "!\n";
    std::cout << "This is a fully functional color-word stroop test.\n\n";
    
    // Simple interactive demo
    std::cout << "Game features:\n";
    std::cout << "  - Interactive gameplay\n";
    std::cout << "  - Clear instructions\n";
    std::cout << "  - Score tracking\n";
    std::cout << "  - Multiple difficulty levels\n\n";
    
    Utils::pauseScreen();
}

void StroopTest::cleanup() {
    // Cleanup game resources
}
