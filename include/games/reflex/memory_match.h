#ifndef MEMORY_MATCH_H
#define MEMORY_MATCH_H

#include "game_base.h"

class MemoryMatch : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "MemoryMatch"; }
    std::string getDescription() const override { return "Concentration card game"; }
    std::string getCategory() const override { return "Quick/Reflex Games"; }
};

#endif // MEMORY_MATCH_H
