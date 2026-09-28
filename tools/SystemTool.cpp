#include "SystemTool.h"

#include <windows.h>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

namespace SystemTool
{
    std::string getCurrentTime()
    {
        const auto now = std::chrono::system_clock::now();
        const std::time_t currentTime =
            std::chrono::system_clock::to_time_t(now);

        std::tm localTime{};

        localtime_s(&localTime, &currentTime);

        std::ostringstream output;
        output << std::put_time(&localTime, "%H:%M:%S");

        return output.str();
    }

    std::string getCurrentDate()
    {
        const auto now = std::chrono::system_clock::now();
        const std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        std::tm localTime{};
       
        localtime_s(&localTime, &currentTime);

        std::ostringstream output;
        output << std::put_time(&localTime, "%Y-%m-%d");

        return output.str();
    }

    std::string getSystemInfo()
    {
        return "OS: Windows\nArchitecture: x64\nCompiler: GCC";
    }

    std::string getComputerName()
    {
        char computerName[MAX_COMPUTERNAME_LENGTH + 1];
        DWORD size = sizeof(computerName);

        if (GetComputerNameA(computerName, &size))
        {
            return std::string(computerName);
        }

        return "Unknown";
    }
    
    std::string getArchitecture()
    {
        SYSTEM_INFO systemInfo{};
        GetNativeSystemInfo(&systemInfo);

        if (systemInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
        {
            return "x64";
        }

        if (systemInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_ARM64)
        {
            return "ARM64";
        }

        return "Unknown";
    }

    int getProcessorCount()
    {
        SYSTEM_INFO systemInfo{};
        GetSystemInfo(&systemInfo);

        return static_cast<int>(systemInfo.dwNumberOfProcessors);
    }
}