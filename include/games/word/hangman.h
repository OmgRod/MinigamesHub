#ifndef HANGMAN_H
#define HANGMAN_H

#include "game_base.h"
#include <vector>
#include <string>

class Hangman : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "Hangman"; }
    std::string getDescription() const override { return "Guess the word letter by letter"; }
    std::string getCategory() const override { return "Word & Language Games"; }

private:
    std::vector<std::string> words_;
    std::string currentWord_;
    std::string guessedWord_;
    std::vector<char> guessedLetters_;
    int attemptsLeft_;
    
    void displayState();
    bool isGameOver();
    bool isWordGuessed();
};

#endif // HANGMAN_H
