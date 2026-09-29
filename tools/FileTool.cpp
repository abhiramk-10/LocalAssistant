#include "FileTool.h"
// Includes the declarations of the FileTool functions implemented below.

#include <filesystem>
// C++17 filesystem library for directories, paths, and file operations.
#include <sstream>
// Provides std::ostringstream for building strings in memory.
#include <fstream>
// Provides std::ifstream and std::ofstream for file input/output.

// Namespace alias: lets us write fs:: instead of std::filesystem.
namespace fs = std::filesystem;

namespace FileTool
{
    // Lists entries in the program's current working directory.
    std::string listCurrentDirectory()
    {
        // ostringstream builds a string using the stream << operator.
        std::ostringstream output;

        try
        {
            // current_path() gets the working directory.
            // directory_iterator visits each entry in that directory.
            for (const auto& entry :
                 fs::directory_iterator(fs::current_path()))
            {
                // const auto& means: do not modify the entry, let C++
                // determine its type, and avoid copying the object.
                if (entry.is_directory())
                {
                    output << "[DIR]  "
                           << entry.path().filename().string()
                           << '\n';
                }
                else
                {
                    output << "[FILE] "
                           << entry.path().filename().string()
                           << '\n';
                }
            }
        }
        catch (const fs::filesystem_error& error)
        {
            // try/catch handles exceptions from filesystem operations.
            // const reference avoids copying the exception object.
            return "Error: " + std::string(error.what());
        }

        // str() converts the stream's accumulated data into std::string.
        return output.str();
    }

    // Opens a file and returns all of its contents.
    std::string readFile(const std::string& fileName)
    {
        // ifstream = input file stream: reads FROM a file.
        std::ifstream file(fileName);

        if (!file.is_open())
        {
            // ! means logical NOT: this means "file is not open".
            return "Error: Could not open file.";
        }

        std::ostringstream output;

        // rdbuf() accesses the file's stream buffer. Sending it to
        // output copies the file contents into the string stream.
        output << file.rdbuf();

        return output.str();
    }

    // Creates an empty file and returns whether opening it succeeded.
    bool createFile(const std::string& fileName)
    {
        // ofstream = output file stream: writes TO a file.
        std::ofstream file(fileName);

        // is_open() returns true when the stream opened successfully.
        return file.is_open();
    }

    // Writes content to a file and reports success/failure.
    bool writeFile(const std::string& fileName,
                   const std::string& content)
    {
        std::ofstream file(fileName);

        if (!file.is_open())
        {
            return false;
        }

        // << sends the text into the output file stream.
        file << content;

        return true;
    }
}
