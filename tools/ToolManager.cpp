#include "ToolManager.h"

#include "FileTool.h"
#include "SystemTool.h"

std::string ToolManager::execute(const std::string& command)
{
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

    return "Unknown command.";
}