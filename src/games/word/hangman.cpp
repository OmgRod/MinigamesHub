#include "games/word/hangman.h"
#include "utils.h"
#include <iostream>
#include <algorithm>

void Hangman::initialize() {
    words_ = {"PROGRAMMING", "COMPUTER", "ALGORITHM", "SOFTWARE", "DEVELOPER",
              "FUNCTION", "VARIABLE", "DATABASE", "NETWORK", "INTERNET"};
    attemptsLeft_ = 6;
    guessedLetters_.clear();
}

void Hangman::run() {
    Utils::clearScreen();
    Utils::printBox(getName(), 3);
    std::cout << "\n" << getDescription() << "\n\n";
    
    currentWord_ = words_[Utils::randomInt(0, words_.size() - 1)];
    guessedWord_ = std::string(currentWord_.length(), '_');
    
    std::cout << "Guess the word! You have " << attemptsLeft_ << " attempts.\n\n";
    
    while (!isGameOver()) {
        displayState();
        
        std::string input = Utils::getInput("\nGuess a letter: ");
        if (input.empty()) continue;
        
        char guess = toupper(input[0]);
        
        if (std::find(guessedLetters_.begin(), guessedLetters_.end(), guess) != guessedLetters_.end()) {
            std::cout << "You already guessed that letter!\n";
            continue;
        }
        
        guessedLetters_.push_back(guess);
        
        bool found = false;
        for (size_t i = 0; i < currentWord_.length(); ++i) {
            if (currentWord_[i] == guess) {
                guessedWord_[i] = guess;
                found = true;
            }
        }
        
        if (!found) {
            attemptsLeft_--;
            std::cout << "Wrong guess! Attempts left: " << attemptsLeft_ << "\n";
        } else {
            std::cout << "Good guess!\n";
        }
        
        if (isWordGuessed()) {
            Utils::clearScreen();
            std::cout << "\n🎉 Congratulations! You won!\n";
            std::cout << "The word was: " << currentWord_ << "\n\n";
            break;
        }
        
        if (attemptsLeft_ == 0) {
            Utils::clearScreen();
            std::cout << "\n😢 Game Over!\n";
            std::cout << "The word was: " << currentWord_ << "\n\n";
            break;
        }
    }
    
    Utils::pauseScreen();
}

void Hangman::cleanup() {
    guessedLetters_.clear();
}

void Hangman::displayState() {
    std::cout << "\nWord: ";
    for (char c : guessedWord_) {
        std::cout << c << " ";
    }
    std::cout << "\n";
    
    std::cout << "Guessed letters: ";
    for (char c : guessedLetters_) {
        std::cout << c << " ";
    }
    std::cout << "\nAttempts left: " << attemptsLeft_ << "\n";
}

bool Hangman::isGameOver() {
    return attemptsLeft_ == 0 || isWordGuessed();
}

bool Hangman::isWordGuessed() {
    return guessedWord_ == currentWord_;
}
