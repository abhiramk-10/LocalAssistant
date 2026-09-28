#include "FileTool.h"

#include <filesystem>
#include <sstream>
#include <fstream>

namespace fs = std::filesystem;

namespace FileTool
{
    std::string listCurrentDirectory()
    {
        std::ostringstream output;

        try
        {
            for (const auto& entry : fs::directory_iterator(fs::current_path()))
            {
                if (entry.is_directory())
                {
                    output << "[DIR]  " << entry.path().filename().string() << '\n';
                }
                else
                {
                    output << "[FILE] " << entry.path().filename().string() << '\n';
                }
            }
        }
        catch (const fs::filesystem_error& error)
        {
            return "Error: " + std::string(error.what());
        }

        return output.str();
    }

    std::string readFile(const std::string& fileName)
    {
        std::ifstream file(fileName);

        if (!file.is_open())
        {
            return "Error: Could not open file.";
        }

        std::ostringstream output;
        output << file.rdbuf();

        return output.str();
    }
    bool createFile(const std::string& fileName)
    {
        std::ofstream file(fileName);

        return file.is_open();
    }
    bool writeFile(const std::string& fileName, const std::string& content)
    {
        std::ofstream file(fileName);

        if (!file.is_open())
        {
            return false;
        }

        file << content;

        return true;
    }
}