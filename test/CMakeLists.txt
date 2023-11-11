cmake_minimum_required(VERSION 3.2)

project(bunny-test VERSION 3.7.1 LANGUAGES CXX)

find_package(GTest REQUIRED)

add_compile_options(-Wall -Wextra -Wpedantic)

file(GLOB SRC_FILES
     "src/*.cpp" 
     "include/*.hpp"
)


# include_directories(include)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE include ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread gtest_main)