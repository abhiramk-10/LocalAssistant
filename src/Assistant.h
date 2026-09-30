#pragma once
// #pragma once tells the compiler to include this header only once
// in a translation unit. It prevents duplicate declarations.

#include <string>
// std::string is the C++ standard-library type used for text.

#include "../core/Brain.h"
// Brain converts natural-language input into a structured decision.

#include "../core/TaskManager.h"
// TaskManager stores tasks and sends them to the tool layer.

// ------------------------------------------------------------
// class Assistant
// ------------------------------------------------------------
// Assistant is the application's user-interface/controller layer.
//
// It connects the major parts of the system:
//
//     User
//       ↓
//     Assistant
//       ↓
//     Brain
//       ↓
//     TaskManager
//       ↓
//     ToolManager
//       ↓
//     Tools
//
// This is our first important step from a collection of tools
// toward an actual assistant architecture.
class Assistant
{
public:
    // Public means code outside the class can call this function.
    // run() starts the main user-interaction loop.
    void run();

private:
    // processCommand() takes one complete line entered by the user
    // and moves it through the assistant pipeline.
    void processCommand(const std::string& command);

    // --------------------------------------------------------
    // Composition
    // --------------------------------------------------------
    // Assistant "has a" Brain.
    // The Brain is responsible for understanding the request.
    Brain brain;

    // Assistant "has a" TaskManager.
    // TaskManager is responsible for representing and executing work.
    TaskManager taskManager;
};
