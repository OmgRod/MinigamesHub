#ifndef AI_JUDGE_H
#define AI_JUDGE_H

#include "game_base.h"

class AIJudge : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "AIJudge"; }
    std::string getDescription() const override { return "AI scores creativity or efficiency"; }
    std::string getCategory() const override { return "Experimental Games"; }
};

#endif // AI_JUDGE_H
