#ifndef SIMON_SAYS_H
#define SIMON_SAYS_H

#include "game_base.h"

class SimonSays : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "SimonSays"; }
    std::string getDescription() const override { return "Simon says pattern memory"; }
    std::string getCategory() const override { return "Quick/Reflex Games"; }
};

#endif // SIMON_SAYS_H
