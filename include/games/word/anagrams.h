#ifndef ANAGRAMS_H
#define ANAGRAMS_H

#include "game_base.h"

class Anagrams : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "Anagrams"; }
    std::string getDescription() const override { return "Rearrange letters to form words"; }
    std::string getCategory() const override { return "Word & Language Games"; }
};

#endif // ANAGRAMS_H
