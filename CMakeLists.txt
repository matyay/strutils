cmake_minimum_required(VERSION 3.2)
project(strutils VERSION 0.1.0)

option(TESTS "Build and run tests" ON)

# =============================================================================

# Set compilation flags
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall -Wextra -Wno-unused-function")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -ffast-math -O3")

# =============================================================================
# The main library

include_directories(include)

file(GLOB SRCS src/*.cc)
add_library(strutils ${SRCS})
set_target_properties(strutils PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "lib")

# =============================================================================
# Build and run tests

if(TESTS)
    add_subdirectory(tests)
endif()

