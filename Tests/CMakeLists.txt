cmake_minimum_required(VERSION 3.10)
project(DataStructureTests)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find Boost libraries
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# List of test source files
set(TEST_FILES
    singly_linked_list_test.cpp
    stack_test.cpp
    queue_test.cpp
)

# Loop over each test file to create an executable
foreach(test_file ${TEST_FILES})
    get_filename_component(test_name ${test_file} NAME_WE)
    add_executable(${test_name} ${test_file})
    target_link_libraries(${test_name} Boost::unit_test_framework)
endforeach()
