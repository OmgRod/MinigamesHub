#ifndef MAGIC_SQUARE_H
#define MAGIC_SQUARE_H

#include "game_base.h"

class MagicSquare : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "MagicSquare"; }
    std::string getDescription() const override { return "Build magic square puzzles"; }
    std::string getCategory() const override { return "Logic & Number Games"; }
};

#endif // MAGIC_SQUARE_H
