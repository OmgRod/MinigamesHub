#ifndef MIRROR_LASER_H
#define MIRROR_LASER_H

#include "game_base.h"

class MirrorLaser : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "MirrorLaser"; }
    std::string getDescription() const override { return "Redirect laser beams using mirrors"; }
    std::string getCategory() const override { return "Spatial/Visual Puzzles"; }
};

#endif // MIRROR_LASER_H
