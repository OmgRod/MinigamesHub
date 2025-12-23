#ifndef STROOP_TEST_H
#define STROOP_TEST_H

#include "game_base.h"

class StroopTest : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "StroopTest"; }
    std::string getDescription() const override { return "Color-word Stroop test"; }
    std::string getCategory() const override { return "Quick/Reflex Games"; }
};

#endif // STROOP_TEST_H
