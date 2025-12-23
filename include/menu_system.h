#ifndef MENU_SYSTEM_H
#define MENU_SYSTEM_H

#include <string>
#include <vector>
#include <memory>
#include "game_base.h"

class MenuSystem {
public:
    MenuSystem();
    
    void displayMainMenu();
    int selectGame(const std::vector<std::unique_ptr<GameBase>>& games);
    void displayGameCategories(const std::vector<std::unique_ptr<GameBase>>& games);
    
    void showWelcome();
    void showAbout();
    
private:
    void displayGameList(const std::vector<GameBase*>& games);
};

#endif // MENU_SYSTEM_H
