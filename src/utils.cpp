#include "utils.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <chrono>

#ifdef PLATFORM_WINDOWS
#include <conio.h>
#include <windows.h>
#else
#include <unistd.h>
#include <termios.h>
#endif

namespace Utils {

void clearScreen() {
#ifdef PLATFORM_WINDOWS
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string getInput(const std::string& prompt) {
    std::cout << prompt;
    std::string input;
    std::getline(std::cin, input);
    return input;
}

int getIntInput(const std::string& prompt, int min, int max) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        
        if (input.empty()) {
            continue;
        }
        
        try {
            int value = std::stoi(input);
            if (value >= min && value <= max) {
                return value;
            }
            std::cout << "Please enter a number between " << min << " and " << max << ".\n";
        } catch (...) {
            std::cout << "Invalid input. Please enter a number.\n";
        }
    }
}

std::string toUpper(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

std::string toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}

static std::mt19937& getRandomEngine() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return gen;
}

int randomInt(int min, int max) {
    std::uniform_int_distribution<> dis(min, max);
    return dis(getRandomEngine());
}

double randomDouble(double min, double max) {
    std::uniform_real_distribution<> dis(min, max);
    return dis(getRandomEngine());
}

bool randomBool() {
    return randomInt(0, 1) == 1;
}

long long getCurrentTimeMs() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    ).count();
}

void printCentered(const std::string& text, int width) {
    int padding = (width - static_cast<int>(text.length())) / 2;
    if (padding > 0) {
        std::cout << std::string(padding, ' ');
    }
    std::cout << text << std::endl;
}

void printBox(const std::string& text, int padding) {
    int width = static_cast<int>(text.length()) + (padding * 2);
    std::string border(width + 2, '=');
    
    std::cout << border << std::endl;
    std::cout << "|" << std::string(padding, ' ') << text << std::string(padding, ' ') << "|" << std::endl;
    std::cout << border << std::endl;
}

void printSeparator(char ch, int width) {
    std::cout << std::string(width, ch) << std::endl;
}

} // namespace Utils
