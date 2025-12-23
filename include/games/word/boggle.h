#ifndef BOGGLE_H
#define BOGGLE_H

#include "game_base.h"

class Boggle : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "Boggle"; }
    std::string getDescription() const override { return "Find words in a grid of letters"; }
    std::string getCategory() const override { return "Word & Language Games"; }
};

#endif // BOGGLE_H
