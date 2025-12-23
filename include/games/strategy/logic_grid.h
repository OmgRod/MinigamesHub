#ifndef LOGIC_GRID_H
#define LOGIC_GRID_H

#include "game_base.h"

class LogicGrid : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "LogicGrid"; }
    std::string getDescription() const override { return "Logic grid puzzles"; }
    std::string getCategory() const override { return "Strategy & Thinking Games"; }
};

#endif // LOGIC_GRID_H
