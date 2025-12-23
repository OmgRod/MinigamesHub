#ifndef CHESS_PUZZLES_H
#define CHESS_PUZZLES_H

#include "game_base.h"

class ChessPuzzles : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "ChessPuzzles"; }
    std::string getDescription() const override { return "Checkmate in X moves"; }
    std::string getCategory() const override { return "Strategy & Thinking Games"; }
};

#endif // CHESS_PUZZLES_H
