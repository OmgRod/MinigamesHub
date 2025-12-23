#include "menu_system.h"
#include "utils.h"
#include <iostream>
#include <iomanip>
#include <map>

MenuSystem::MenuSystem() {}

void MenuSystem::showWelcome() {
    Utils::clearScreen();
    Utils::printSeparator('=', 80);
    Utils::printCentered("MINIGAMES HUB", 80);
    Utils::printCentered("50+ Brain Games & Puzzles", 80);
    Utils::printSeparator('=', 80);
    std::cout << "\n";
}

void MenuSystem::showAbout() {
    Utils::clearScreen();
    Utils::printBox("ABOUT MINIGAMES HUB", 3);
    std::cout << "\nA comprehensive collection of 50+ brain games and puzzles.\n";
    std::cout << "\nCategories:\n";
    std::cout << "  - Word & Language Games (14)\n";
    std::cout << "  - Logic & Number Games (8)\n";
    std::cout << "  - Spatial/Visual Puzzles (11)\n";
    std::cout << "  - Strategy & Thinking Games (9)\n";
    std::cout << "  - Quick/Reflex Games (6)\n";
    std::cout << "  - Experimental Games (2)\n";
    std::cout << "\nBuilt with C++17 for maximum performance and portability.\n";
    Utils::pauseScreen();
}

void MenuSystem::displayMainMenu() {
    std::cout << "\nMAIN MENU:\n";
    std::cout << "  1. Browse All Games\n";
    std::cout << "  2. Browse by Category\n";
    std::cout << "  3. About\n";
    std::cout << "  0. Exit\n";
}

void MenuSystem::displayGameCategories(const std::vector<std::unique_ptr<GameBase>>& games) {
    std::map<std::string, std::vector<GameBase*>> categories;
    
    for (const auto& game : games) {
        categories[game->getCategory()].push_back(game.get());
    }
    
    Utils::clearScreen();
    std::cout << "GAME CATEGORIES:\n\n";
    
    int index = 1;
    for (const auto& pair : categories) {
        std::cout << "  " << index++ << ". " << pair.first 
                  << " (" << pair.second.size() << " games)\n";
    }
    std::cout << "  0. Back to Main Menu\n";
}

void MenuSystem::displayGameList(const std::vector<GameBase*>& games) {
    std::cout << "\n";
    for (size_t i = 0; i < games.size(); ++i) {
        std::cout << "  " << std::setw(2) << (i + 1) << ". " 
                  << games[i]->getName() << "\n";
        std::cout << "      " << games[i]->getDescription() << "\n";
    }
    std::cout << "   0. Back\n";
}

int MenuSystem::selectGame(const std::vector<std::unique_ptr<GameBase>>& games) {
    Utils::clearScreen();
    std::cout << "ALL GAMES (" << games.size() << " total):\n";
    
    std::vector<GameBase*> gameList;
    for (const auto& game : games) {
        gameList.push_back(game.get());
    }
    
    displayGameList(gameList);
    
    int choice = Utils::getIntInput("\nSelect a game (0 to go back): ", 0, static_cast<int>(games.size()));
    return choice - 1;
}
