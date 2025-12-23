#ifndef WORD_LADDER_H
#define WORD_LADDER_H

#include "game_base.h"

class WordLadder : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "WordLadder"; }
    std::string getDescription() const override { return "Change one letter at a time to reach target"; }
    std::string getCategory() const override { return "Word & Language Games"; }
};

#endif // WORD_LADDER_H
