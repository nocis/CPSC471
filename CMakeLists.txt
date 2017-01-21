# Set minimum require cmake version.
cmake_minimum_required (VERSION 2.6)

# Give the project a name.
project (Template)

# The version number.
set (PROJECT_VERSION_MAJOR 1)
set (PROJECT_VERSION_MINOR 0)

# #############################################################################

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/config.ipp"
  "${PROJECT_BINARY_DIR}/config.hpp"
  )

# Add includes path.
include_directories("${PROJECT_BINARY_DIR}")

# Add an executable.
add_executable(Template template.cpp)
