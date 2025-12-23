#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <random>

namespace Utils {
    // Console utilities
    void clearScreen();
    void pauseScreen();
    std::string getInput(const std::string& prompt);
    int getIntInput(const std::string& prompt, int min, int max);
    
    // String utilities
    std::string toUpper(const std::string& str);
    std::string toLower(const std::string& str);
    std::vector<std::string> split(const std::string& str, char delimiter);
    std::string trim(const std::string& str);
    
    // Random utilities
    int randomInt(int min, int max);
    double randomDouble(double min, double max);
    bool randomBool();
    
    // Time utilities
    long long getCurrentTimeMs();
    
    // Display utilities
    void printCentered(const std::string& text, int width = 80);
    void printBox(const std::string& text, int padding = 2);
    void printSeparator(char ch = '=', int width = 80);
}

#endif // UTILS_H
