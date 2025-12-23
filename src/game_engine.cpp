#include "game_engine.h"
#include "menu_system.h"
#include "utils.h"
#include <iostream>

GameEngine::GameEngine() : running_(false) {}

GameEngine::~GameEngine() {
    shutdown();
}

void GameEngine::initialize() {
    running_ = true;
}

void GameEngine::registerGame(std::unique_ptr<GameBase> game) {
    games_.push_back(std::move(game));
}

void GameEngine::run() {
    MenuSystem menu;
    
    while (running_) {
        menu.showWelcome();
        menu.displayMainMenu();
        
        int choice = Utils::getIntInput("\nEnter your choice: ", 0, 3);
        
        switch (choice) {
            case 1: {
                // Browse all games
                int gameIndex = menu.selectGame(games_);
                if (gameIndex >= 0 && gameIndex < static_cast<int>(games_.size())) {
                    Utils::clearScreen();
                    try {
                        games_[gameIndex]->initialize();
                        games_[gameIndex]->run();
                        games_[gameIndex]->cleanup();
                    } catch (const std::exception& e) {
                        std::cerr << "Error running game: " << e.what() << std::endl;
                    }
                    Utils::pauseScreen();
                }
                break;
            }
            case 2:
                // Browse by category
                menu.displayGameCategories(games_);
                Utils::pauseScreen();
                break;
            case 3:
                // About
                menu.showAbout();
                break;
            case 0:
                // Exit
                running_ = false;
                break;
        }
    }
}

void GameEngine::shutdown() {
    games_.clear();
}
