#pragma once

#include <string>

namespace FileTool
{
    std::string listCurrentDirectory();
    std::string readFile(const std::string& fileName);
    bool createFile(const std::string& fileName);
    bool writeFile(const std::string& fileName, const std::string& content);
}