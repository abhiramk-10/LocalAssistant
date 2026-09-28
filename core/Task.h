#pragma once

#include <string>

enum class TaskStatus
{
    Pending,
    Running,
    Completed,
    Failed
};

class Task
{
public:
    explicit Task(const std::string& description);

    void start();
    void complete();
    void fail();

    bool isCompleted() const;
    TaskStatus getStatus() const;
    std::string getDescription() const;

private:
    std::string description;
    TaskStatus status;
};
