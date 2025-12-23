#ifndef PALINDROMES_H
#define PALINDROMES_H

#include "game_base.h"

class Palindromes : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "Palindromes"; }
    std::string getDescription() const override { return "Identify or construct palindromes"; }
    std::string getCategory() const override { return "Word & Language Games"; }
};

#endif // PALINDROMES_H
