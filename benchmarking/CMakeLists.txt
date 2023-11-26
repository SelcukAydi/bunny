cmake_minimum_required(VERSION 3.2)

project(bunny-benchmark VERSION 3.7.1 LANGUAGES CXX)

set(benchmark_DIR "${CMAKE_CURRENT_SOURCE_DIR}/benchmark")
set(BENCHMARK_ENABLE_GTEST_TESTS OFF)

find_package(Boost REQUIRED COMPONENTS serialization)
find_package(absl REQUIRED)
find_package(utf8_range REQUIRED)
find_package(protobuf REQUIRED)

add_compile_options(-Wall -Wextra -Wpedantic)

file(GLOB SRC_FILES
     "src/*.cpp" 
     "src/*.cc"
)

add_subdirectory(benchmark)

link_directories(/usr/local/lib/abseil/lib ${Protobuf_LIBRARIES})

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE 
                         include 
                         ${CMAKE_CURRENT_SOURCE_DIR}/include 
                         ${Boost_INCLUDE_DIRS}
                         benchmark/include
                         ${Protobuf_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} 
                    pthread 
                    gtest_main 
                    Boost::serialization 
                    benchmark::benchmark
                    protobuf::libprotobuf 
                    protobuf::libprotoc
)