# LocalAssistant

A **from-scratch C++ personal assistant/agent project** built as a long-term learning project.

The goal is not to immediately create a perfect AI. The goal is to understand and build the pieces that make an assistant work: input handling, reasoning, tasks, tools, execution, memory, and eventually local AI.

> **Important:** The current Brain is a rule-based intent engine. It is not an LLM and does not pretend to be one.

## What are we building?

```text
User
  │
  ▼
Assistant
  │
  ▼
Brain / Understanding
  │
  ▼
Planner / Task Manager
  │
  ▼
Tool Manager
  │
  ├── System Tool
  ├── File Tool
  └── Future Tools
  │
  ▼
Computer / Environment
```

The long-term goal is a local assistant that can understand a request, decide what needs to happen, create tasks, use appropriate tools, observe results, and continue working without requiring a cloud API for every operation.

## Current capabilities

- C++ console interaction
- System information tools
- File-related tools
- Tool management
- Task objects and lifecycle management
- First rule-based Brain
- CMake builds
- Small standalone tests for core components

The current Brain recognizes commands such as:

```text
help / commands
time / what time is it / current time
date / today
system / system info / system information
computer / computer name
list / list files / show files
```

This is intentionally simple. We will make the Brain more capable step by step.

## Project structure

```text
LocalAssistant/
├── core/
│   ├── Brain.h
│   ├── Brain.cpp
│   ├── Task.h
│   ├── Task.cpp
│   ├── TaskManager.h
│   └── TaskManager.cpp
├── tools/
│   ├── ToolManager.*
│   ├── SystemTool.*
│   └── FileTool.*
├── src/
│   ├── main.cpp
│   └── Assistant.cpp
├── tests/
│   ├── TaskTest.cpp
│   └── TaskManagerTest.cpp
├── CMakeLists.txt
└── README.md
```

## How the pieces work

### Task

A `Task` represents one unit of work.

```text
Pending
   │ start()
   ▼
Running
   │
   ├── complete() ──► Completed
   └── fail() ──────► Failed
```

It teaches `class`, `enum class`, constructors, member functions, access control, encapsulation, `const`, references, and object state.

### TaskManager

`TaskManager` stores and manages multiple tasks.

```text
TaskManager
   ├── Task 1
   ├── Task 2
   └── Task 3
```

It teaches `std::vector`, pointers, `nullptr`, indexing, object lifetime, references, and class composition.

### ToolManager

`ToolManager` connects an internal command to the correct tool.

```text
"time" → ToolManager → SystemTool → actual operation
```

The Brain does not need to know how Windows APIs or file operations work. This separation keeps responsibilities clear.

### Tools

Tools perform real operations.

```text
SystemTool → computer/system information
FileTool   → directory/file operations
```

Future tools could include process, network, browser, robot, camera, or database tools.

## The Brain

The Brain is the interpretation layer.

```text
User input
     │
     ▼
normalize input
     │
     ▼
recognize intent
     │
     ▼
BrainDecision
     │
     ├── understood
     ├── command
     └── message
```

Example:

```text
User: What time is it?

Brain:
understood = true
command = "time"
```

The ToolManager can then execute the internal command.

The Brain is deliberately rule-based at this stage. That lets us understand the architecture before introducing a local language model.

## Learning path

This repository is also a **C++ learning course built around a real project**. Do not try to understand everything at once.

### Level 1 — C++ fundamentals

Learn:

- variables and data types
- `if` / `else`
- loops
- functions
- arrays
- strings
- input/output

### Level 2 — Memory and types

Learn:

- references
- pointers
- `nullptr`
- stack vs heap
- `const`
- type conversion
- `static_cast`

### Level 3 — Object-oriented C++

Learn:

- classes and objects
- constructors/destructors
- public/private
- encapsulation
- composition
- inheritance

### Level 4 — Standard Library

Learn:

- `std::string`
- `std::vector`
- algorithms
- iterators
- `std::size_t`
- smart pointers

### Level 5 — Architecture

Study this flow until you can explain why every layer exists:

```text
Task
  ↓
TaskManager
  ↓
ToolManager
  ↓
Tools
```

### Level 6 — Brain

Start with normalization, command recognition, intent classification, structured decisions, and command parsing.

Then move toward entities, context, multi-step planning, conversation state, and memory.

### Level 7 — Concurrency

Learn `std::thread`, mutexes, locks, condition variables, futures, and asynchronous tasks.

This will matter when the assistant needs to perform multiple operations concurrently.

### Level 8 — Local AI

Only after the architecture is understood, investigate local inference and model integration.

Remember:

```text
AI model ≠ entire assistant
```

A model can help with understanding and planning, while the C++ application remains responsible for tools, permissions, state, execution, and safety.

## How to study the code

For every `.h` and `.cpp` file, ask:

1. What is this?
2. Why does it exist?
3. What C++ concept is being used?
4. What does every important keyword or symbol mean?
5. What data enters the function?
6. What does the function return or change?
7. Who calls it?
8. What calls happen next?
9. What happens when something fails?
10. Could I rewrite this part myself?

The source code is intentionally commented to explain not only what the code does, but also the C++ concepts and syntax used to implement it.

## Build on Windows

From the project directory:

```cmd
cmake -S . -B build
cmake --build build
```

Run:

```cmd
build\LocalAssistant.exe
```

If the build directory was created on another machine/environment, delete it first because CMake caches absolute paths:

```cmd
rmdir /s /q build
cmake -S . -B build
cmake --build build
```

## Running tests

Task test:

```cmd
g++ -std=c++17 -Wall -Wextra -Wpedantic tests\TaskTest.cpp core\Task.cpp -o TaskTest.exe
TaskTest.exe
```

Task manager test:

```cmd
g++ -std=c++17 -Wall -Wextra -Wpedantic tests\TaskManagerTest.cpp core\Task.cpp core\TaskManager.cpp tools\ToolManager.cpp tools\SystemTool.cpp tools\FileTool.cpp -o TaskManagerTest.exe
TaskManagerTest.exe
```

## Development philosophy

### Understand before abstracting

Do not add a framework just because it is convenient. Understand the C++ underneath it first.

### One responsibility per component

```text
Brain       → understand
Task        → represent work
TaskManager → manage work
ToolManager → select/dispatch tools
Tool        → perform work
```

### Build incrementally

Every major feature should have a small test before it becomes part of the complete assistant.

### Prefer explicit code while learning

Readable code is more valuable than clever code at this stage.

### Keep the Brain separate from execution

The Brain should produce decisions. Controlled application components and tools should perform the operations.

## Long-term roadmap

```text
[Current]
Rule-based Assistant
        ↓
Better intent recognition
        ↓
Command parser
        ↓
Task planning
        ↓
Multi-step tasks
        ↓
Context
        ↓
Memory
        ↓
Local language model
        ↓
AI-assisted tool selection
        ↓
Planning + execution loop
        ↓
Observation / feedback
        ↓
More autonomous local assistant
```

The architecture will evolve as we learn. Each layer should be tested instead of assuming the final design in advance.

## Why build it from scratch?

The purpose is educational as much as functional. A ready-made assistant API can produce a result quickly, but it can hide important engineering concepts.

Building this ourselves lets us learn:

```text
C++
 ↓
Software architecture
 ↓
Operating-system interaction
 ↓
Concurrency
 ↓
Task systems
 ↓
Planning
 ↓
Memory
 ↓
AI integration
```

The goal is not simply to make a chatbot. The goal is to understand how the different pieces can be engineered into a real assistant.

## Status

**Current stage:** Core task system + tool architecture + first rule-based Brain.

**Next major stage:** Connect the Brain to the Assistant and TaskManager, then improve intent parsing and task planning.
