#ifndef PATTERN_SPEED_H
#define PATTERN_SPEED_H

#include "game_base.h"

class PatternSpeed : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "PatternSpeed"; }
    std::string getDescription() const override { return "Pattern recognition speed test"; }
    std::string getCategory() const override { return "Quick/Reflex Games"; }
};

#endif // PATTERN_SPEED_H
