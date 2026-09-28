cmake_minimum_required(VERSION 3.20)

project(LocalAssistant VERSION 0.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(LocalAssistant
    src/main.cpp
    src/Assistant.cpp
    tools/SystemTool.cpp
    tools/FileTool.cpp
    tools/ToolManager.cpp
)

target_include_directories(LocalAssistant PRIVATE
    src
    tools
)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(LocalAssistant PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()
