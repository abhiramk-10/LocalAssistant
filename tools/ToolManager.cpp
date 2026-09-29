#include "ToolManager.h"
// Includes this class's declaration before defining its functions.

#include "FileTool.h"
// Provides file operations such as listing and reading files.

#include "SystemTool.h"
// Provides system operations such as time and computer information.

#include <sstream>
// Provides string-stream types. The current file uses string-related
// standard-library functionality and keeps parsing logic readable.

// ------------------------------------------------------------
// Helper function: startsWith
// ------------------------------------------------------------
// A helper function is a small function used internally to support
// a larger operation.
//
// This function is inside an unnamed namespace, which gives it
// internal linkage: other .cpp files cannot directly use it.
namespace
{
    bool startsWith(const std::string& value, const std::string& prefix)
    {
        // rfind(prefix, 0) searches for prefix starting at position 0.
        // If it returns 0, the string begins with that prefix.
        return value.rfind(prefix, 0) == 0;
    }
}

// ------------------------------------------------------------
// ToolManager::execute
// ------------------------------------------------------------
// This is the main command-dispatch function.
//
// Input:
//     command = text such as "time", "list", or "read file.txt"
//
// Output:
//     a string containing the result or an error message.
std::string ToolManager::execute(const std::string& command)
{
    // --------------------------------------------------------
    // Exact command matching
    // --------------------------------------------------------
    // The == operator compares two strings for equality.
    if (command == "help")
    {
        // Adjacent string literals are automatically joined by C++.
        // This lets us format a long message over multiple lines.
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
        // Scope resolution operator '::' selects a function from
        // the SystemTool namespace.
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
        // The '+' operator concatenates std::string values.
        // std::to_string converts the processor count into text.
        return "Computer: " + SystemTool::getComputerName() +
               "\nArchitecture: " + SystemTool::getArchitecture() +
               "\nProcessors: " +
               std::to_string(SystemTool::getProcessorCount());
    }

    if (command == "list")
    {
        return FileTool::listCurrentDirectory();
    }

    // --------------------------------------------------------
    // Commands with arguments
    // --------------------------------------------------------
    // Unlike "time", a command such as "read notes.txt" contains
    // both a command name and user-provided data.
    if (startsWith(command, "read "))
    {
        // substr(5) returns a new string beginning at character 5.
        // For "read notes.txt", this produces "notes.txt".
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

        // find() returns the position of the requested separator.
        // std::string::npos means the separator was not found.
        const std::size_t separator = arguments.find(" | ");

        if (separator == std::string::npos)
        {
            return "Usage: write <file> | <text>";
        }

        // substr() extracts the part before the separator.
        const std::string fileName = arguments.substr(0, separator);

        // separator + 3 skips the three characters in " | ".
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

    // No known command matched the input.
    return "Unknown command: " + command +
           "\nType 'help' to see available commands.";
}
