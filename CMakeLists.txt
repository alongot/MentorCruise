cmake_minimum_required(VERSION 3.10)
project(StackTests)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find Boost libraries
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# Add your test executable
add_executable(StackTests stack_test.cpp)

# Link Boost.Test
target_link_libraries(StackTests Boost::unit_test_framework)