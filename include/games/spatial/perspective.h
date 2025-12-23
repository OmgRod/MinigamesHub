#ifndef PERSPECTIVE_H
#define PERSPECTIVE_H

#include "game_base.h"

class PerspectivePuzzle : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "PerspectivePuzzle"; }
    std::string getDescription() const override { return "Illusion-based matching"; }
    std::string getCategory() const override { return "Spatial/Visual Puzzles"; }
};

#endif // PERSPECTIVE_H
