#pragma once
// Ensures this header is included only once per translation unit.

#include <string>
// std::string is used for file names, file contents, and results.

// ------------------------------------------------------------
// namespace FileTool
// ------------------------------------------------------------
// Groups all file-related operations under one name.
//
// Example:
//     FileTool::readFile("notes.txt");
namespace FileTool
{
    // Function declarations tell the compiler what functions are
    // available. Their implementations live in FileTool.cpp.

    // Lists files and directories in the current working directory.
    std::string listCurrentDirectory();

    // Opens a file and returns its contents as a string.
    std::string readFile(const std::string& fileName);

    // Creates an empty file. Returns true on success.
    bool createFile(const std::string& fileName);

    // Writes content to a file. Returns true on success.
    bool writeFile(const std::string& fileName, const std::string& content);

    // Appends content to an existing file.
    bool appendFile(const std::string& fileName, const std::string& content);

    // Checks whether a file exists.
    bool fileExists(const std::string& fileName);

    // Deletes a file.
    bool deleteFile(const std::string& fileName);
}
