#pragma once
// Prevents this header from being included more than once.

#include <string>
// std::string stores text in C++.

// ------------------------------------------------------------
// class ToolManager
// ------------------------------------------------------------
// ToolManager is the dispatch layer between a command and the
// concrete tool that performs the operation.
//
// Example:
//     "time" -> ToolManager -> SystemTool
//     "list" -> ToolManager -> FileTool
class ToolManager
{
public:
    // --------------------------------------------------------
    // execute()
    // --------------------------------------------------------
    // A member function is a function that belongs to a class.
    //
    // const std::string& command:
    //     const -> do not modify the caller's string
    //     &     -> pass by reference instead of copying it
    //
    // std::string before the function name is the return type.
    // The function returns the tool's result as text.
    std::string execute(const std::string& command);
};
