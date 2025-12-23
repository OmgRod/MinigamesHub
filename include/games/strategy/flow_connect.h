#ifndef FLOW_CONNECT_H
#define FLOW_CONNECT_H

#include "game_base.h"

class FlowConnect : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "FlowConnect"; }
    std::string getDescription() const override { return "Connect matching colors"; }
    std::string getCategory() const override { return "Strategy & Thinking Games"; }
};

#endif // FLOW_CONNECT_H
