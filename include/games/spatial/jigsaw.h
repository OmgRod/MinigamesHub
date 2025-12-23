#ifndef JIGSAW_H
#define JIGSAW_H

#include "game_base.h"

class Jigsaw : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "Jigsaw"; }
    std::string getDescription() const override { return "Complete the jigsaw puzzle"; }
    std::string getCategory() const override { return "Spatial/Visual Puzzles"; }
};

#endif // JIGSAW_H
