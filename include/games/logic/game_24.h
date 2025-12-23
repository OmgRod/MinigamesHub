#ifndef GAME_24_H
#define GAME_24_H

#include "game_base.h"

class Game24 : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "Game24"; }
    std::string getDescription() const override { return "Combine numbers to reach 24"; }
    std::string getCategory() const override { return "Logic & Number Games"; }
};

#endif // GAME_24_H
