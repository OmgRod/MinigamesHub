#ifndef KENKEN_H
#define KENKEN_H

#include "game_base.h"

class KenKen : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "KenKen"; }
    std::string getDescription() const override { return "Math-based logic puzzle"; }
    std::string getCategory() const override { return "Logic & Number Games"; }
};

#endif // KENKEN_H
