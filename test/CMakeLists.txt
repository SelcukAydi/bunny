cmake_minimum_required(VERSION 3.2)

project(bunny-test VERSION 3.7.1 LANGUAGES CXX)

set(Boost_NO_BOOST_CMAKE TRUE)
set(BOOST_ROOT "/usr/local/lib/boost")
set(Boost_INCLUDE_DIR "/usr/local/lib/boost/include")
set(benchmark_DIR "${CMAKE_CURRENT_SOURCE_DIR}/benchmark")
set(BENCHMARK_ENABLE_GTEST_TESTS OFF)

find_package(GTest REQUIRED)
find_package(Boost REQUIRED COMPONENTS serialization)

add_compile_options(-Wall -Wextra -Wpedantic)

file(GLOB SRC_FILES
     "src/*.cpp" 
     "include/*.hpp"
)

add_subdirectory(benchmark)

# include_directories(include)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE include ${CMAKE_CURRENT_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS} benchmark/include)
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread gtest_main Boost::serialization benchmark::benchmark)