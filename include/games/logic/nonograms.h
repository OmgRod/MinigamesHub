#ifndef NONOGRAMS_H
#define NONOGRAMS_H

#include "game_base.h"

class Nonograms : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "Nonograms"; }
    std::string getDescription() const override { return "Reveal pictures using number clues"; }
    std::string getCategory() const override { return "Logic & Number Games"; }
};

#endif // NONOGRAMS_H
