#include "Assistant.h"
#include "../tools/SystemTool.h"
#include "../tools/FileTool.h"

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

void Assistant::processCommand(const std::string& command) //Assistant::processCommand(const std::string& command) means that the processCommand() function is a member function of the Assistant class. The scope resolution operator (::) is used to define the function outside the class definition, indicating that it belongs to the Assistant class.
{
    if (command == "help")
    {
        std::cout << "Assistant: Available commands:\n";
        std::cout << "  help   - Show available commands\n";
        std::cout << "  time   - Show current time\n";
        std::cout << "  date   - Show current date\n";
        std::cout << "  system - Show system information\n";
        std::cout << "  computer - Show computer name\n";
        std::cout << "  list   - List files and folders\n";
        std::cout << "  read <file> - Read a file\n";
        std::cout << "  create <file> - Create a file\n";
        std::cout << "  write <file> <text> - Write text to a file\n";
        std::cout << "  exit   - Close the assistant\n";
    }
    else if (command == "time")
    {
        std::cout << "Assistant: Current time is " << SystemTool::getCurrentTime() << "\n";
    }
    else if (command == "date")
    {
        std::cout << "Assistant: Today's date is " << SystemTool::getCurrentDate() << "\n";
    }
    else if (command == "system")
    {
        std::cout << "Assistant:\n";
        std::cout << "Computer: " << SystemTool::getComputerName() << "\n";
        std::cout << "Architecture: " << SystemTool::getArchitecture() << "\n";
        std::cout << "Processors: " << SystemTool::getProcessorCount() << "\n";
    }
    else if (command == "computer")
    {
        std::cout << "Assistant: Computer name: " << SystemTool::getComputerName() << "\n";
    }
    else if (command == "list")
    {
        std::cout << "Assistant:\n";
        std::cout << FileTool::listCurrentDirectory();
    }
    else if (command.rfind("read ", 0) == 0)
    {
        const std::string fileName = command.substr(5);

        std::cout << "Assistant:\n";
        std::cout << FileTool::readFile(fileName) << "\n";
    }
    else if (command.rfind("create ", 0) == 0)
    {
        const std::string fileName = command.substr(7);

        if (FileTool::createFile(fileName))
        {
            std::cout << "Assistant: File created successfully.\n";
        }
        else
        {
            std::cout << "Assistant: Failed to create file.\n";
        }
    }
    else if (command.rfind("write ", 0) == 0)
    {
        const std::string arguments = command.substr(6);

        const std::size_t separator = arguments.find(' ');

        if (separator == std::string::npos)
        {
            std::cout << "Assistant: Usage: write <file> <content>\n";
            return;
        }

        const std::string fileName = arguments.substr(0, separator);
        const std::string content = arguments.substr(separator + 1);

        if (FileTool::writeFile(fileName, content))
        {
            std::cout << "Assistant: File written successfully.\n";
        }
        else
        {
            std::cout << "Assistant: Failed to write file.\n";
        }
    }
    else if (command.empty())
    {
        // Ignore empty input.
    }
    else
    {
        std::cout << "Assistant: I don't understand that command yet.\n";
    }
}