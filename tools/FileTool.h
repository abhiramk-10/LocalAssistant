#pragma once

#include <string>

namespace FileTool
{
    std::string listCurrentDirectory();
    std::string readFile(const std::string& fileName);
    bool createFile(const std::string& fileName);
    bool writeFile(const std::string& fileName, const std::string& content);
    bool appendFile(const std::string& fileName, const std::string& content);
    bool fileExists(const std::string& fileName);
    bool deleteFile(const std::string& fileName);
}
