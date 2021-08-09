cmake_minimum_required(VERSION 3.16)
project(JUCECMakeRepo)

#including CPM.cmake, a package manager:
#https://github.com/TheLartians/CPM.cmake
include(CMake/CPM.cmake)

#Compile commands, useful for some IDEs like VS-Code
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

#Minimum MacOS target, set globally
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.9" CACHE STRING "Minimum OS X deployment version" FORCE)

option(UniversalBinary "Build universal binary for mac" OFF)

if (UniversalBinary)
    set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64" CACHE INTERNAL "")
endif()

#static linking in Windows
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

#Adds all the module sources so they appear correctly in the IDE
set_property(GLOBAL PROPERTY USE_FOLDERS YES)
option(JUCE_ENABLE_MODULE_SOURCE_GROUPS "Enable Module Source Groups" ON)

#Fetching JUCE from git
#IF you want to instead point it to a local version, you can invoke CMake with
#-DCPM_JUCE_SOURCE="Path_To_JUCE"
CPMAddPackage(
        NAME JUCE
        GITHUB_REPOSITORY juce-framework/JUCE
        GIT_TAG origin/develop)

add_subdirectory(Modules)
add_subdirectory(Plugins)
