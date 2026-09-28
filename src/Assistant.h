#pragma once //this line is used for preventing multiple inclusions of the same header file in a single compilation unit. It ensures that the contents of the header file are included only once, avoiding potential redefinition errors.

#include <string>

class Assistant
{
public:
    void run(); 

private:
    void processCommand(const std::string& command);
};