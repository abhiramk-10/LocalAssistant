cmake_minimum_required(VERSION 3.20)

project(LocalAssistant VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(LocalAssistant
    src/main.cpp
    src/Assistant.cpp
    tools/SystemTool.cpp
    tools/FileTool.cpp
)

target_include_directories(LocalAssistant PRIVATE
    src
    tools
)