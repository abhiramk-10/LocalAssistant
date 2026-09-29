#pragma once
// #pragma once tells the compiler to include this header only once
// in a translation unit. It prevents duplicate declarations.

#include <string>
// std::string is the C++ standard-library type used for text.

#include "../tools/ToolManager.h"
// Assistant owns a ToolManager, so the complete ToolManager
// declaration is needed here.

// ------------------------------------------------------------
// class Assistant
// ------------------------------------------------------------
// A class groups related data and functions into one type.
// Assistant is the main application/controller layer.
//
// Its job is to handle the interaction loop and pass work to
// lower-level components instead of implementing every tool itself.
class Assistant
{
public:
    // Public means code outside the class can call this function.
    // run() starts the assistant's main user-interaction loop.
    void run();

private:
    // private means only Assistant's member functions can directly
    // call/access this function.
    //
    // processCommand() takes one user command and sends it to the
    // execution layer.
    void processCommand(const std::string& command);

    // --------------------------------------------------------
    // Composition
    // --------------------------------------------------------
    // ToolManager is stored as a member object inside Assistant.
    // This is called composition: an Assistant "has a" ToolManager.
    ToolManager toolManager;
};
