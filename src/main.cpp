#include "Assistant.h"
// Includes the Assistant class declaration so main() can create
// and start an Assistant object.

// ------------------------------------------------------------
// main()
// ------------------------------------------------------------
// main() is the entry point of a C++ program.
// When Windows starts LocalAssistant.exe, execution begins here.
int main()
{
    // Create an Assistant object.
    // The object's lifetime begins here and ends when main() ends.
    Assistant assistant;

    // Call the Assistant's run() member function.
    // This starts the main interaction loop with the user.
    assistant.run();

    // Return 0 tells the operating system that the program
    // finished successfully.
    return 0;
}
