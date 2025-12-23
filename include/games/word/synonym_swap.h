#ifndef SYNONYM_SWAP_H
#define SYNONYM_SWAP_H

#include "game_base.h"

class SynonymSwap : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "SynonymSwap"; }
    std::string getDescription() const override { return "Replace words with correct synonyms"; }
    std::string getCategory() const override { return "Word & Language Games"; }
};

#endif // SYNONYM_SWAP_H
