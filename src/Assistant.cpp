#include "Assistant.h"
#include "../tools/SystemTool.h"
#include "../tools/FileTool.h"
#include "../tools/ToolManager.h"

#include <iostream>


void Assistant::run() // Assistant::run() means that the run() function is a member function of the Assistant class. The scope resolution operator (::) is used to define the function outside the class definition, indicating that it belongs to the Assistant class.  
{
    std::string command;

    std::cout << "================================\n";
    std::cout << "       LOCAL ASSISTANT v0.1\n";
    std::cout << "================================\n\n";

    while (true)
    {
        std::cout << "You: ";
        std::getline(std::cin, command);

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
    if (command == "exit")
    {
        return;
    }

    std::cout << "Assistant: " << toolManager.execute(command) << '\n';
}