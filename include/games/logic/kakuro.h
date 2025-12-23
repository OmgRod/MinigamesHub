#ifndef KAKURO_H
#define KAKURO_H

#include "game_base.h"

class Kakuro : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "Kakuro"; }
    std::string getDescription() const override { return "Crossword meets math"; }
    std::string getCategory() const override { return "Logic & Number Games"; }
};

#endif // KAKURO_H
