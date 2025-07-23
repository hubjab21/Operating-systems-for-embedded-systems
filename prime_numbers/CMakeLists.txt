# Set minimum cmake version
cmake_minimum_required(VERSION 3.15)
# Set project name and language definition
project(prime_numbers VERSION 1.0 LANGUAGES CXX)
# Define the executable and the source files required to build it
add_executable(prime_numbers main.cpp)
# Set C++ language standard
target_compile_features(prime_numbers PRIVATE cxx_std_20)