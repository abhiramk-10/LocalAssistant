#include "Assistant.h"

#include <iostream>

void Assistant::run()
{
    std::string command;

    std::cout << "================================\n";
    std::cout << "       LOCAL ASSISTANT v0.2\n";
    std::cout << "================================\n";
    std::cout << "Type 'help' for available commands.\n\n";

    while (true)
    {
        std::cout << "You: ";

        if (!std::getline(std::cin, command))
        {
            std::cout << "\nAssistant: Input closed. Goodbye.\n";
            break;
        }

        if (command.empty())
        {
            continue;
        }

        if (command == "exit")
        {
            std::cout << "Assistant: Goodbye.\n";
            break;
        }

        processCommand(command);
    }
}

void Assistant::processCommand(const std::string& command)
{
    std::cout << "Assistant: " << toolManager.execute(command) << '\n';
}
