#ifndef MAZE_SOLVER_H
#define MAZE_SOLVER_H

#include "game_base.h"

class MazeSolver : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "MazeSolver"; }
    std::string getDescription() const override { return "Solve the maze"; }
    std::string getCategory() const override { return "Spatial/Visual Puzzles"; }
};

#endif // MAZE_SOLVER_H
