#ifndef RULE_DISCOVERY_H
#define RULE_DISCOVERY_H

#include "game_base.h"

class RuleDiscovery : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "RuleDiscovery"; }
    std::string getDescription() const override { return "Guess the hidden rule"; }
    std::string getCategory() const override { return "Experimental Games"; }
};

#endif // RULE_DISCOVERY_H
