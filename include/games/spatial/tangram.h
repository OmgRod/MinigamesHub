#ifndef TANGRAM_H
#define TANGRAM_H

#include "game_base.h"

class Tangram : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "Tangram"; }
    std::string getDescription() const override { return "Make shapes from shapes"; }
    std::string getCategory() const override { return "Spatial/Visual Puzzles"; }
};

#endif // TANGRAM_H
