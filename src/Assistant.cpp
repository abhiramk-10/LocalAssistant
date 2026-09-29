#include "Assistant.h"
// Includes the Assistant class declaration.
#include <iostream>
// Provides std::cout for console output and std::cin for input.

// ------------------------------------------------------------
// Assistant::run()
// ------------------------------------------------------------
// Starts the main interactive loop of the assistant.
void Assistant::run()
{
    // std::string stores the command typed by the user.
    std::string command;

    // Print a simple startup screen.
    std::cout << "================================\n";
    std::cout << "       LOCAL ASSISTANT v0.2\n";
    std::cout << "================================\n";
    std::cout << "Type 'help' for available commands.\n\n";

    // while(true) creates an intentional infinite loop.
    // We leave the loop with break when the user exits or input closes.
    while (true)
    {
        std::cout << "You: ";

        // getline() reads a complete line, including spaces.
        // It returns false when input reaches EOF or another input error.
        if (!std::getline(std::cin, command))
        {
            std::cout << "\nAssistant: Input closed. Goodbye.\n";
            break;
        }

        // empty() checks whether the string contains zero characters.
        // Ignore blank input instead of sending it to a tool.
        if (command.empty())
        {
            continue;
            // continue skips the rest of this loop iteration and
            // starts the next iteration.
        }

        // Exact string comparison checks for the exit command.
        if (command == "exit")
        {
            std::cout << "Assistant: Goodbye.\n";
            break;
        }

        // Send the command to the next layer of the architecture.
        // Assistant handles interaction; ToolManager handles dispatch.
        processCommand(command);
    }
}

// ------------------------------------------------------------
// Assistant::processCommand()
// ------------------------------------------------------------
// Receives one user command and asks ToolManager to execute it.
void Assistant::processCommand(const std::string& command)
{
    // std::cout writes text to the console.
    // ToolManager::execute() returns the result as a std::string.
    std::cout << "Assistant: " << toolManager.execute(command) << '\n';
}
