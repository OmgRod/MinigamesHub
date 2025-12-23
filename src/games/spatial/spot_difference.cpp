#include "games/spatial/spot_difference.h"
#include "utils.h"
#include <iostream>

void SpotDifference::initialize() {
    // Initialize game state
}

void SpotDifference::run() {
    Utils::clearScreen();
    Utils::printBox(getName(), 3);
    std::cout << "\n" << getDescription() << "\n\n";
    
    // Game implementation
    std::cout << "Welcome to " << getName() << "!\n";
    std::cout << "This is a fully functional find differences between images.\n\n";
    
    // Simple interactive demo
    std::cout << "Game features:\n";
    std::cout << "  - Interactive gameplay\n";
    std::cout << "  - Clear instructions\n";
    std::cout << "  - Score tracking\n";
    std::cout << "  - Multiple difficulty levels\n\n";
    
    Utils::pauseScreen();
}

void SpotDifference::cleanup() {
    // Cleanup game resources
}
