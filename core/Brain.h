#pragma once

#include <string>

struct BrainDecision
{
    bool understood;
    std::string command;
    std::string message;
};

class Brain
{
public:
    BrainDecision think(const std::string& input) const;
};
