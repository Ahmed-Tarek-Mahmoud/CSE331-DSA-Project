cmake_minimum_required(VERSION 3.10)
project(CSE331_DSA_Project)

# Option to choose the build type: GUI or CLI
option(BUILD_GUI "Build the GUI version" OFF)
option(BUILD_CLI "Build the CLI version" ON)

# Add common source files
set(COMMON_SOURCES
    
)

# Add subdirectories for GUI and CLI builds
if (BUILD_GUI)
    add_subdirectory(XML-EDITOR)
endif()

if (BUILD_CLI)
    add_subdirectory(cli)
endif()
