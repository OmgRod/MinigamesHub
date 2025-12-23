#ifndef DOTS_BOXES_H
#define DOTS_BOXES_H

#include "game_base.h"

class DotsBoxes : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "DotsBoxes"; }
    std::string getDescription() const override { return "Classic dots and boxes"; }
    std::string getCategory() const override { return "Strategy & Thinking Games"; }
};

#endif // DOTS_BOXES_H
