#include "Brain.h"
// Includes the Brain class and BrainDecision declarations.
#include <algorithm>
// Provides std::transform for processing each character.
#include <cctype>
// Provides std::tolower for lowercase conversion.

// ------------------------------------------------------------
// Unnamed namespace
// ------------------------------------------------------------
// Names inside an unnamed namespace are intended for this .cpp file.
// This keeps implementation helpers private to this translation unit.
namespace
{
    // --------------------------------------------------------
    // normalize()
    // --------------------------------------------------------
    // Converts input to lowercase so commands can be compared
    // without caring about uppercase/lowercase differences.
    //
    // Example:
    //     "WHAT TIME IS IT"
    // becomes:
    //     "what time is it"
    std::string normalize(std::string value)
    {
        // std::transform applies a function to every element in a range.
        // begin() points to the first character; end() points just after
        // the last character. The third argument is where results go.
        std::transform(
            value.begin(),
            value.end(),
            value.begin(),

            // Lambda function: a small function written directly where
            // it is needed. It receives one character at a time.
            [](unsigned char character)
            {
                // tolower converts the character to lowercase.
                // static_cast<char> explicitly converts the result back
                // to char because tolower returns an int.
                return static_cast<char>(std::tolower(character));
            }
        );

        return value;
    }
}

// ------------------------------------------------------------
// Brain::think()
// ------------------------------------------------------------
// This function is the first version of our local "brain".
// It maps natural-language variations to internal commands.
//
// Important:
// This is rule-based intent recognition, not an LLM.
BrainDecision Brain::think(const std::string& input) const
{
    // const means the local text variable cannot be modified later.
    // normalize() creates the lowercase form used for comparison.
    const std::string text = normalize(input);

    // || is logical OR. The condition is true when any one of the
    // listed phrases matches the normalized user input.
    if (text == "help" || text == "commands")
    {
        // Return a BrainDecision using aggregate initialization.
        // Values are assigned in struct-member order:
        // understood, command, message.
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

    // {} creates an empty std::string for command.
    // understood=false tells the caller that no known intent matched.
    return {false, {}, "I don't understand that request yet."};
}
