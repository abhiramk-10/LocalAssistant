#pragma once

#include "Task.h"
#include "../tools/ToolManager.h"

#include <vector>

class TaskManager
{
public:
    void addTask(const Task& task);
    Task* getTask(int index);
    int getTaskCount() const;
    void executeTask(int index);

private:
    std::vector<Task> tasks;
    ToolManager toolManager;
};
