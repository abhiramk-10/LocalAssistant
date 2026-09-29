#pragma once

#include <string> // Provides std::string for storing text.

// ------------------------------------------------------------
// enum class: TaskStatus
// ------------------------------------------------------------
// An enum class defines a fixed set of named values.
// Here it represents the lifecycle/state of a Task.
//
// Using names such as TaskStatus::Running is clearer than using
// unexplained numbers such as 0, 1, 2, or 3.
enum class TaskStatus
{
    Pending,   // Created, but execution has not started.
    Running,   // Currently being executed.
    Completed, // Finished successfully.
    Failed     // Execution could not be completed.
};

// ------------------------------------------------------------
// class Task
// ------------------------------------------------------------
// A class is a user-defined type that groups data and functions.
//
// A Task represents one unit of work for LocalAssistant.
// It stores what should be done and its current state.
class Task
{
public:
    // --------------------------------------------------------
    // Constructor
    // --------------------------------------------------------
    // A constructor runs automatically when an object is created.
    //
    // 'explicit' prevents C++ from silently converting a string
    // into a Task when that conversion was not intended.
    //
    // const std::string& means:
    //   const -> do not modify the supplied string
    //   &     -> use the existing string instead of copying it
    //   std::string -> C++ standard-library text type
    explicit Task(const std::string& description);

    // Member functions control the Task lifecycle.
    void start();
    void complete();
    void fail();

    // 'const' after a member function means the function promises
    // not to modify this Task object.
    bool isCompleted() const;
    TaskStatus getStatus() const;
    std::string getDescription() const;

private:
    // private members are directly accessible only by Task's own
    // member functions. This is called encapsulation.
    std::string description;
    TaskStatus status;
};
