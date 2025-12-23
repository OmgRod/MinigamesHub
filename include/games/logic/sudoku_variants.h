#ifndef SUDOKU_VARIANTS_H
#define SUDOKU_VARIANTS_H

#include "game_base.h"

class SudokuVariants : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "SudokuVariants"; }
    std::string getDescription() const override { return "Killer sudoku, diagonal sudoku variants"; }
    std::string getCategory() const override { return "Logic & Number Games"; }
};

#endif // SUDOKU_VARIANTS_H
