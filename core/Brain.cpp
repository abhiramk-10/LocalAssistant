#include "Brain.h"

#include <algorithm>
#include <cctype>

namespace
{
    std::string normalize(std::string value)
    {
        std::transform(value.begin(), value.end(), value.begin(),
                       [](unsigned char character)
                       {
                           return static_cast<char>(std::tolower(character));
                       });
        return value;
    }
}

BrainDecision Brain::think(const std::string& input) const
{
    const std::string text = normalize(input);

    if (text == "help" || text == "commands")
    {
        return {true, "help", "Showing available commands."};
    }

    if (text == "time" || text == "what time is it" ||
        text == "current time")
    {
        return {true, "time", "Checking the current time."};
    }

    if (text == "date" || text == "today" ||
        text == "what is the date")
    {
        return {true, "date", "Checking today's date."};
    }

    if (text == "system" || text == "system information" ||
        text == "system info")
    {
        return {true, "system", "Checking system information."};
    }

    if (text == "computer" || text == "computer name" ||
        text == "what is my computer name")
    {
        return {true, "computer", "Checking the computer name."};
    }

    if (text == "list" || text == "list files" ||
        text == "show files")
    {
        return {true, "list", "Checking the current directory."};
    }

    return {false, {}, "I don't understand that request yet."};
}
