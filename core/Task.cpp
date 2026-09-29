#include "Task.h"

// ------------------------------------------------------------
// Task constructor
// ------------------------------------------------------------
// A Task represents one unit of work the assistant wants to do.
//
// 'description' is the command/request associated with the task.
// A newly-created task always starts in the Pending state because
// it has not been executed yet.
Task::Task(const std::string& description)
    : description(description), status(TaskStatus::Pending)
{
}

// ------------------------------------------------------------
// start()
// ------------------------------------------------------------
// Changes the task state from Pending to Running.
// This tells the rest of the program that execution has started.
void Task::start()
{
    status = TaskStatus::Running;
}

// ------------------------------------------------------------
// complete()
// ------------------------------------------------------------
// Marks the task as successfully completed.
void Task::complete()
{
    status = TaskStatus::Completed;
}

// ------------------------------------------------------------
// fail()
// ------------------------------------------------------------
// Marks the task as failed when the requested operation could
// not be completed successfully.
void Task::fail()
{
    status = TaskStatus::Failed;
}

// ------------------------------------------------------------
// isCompleted()
// ------------------------------------------------------------
// Returns true only when the task reached the Completed state.
// 'const' means this function promises not to modify the Task.
bool Task::isCompleted() const
{
    return status == TaskStatus::Completed;
}

// ------------------------------------------------------------
// getStatus()
// ------------------------------------------------------------
// Gives other parts of the program access to the current state
// without allowing them to directly modify the private member.
TaskStatus Task::getStatus() const
{
    return status;
}

// ------------------------------------------------------------
// getDescription()
// ------------------------------------------------------------
// Returns the text describing what this task is supposed to do.
std::string Task::getDescription() const
{
    return description;
}
