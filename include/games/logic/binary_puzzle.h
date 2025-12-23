#ifndef BINARY_PUZZLE_H
#define BINARY_PUZZLE_H

#include "game_base.h"

class BinaryPuzzle : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "BinaryPuzzle"; }
    std::string getDescription() const override { return "Takuzu binary puzzle"; }
    std::string getCategory() const override { return "Logic & Number Games"; }
};

#endif // BINARY_PUZZLE_H
