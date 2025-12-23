#ifndef SPOT_DIFFERENCE_H
#define SPOT_DIFFERENCE_H

#include "game_base.h"

class SpotDifference : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "SpotDifference"; }
    std::string getDescription() const override { return "Find differences between images"; }
    std::string getCategory() const override { return "Spatial/Visual Puzzles"; }
};

#endif // SPOT_DIFFERENCE_H
