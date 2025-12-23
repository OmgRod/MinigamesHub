#ifndef HEX_GO_H
#define HEX_GO_H

#include "game_base.h"

class HexGo : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    
    std::string getName() const override { return "HexGo"; }
    std::string getDescription() const override { return "Hex or Go mini-boards"; }
    std::string getCategory() const override { return "Strategy & Thinking Games"; }
};

#endif // HEX_GO_H
