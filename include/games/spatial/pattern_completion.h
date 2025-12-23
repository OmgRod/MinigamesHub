#ifndef PATTERN_COMPLETION_H
#define PATTERN_COMPLETION_H

#include "game_base.h"

class PatternCompletion : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "PatternCompletion"; }
    std::string getDescription() const override { return "Choose the missing tile"; }
    std::string getCategory() const override { return "Spatial/Visual Puzzles"; }
};

#endif // PATTERN_COMPLETION_H
