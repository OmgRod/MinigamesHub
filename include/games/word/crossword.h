#ifndef CROSSWORD_H
#define CROSSWORD_H

#include "game_base.h"

class Crossword : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "Crossword"; }
    std::string getDescription() const override { return "Fill in the crossword puzzle"; }
    std::string getCategory() const override { return "Word & Language Games"; }
};

#endif // CROSSWORD_H
