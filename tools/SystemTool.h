#pragma once
// Prevents duplicate inclusion of this header.

#include <string>
// Provides std::string, which we use for textual system information.

// ------------------------------------------------------------
// namespace SystemTool
// ------------------------------------------------------------
// A namespace groups related functions and prevents name clashes.
// These functions belong to the SystemTool namespace, so callers
// use names such as SystemTool::getCurrentTime().
namespace SystemTool
{
    // Function declarations (prototypes).
    // A declaration tells the compiler that the function exists;
    // the implementation is provided in SystemTool.cpp.

    // Returns the current local time as formatted text.
    std::string getCurrentTime();

    // Returns the current local date as formatted text.
    std::string getCurrentDate();

    // Returns general system information.
    std::string getSystemInfo();

    // Returns the Windows computer name.
    std::string getComputerName();

    // Returns the native processor architecture as text.
    std::string getArchitecture();

    // Returns the number of logical processors reported by Windows.
    int getProcessorCount();
}
