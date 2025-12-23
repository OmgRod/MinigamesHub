#ifndef SPEED_TYPING_H
#define SPEED_TYPING_H

#include "game_base.h"

class SpeedTyping : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "SpeedTyping"; }
    std::string getDescription() const override { return "Test accuracy and speed"; }
    std::string getCategory() const override { return "Word & Language Games"; }
};

#endif // SPEED_TYPING_H
