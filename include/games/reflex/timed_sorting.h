#ifndef TIMED_SORTING_H
#define TIMED_SORTING_H

#include "game_base.h"

class TimedSorting : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "TimedSorting"; }
    std::string getDescription() const override { return "Categorize items quickly"; }
    std::string getCategory() const override { return "Quick/Reflex Games"; }
};

#endif // TIMED_SORTING_H
