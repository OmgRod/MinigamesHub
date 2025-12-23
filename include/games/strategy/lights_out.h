#ifndef LIGHTS_OUT_H
#define LIGHTS_OUT_H

#include "game_base.h"

class LightsOut : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "LightsOut"; }
    std::string getDescription() const override { return "Turn all lights off"; }
    std::string getCategory() const override { return "Strategy & Thinking Games"; }
};

#endif // LIGHTS_OUT_H
