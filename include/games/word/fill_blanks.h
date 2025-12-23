#ifndef FILL_BLANKS_H
#define FILL_BLANKS_H

#include "game_base.h"

class FillBlanks : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "FillBlanks"; }
    std::string getDescription() const override { return "Complete phrases with missing words"; }
    std::string getCategory() const override { return "Word & Language Games"; }
};

#endif // FILL_BLANKS_H
