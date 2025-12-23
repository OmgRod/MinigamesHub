#ifndef WORD_SEARCH_H
#define WORD_SEARCH_H

#include "game_base.h"

class WordSearch : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "WordSearch"; }
    std::string getDescription() const override { return "Classic grid-based word finding"; }
    std::string getCategory() const override { return "Word & Language Games"; }
};

#endif // WORD_SEARCH_H
