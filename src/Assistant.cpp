#include "Assistant.h"
// Includes the Assistant class declaration.

#include <iostream>
// std::cout writes text to the terminal.
// std::cin reads user input from the terminal.

#include <string>
// std::string stores the command entered by the user.

// ------------------------------------------------------------
// Assistant::run()
// ------------------------------------------------------------
// Starts the main user-interface loop.
//
// UX = User Experience.
//
// This function is responsible for making the terminal assistant
// comfortable to use. It should handle things such as:
//   - startup information
//   - prompts
//   - blank input
//   - exit behavior
//   - displaying results
//
// It should NOT contain the implementation of every tool.
// Tool execution belongs to ToolManager and the individual tools.
void Assistant::run()
{
    // std::string is a standard-library class used to represent text.
    // We reuse this variable for every line entered by the user.
    std::string command;

    // --------------------------------------------------------
    // STARTUP UI
    // --------------------------------------------------------
    // A clear startup screen makes it immediately obvious that
    // the program is ready for interaction.
    std::cout << "\n";
    std::cout << "==================================================\n";
    std::cout << "              LOCAL ASSISTANT                    \n";
    std::cout << "==================================================\n";
    std::cout << " Local C++ assistant | Core v0.2                 \n";
    std::cout << " Type 'help' for commands or 'exit' to quit.     \n";
    std::cout << "==================================================\n\n";

    // --------------------------------------------------------
    // MAIN INTERACTION LOOP
    // --------------------------------------------------------
    // while(true) creates a loop that continues indefinitely.
    //
    // We intentionally stop it with 'break' when:
    //   1. the user enters exit, or
    //   2. terminal input is closed (EOF/error).
    while (true)
    {
        // The prompt tells the user whose turn it is.
        std::cout << "You > ";

        // ----------------------------------------------------
        // getline()
        // ----------------------------------------------------
        // std::getline() reads a complete line from std::cin.
        //
        // Unlike operator>> for a string, getline() keeps spaces.
        // That is important for commands such as:
        //
        //     write notes.txt | hello world
        //
        // The function returns false if input is closed or fails.
        if (!std::getline(std::cin, command))
        {
            std::cout << "\nAssistant > Input closed. Goodbye.\n";
            break;
        }

        // ----------------------------------------------------
        // BLANK INPUT
        // ----------------------------------------------------
        // empty() is a std::string member function.
        // It returns true when the string contains no characters.
        //
        // Ignoring blank lines prevents unnecessary error messages
        // and makes the interface feel less strict.
        if (command.empty())
        {
            continue;
            // continue immediately starts the next loop iteration.
        }

        // ----------------------------------------------------
        // EXIT COMMAND
        // ----------------------------------------------------
        // == compares two strings for exact equality.
        //
        // Exit is handled here because closing the interaction loop
        // is an Assistant/UI responsibility, not a tool operation.
        if (command == "exit")
        {
            std::cout << "Assistant > Goodbye.\n";
            break;
        }

        // ----------------------------------------------------
        // COMMAND PROCESSING
        // ----------------------------------------------------
        // Assistant is the UI/controller layer.
        //
        // It passes the user's command to the next layer instead
        // of knowing how every command is implemented.
        processCommand(command);
    }
}

// ------------------------------------------------------------
// Assistant::processCommand()
// ------------------------------------------------------------
// Receives one command and sends it to ToolManager.
//
// Architecture:
//
//     User input
//         ↓
//     Assistant
//         ↓
//     ToolManager
//         ↓
//     Specific Tool
//         ↓
//     Result
//         ↓
//     Assistant
//         ↓
//     User
//
// This separation is an example of separation of concerns:
// each component has a focused responsibility.
void Assistant::processCommand(const std::string& command)
{
    // ToolManager::execute() returns a std::string containing the
    // result produced by the selected tool or an error message.
    const std::string result = toolManager.execute(command);

    // Print the result with a separate Assistant prompt so the
    // conversation is easier to scan visually.
    std::cout << "Assistant > " << result << "\n\n";
}
