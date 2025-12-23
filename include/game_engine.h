#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <memory>
#include <vector>
#include "game_base.h"

class GameEngine {
public:
    GameEngine();
    ~GameEngine();
    
    void initialize();
    void run();
    void shutdown();
    
    void registerGame(std::unique_ptr<GameBase> game);
    
private:
    std::vector<std::unique_ptr<GameBase>> games_;
    bool running_;
};

#endif // GAME_ENGINE_H
