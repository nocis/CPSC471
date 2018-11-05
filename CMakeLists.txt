# Set minimum require cmake version.
cmake_minimum_required (VERSION 3.1)

# Give the project a name.
project (Project)

# The version number.
set (PROJECT_VERSION_MAJOR 0)
set (PROJECT_VERSION_MINOR 1)
set (PROJECT_VERSION_PATCH 0)
message("-- Version is set to ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
set (CMAKE_CXX_STANDARD 17)

# #############################################################################

# Use ccache if it is found
find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("-- Debug mode: ccache found, using ccache")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif()

# Special options for compilers
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    # using Clang
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 5)
        message(FATAL_ERROR "Clang must be at least version 5")
    endif()
    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        set (CMAKE_CXX_FLAGS_RELEASE "-Ofast")
    endif()
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    # using GCC
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 7)
        message(FATAL_ERROR "GCC must be at least version 7")
    endif()
    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        set (CMAKE_CXX_FLAGS_RELEASE "-O3")
    endif()
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
    # using Intel C++
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    # using Visual Studio C++
endif()

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/config.hpp.in"
  "${PROJECT_BINARY_DIR}/config.hpp"
  )

# Use thread library
set(CMAKE_THREAD_PREFER_PTHREAD ON)
find_package(Threads REQUIRED)

# Add includes path.
include_directories("${PROJECT_BINARY_DIR}")

# Add an executable.
add_executable(${CMAKE_PROJECT_NAME} template.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} Threads::Threads)

# Set install destination target
install (TARGETS ${CMAKE_PROJECT_NAME} DESTINATION bin)
