# Set minimum cmake version
cmake_minimum_required(VERSION 3.15)
# Set a variable that contains the project name (will be used multiple times below)
set(PROJECT_NAME osfes_umlcpp_07_inheritance)
# Set project name and language definition
project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)
# Include CMake module that fetches external dependencies
include(FetchContent)
# Make it fetch goole test library
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/main.zip FIND_PACKAGE_ARGS NAMES GTest DOWNLOAD_EXTRACT_TIMESTAMP false)
FetchContent_MakeAvailable(googletest)
# Include CMake tools for testing
include(CTest)
enable_testing()
# Define the executable and the source files required to build it
add_executable(${PROJECT_NAME} test/test.cpp)
# Set C++ language standard
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
# Define where to look for include files
target_include_directories(${PROJECT_NAME} PRIVATE todo)
# Make the executable link with google test
target_link_libraries(${PROJECT_NAME} PRIVATE gtest_main)
# Make the CTest discover the gtest test cases in this executable
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
