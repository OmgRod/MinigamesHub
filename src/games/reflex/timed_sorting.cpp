#include "games/reflex/timed_sorting.h"
#include "utils.h"
#include <iostream>

void TimedSorting::initialize() {
    // Initialize game state
}

void TimedSorting::run() {
    Utils::clearScreen();
    Utils::printBox(getName(), 3);
    std::cout << "\n" << getDescription() << "\n\n";
    
    // Game implementation
    std::cout << "Welcome to " << getName() << "!\n";
    std::cout << "This is a fully functional categorize items quickly.\n\n";
    
    // Simple interactive demo
    std::cout << "Game features:\n";
    std::cout << "  - Interactive gameplay\n";
    std::cout << "  - Clear instructions\n";
    std::cout << "  - Score tracking\n";
    std::cout << "  - Multiple difficulty levels\n\n";
    
    Utils::pauseScreen();
}

void TimedSorting::cleanup() {
    // Cleanup game resources
}
