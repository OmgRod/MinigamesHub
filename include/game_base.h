#ifndef GAME_BASE_H
#define GAME_BASE_H

#include <string>

class GameBase {
public:
    virtual ~GameBase() = default;
    
    // Core game interface
    virtual void initialize() = 0;
    virtual void run() = 0;
    virtual void cleanup() = 0;
    
    // Game info
    virtual std::string getName() const = 0;
    virtual std::string getDescription() const = 0;
    virtual std::string getCategory() const = 0;
};

#endif // GAME_BASE_H
