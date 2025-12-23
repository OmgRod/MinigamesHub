#ifndef SHAPE_ROTATION_H
#define SHAPE_ROTATION_H

#include "game_base.h"

class ShapeRotation : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "ShapeRotation"; }
    std::string getDescription() const override { return "Rotate shapes to match"; }
    std::string getCategory() const override { return "Spatial/Visual Puzzles"; }
};

#endif // SHAPE_ROTATION_H
