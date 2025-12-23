#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "game_base.h"
#include <vector>

class Minesweeper : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "Minesweeper"; }
    std::string getDescription() const override { return "Classic mine detection game"; }
    std::string getCategory() const override { return "Strategy & Thinking Games"; }

private:
    static const int SIZE = 8;
    static const int MINES = 10;
    
    std::vector<std::vector<bool>> mines_;
    std::vector<std::vector<bool>> revealed_;
    std::vector<std::vector<bool>> flagged_;
    int cellsRevealed_;
    bool gameOver_;
    bool won_;
    
    void initializeBoard();
    void displayBoard();
    int countAdjacentMines(int row, int col);
    void revealCell(int row, int col);
    bool checkWin();
};

#endif // MINESWEEPER_H
