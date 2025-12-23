#ifndef NIM_H
#define NIM_H

#include "game_base.h"

class Nim : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "Nim"; }
    std::string getDescription() const override { return "Mathematical strategy game"; }
    std::string getCategory() const override { return "Strategy & Thinking Games"; }
};

#endif // NIM_H
