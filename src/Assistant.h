#pragma once

#include <string>

#include "../tools/ToolManager.h"

class Assistant
{
public:
    void run();

private:
    void processCommand(const std::string& command);

    ToolManager toolManager;
};