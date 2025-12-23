#ifndef SLIDING_TILE_H
#define SLIDING_TILE_H

#include "game_base.h"

class SlidingTile : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "SlidingTile"; }
    std::string getDescription() const override { return "Classic 15-puzzle"; }
    std::string getCategory() const override { return "Spatial/Visual Puzzles"; }
};

#endif // SLIDING_TILE_H
