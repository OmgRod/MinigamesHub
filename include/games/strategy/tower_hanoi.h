#ifndef TOWER_HANOI_H
#define TOWER_HANOI_H

#include "game_base.h"
#include <vector>
#include <stack>

class TowerHanoi : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "Tower of Hanoi"; }
    std::string getDescription() const override { return "Classic tower puzzle"; }
    std::string getCategory() const override { return "Strategy & Thinking Games"; }

private:
    std::vector<std::stack<int>> towers_;
    int numDisks_;
    int moves_;
    
    void displayTowers();
    bool isValidMove(int from, int to);
    void moveDisk(int from, int to);
    bool isSolved();
};

#endif // TOWER_HANOI_H
