#pragma once
// Prevents this header from being included more than once.

#include <string>
// std::string is the C++ standard-library type used for text.

// ------------------------------------------------------------
// struct BrainDecision
// ------------------------------------------------------------
// A struct groups related data into one object.
// The Brain needs to return three related pieces of information:
//   1. whether it understood the request
//   2. which internal command was recognized
//   3. a message describing the decision
//
// A struct lets us return all three values together.
struct BrainDecision
{
    bool understood;     // true when the Brain recognized the request.
    std::string command; // Internal command for the execution layer.
    std::string message; // Human-readable explanation of the decision.
};

// ------------------------------------------------------------
// class Brain
// ------------------------------------------------------------
// A class groups data and behavior into one user-defined type.
// Brain is the interpretation layer of LocalAssistant.
//
// The current implementation is deliberately rule-based. This
// gives us a simple, deterministic foundation before we introduce
// more advanced local language understanding.
class Brain
{
public:
    // --------------------------------------------------------
    // think()
    // --------------------------------------------------------
    // Receives user text and returns a structured BrainDecision.
    //
    // const std::string&:
    //     const -> input will not be modified
    //     &     -> avoid copying the string
    //
    // The final const means this member function does not modify
    // the Brain object itself.
    BrainDecision think(const std::string& input) const;
};
