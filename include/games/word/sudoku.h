#ifndef SUDOKU_H
#define SUDOKU_H

#include "game_base.h"

class Sudoku : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "Sudoku"; }
    std::string getDescription() const override { return "Classic number puzzle - fill 9x9 grid"; }
    std::string getCategory() const override { return "Word & Language Games"; }
};

#endif // SUDOKU_H
