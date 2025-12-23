#ifndef SYMMETRY_H
#define SYMMETRY_H

#include "game_base.h"

class SymmetryPuzzle : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "SymmetryPuzzle"; }
    std::string getDescription() const override { return "Reflect shapes correctly"; }
    std::string getCategory() const override { return "Spatial/Visual Puzzles"; }
};

#endif // SYMMETRY_H
