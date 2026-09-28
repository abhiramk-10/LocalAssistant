#include "Task.h"

Task::Task(const std::string& description)
    : description(description), status(TaskStatus::Pending)
{
}

void Task::start()
{
    status = TaskStatus::Running;
}

void Task::complete()
{
    status = TaskStatus::Completed;
}

void Task::fail()
{
    status = TaskStatus::Failed;
}

bool Task::isCompleted() const
{
    return status == TaskStatus::Completed;
}

TaskStatus Task::getStatus() const
{
    return status;
}

std::string Task::getDescription() const
{
    return description;
}
