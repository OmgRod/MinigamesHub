#ifndef SCRABBLE_H
#define SCRABBLE_H

#include "game_base.h"

class Scrabble : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "Scrabble"; }
    std::string getDescription() const override { return "Build words from letter tiles"; }
    std::string getCategory() const override { return "Word & Language Games"; }
};

#endif // SCRABBLE_H
