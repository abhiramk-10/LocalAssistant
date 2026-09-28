#pragma once

#include <string>

namespace SystemTool
{
    std::string getCurrentTime();
    std::string getCurrentDate();
    std::string getSystemInfo();
    std::string getComputerName();
    std::string getArchitecture();
    int getProcessorCount();
}