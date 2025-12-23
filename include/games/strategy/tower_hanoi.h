#ifndef TOWER_HANOI_H
#define TOWER_HANOI_H

#include "game_base.h"

class TowerHanoi : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "TowerHanoi"; }
    std::string getDescription() const override { return "Tower of Hanoi puzzle"; }
    std::string getCategory() const override { return "Strategy & Thinking Games"; }
};

#endif // TOWER_HANOI_H
