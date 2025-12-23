#ifndef MISSING_LETTER_H
#define MISSING_LETTER_H

#include "game_base.h"

class MissingLetter : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "MissingLetter"; }
    std::string getDescription() const override { return "Complete partially erased words"; }
    std::string getCategory() const override { return "Word & Language Games"; }
};

#endif // MISSING_LETTER_H
