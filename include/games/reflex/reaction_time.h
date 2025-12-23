#ifndef REACTION_TIME_H
#define REACTION_TIME_H

#include "game_base.h"

class ReactionTime : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "ReactionTime"; }
    std::string getDescription() const override { return "Test your reaction speed"; }
    std::string getCategory() const override { return "Quick/Reflex Games"; }
};

#endif // REACTION_TIME_H
