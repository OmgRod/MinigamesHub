#ifndef BLOCK_FIT_H
#define BLOCK_FIT_H

#include "game_base.h"

class BlockFit : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "BlockFit"; }
    std::string getDescription() const override { return "Tetris-like turn-based puzzle"; }
    std::string getCategory() const override { return "Spatial/Visual Puzzles"; }
};

#endif // BLOCK_FIT_H
