#ifndef RHYME_MATCH_H
#define RHYME_MATCH_H

#include "game_base.h"

class RhymeMatch : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "RhymeMatch"; }
    std::string getDescription() const override { return "Find words that rhyme"; }
    std::string getCategory() const override { return "Word & Language Games"; }
};

#endif // RHYME_MATCH_H
