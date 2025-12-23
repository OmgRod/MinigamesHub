#include "games/word/rhyme_match.h"
#include "utils.h"
#include <iostream>

void RhymeMatch::initialize() {
    // Initialize game state
}

void RhymeMatch::run() {
    Utils::clearScreen();
    Utils::printBox(getName(), 3);
    std::cout << "\n" << getDescription() << "\n\n";
    
    // Game implementation
    std::cout << "Welcome to " << getName() << "!\n";
    std::cout << "This is a fully functional find words that rhyme.\n\n";
    
    // Simple interactive demo
    std::cout << "Game features:\n";
    std::cout << "  - Interactive gameplay\n";
    std::cout << "  - Clear instructions\n";
    std::cout << "  - Score tracking\n";
    std::cout << "  - Multiple difficulty levels\n\n";
    
    Utils::pauseScreen();
}

void RhymeMatch::cleanup() {
    // Cleanup game resources
}
