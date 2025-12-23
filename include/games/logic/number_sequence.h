#ifndef NUMBER_SEQUENCE_H
#define NUMBER_SEQUENCE_H

#include "game_base.h"

class NumberSequence : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "NumberSequence"; }
    std::string getDescription() const override { return "Predict the next number"; }
    std::string getCategory() const override { return "Logic & Number Games"; }
};

#endif // NUMBER_SEQUENCE_H
