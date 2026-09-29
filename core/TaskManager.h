#pragma once
// Prevents duplicate inclusion of this header.

#include "Task.h"
// TaskManager stores and works with Task objects.

#include "../tools/ToolManager.h"
// TaskManager sends task commands to ToolManager for execution.

#include <vector>
// std::vector is a dynamic array from the C++ Standard Library.
// We use it to store any number of Task objects.

// ------------------------------------------------------------
// class TaskManager
// ------------------------------------------------------------
// TaskManager is responsible for storing tasks and controlling
// their execution lifecycle.
class TaskManager
{
public:
    // Adds a Task to the internal vector.
    // const Task& avoids copying the input unnecessarily and
    // prevents this function from modifying the caller's Task.
    void addTask(const Task& task);

    // Returns a pointer to a Task at the requested index.
    // nullptr is returned when the index is invalid.
    Task* getTask(int index);

    // Returns the number of stored tasks.
    // const means asking for the count does not modify the manager.
    int getTaskCount() const;

    // Finds and executes one task using ToolManager.
    void executeTask(int index);

private:
    // std::vector<Task> is a dynamic collection of Task objects.
    // Unlike a fixed-size array, it can grow as tasks are added.
    std::vector<Task> tasks;

    // Composition: TaskManager "has a" ToolManager object.
    // This allows it to delegate actual operations to tools.
    ToolManager toolManager;
};
