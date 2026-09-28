#include "TaskManager.h"

void TaskManager::addTask(const Task& task)
{
    tasks.push_back(task);
}

Task* TaskManager::getTask(int index)
{
    if (index < 0 || index >= static_cast<int>(tasks.size()))
    {
        return nullptr;
    }

    return &tasks[static_cast<std::size_t>(index)];
}

int TaskManager::getTaskCount() const
{
    return static_cast<int>(tasks.size());
}

void TaskManager::executeTask(int index)
{
    Task* task = getTask(index);

    if (task == nullptr)
    {
        return;
    }

    task->start();

    const std::string result = toolManager.execute(task->getDescription());

    if (result.rfind("Unknown command:", 0) == 0 ||
        result.rfind("Usage:", 0) == 0 ||
        result.rfind("Error:", 0) == 0)
    {
        task->fail();
        return;
    }

    task->complete();
}
