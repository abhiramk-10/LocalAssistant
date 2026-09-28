#include "ToolManager.h"

#include "FileTool.h"
#include "SystemTool.h"

#include <sstream>

namespace
{
    bool startsWith(const std::string& value, const std::string& prefix)
    {
        return value.rfind(prefix, 0) == 0;
    }
}

std::string ToolManager::execute(const std::string& command)
{
    if (command == "help")
    {
        return
            "Available commands:\n"
            "  help                       Show available commands\n"
            "  time                       Show current time\n"
            "  date                       Show current date\n"
            "  system                     Show system information\n"
            "  computer                   Show computer name\n"
            "  list                       List files and folders\n"
            "  read <file>                Read a file\n"
            "  create <file>              Create an empty file\n"
            "  write <file> | <text>      Write text to a file\n"
            "  exit                       Close the assistant";
    }

    if (command == "time")
    {
        return SystemTool::getCurrentTime();
    }

    if (command == "date")
    {
        return SystemTool::getCurrentDate();
    }

    if (command == "computer")
    {
        return SystemTool::getComputerName();
    }

    if (command == "system")
    {
        return "Computer: " + SystemTool::getComputerName() +
               "\nArchitecture: " + SystemTool::getArchitecture() +
               "\nProcessors: " +
               std::to_string(SystemTool::getProcessorCount());
    }

    if (command == "list")
    {
        return FileTool::listCurrentDirectory();
    }

    if (startsWith(command, "read "))
    {
        const std::string fileName = command.substr(5);

        if (fileName.empty())
        {
            return "Usage: read <file>";
        }

        return FileTool::readFile(fileName);
    }

    if (startsWith(command, "create "))
    {
        const std::string fileName = command.substr(7);

        if (fileName.empty())
        {
            return "Usage: create <file>";
        }

        if (FileTool::createFile(fileName))
        {
            return "Created: " + fileName;
        }

        return "Error: Could not create " + fileName;
    }

    if (startsWith(command, "write "))
    {
        const std::string arguments = command.substr(6);
        const std::size_t separator = arguments.find(" | ");

        if (separator == std::string::npos)
        {
            return "Usage: write <file> | <text>";
        }

        const std::string fileName = arguments.substr(0, separator);
        const std::string content = arguments.substr(separator + 3);

        if (fileName.empty() || content.empty())
        {
            return "Usage: write <file> | <text>";
        }

        if (FileTool::writeFile(fileName, content))
        {
            return "Updated: " + fileName;
        }

        return "Error: Could not write to " + fileName;
    }

    return "Unknown command: " + command + "\nType 'help' to see available commands.";
}
