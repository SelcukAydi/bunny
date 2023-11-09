cmake_minimum_required(VERSION 3.2)

project(bunny VERSION 3.7.1 LANGUAGES CXX)

SET(WARNING_FLAGS "-Wno-unused-variable -Wno-unused-parameter")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNING_FLAGS} -std=c++17")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(GTest REQUIRED)

add_compile_options(-Wall -Wextra -Wpedantic)

file(GLOB SRC_FILES
     "src/*.cpp" 
     "include/*.hpp"
)

include_directories(include)

add_subdirectory(test)

add_executable(${PROJECT_NAME} ${SRC_FILES})
