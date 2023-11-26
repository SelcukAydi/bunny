cmake_minimum_required(VERSION 3.2)

project(bunny VERSION 1.0.0
                    DESCRIPTION "A header-only backward compatible C++ serialization library." 
                    LANGUAGES CXX)

SET(WARNING_FLAGS "-Wno-unused-variable -Wno-unused-parameter")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNING_FLAGS} -std=c++17")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_INSTALL_PREFIX "/usr/local/lib/")

# This is a local setting and needs to be removed.
list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/boost/lib/cmake/" "/usr/local/lib/protobuf/lib/cmake/")

option(ENABLE_BUNNY_TEST "Enables the bunny test cases." OFF)
option(ENABLE_BUNNY_BENCHMARKING "Enables the benchmarking test cases." OFF)

add_compile_options(-Wall -Wextra -Wpedantic)

file(GLOB SRC_FILES
     "include/*.hpp"
)

include(GNUInstallDirs)

include_directories(include)

if(${ENABLE_BUNNY_TEST})
     add_subdirectory(test)
endif()

if(${ENABLE_BUNNY_BENCHMARKING})
     add_subdirectory(benchmarking)
endif()

add_library(${PROJECT_NAME} INTERFACE ${SRC_FILES})

target_include_directories(${PROJECT_NAME}
                              INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                              $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)


install(TARGETS ${PROJECT_NAME}
                    EXPORT ${PROJECT_NAME}_Targets
                    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
                    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
                    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

include(CMakePackageConfigHelpers)
write_basic_package_version_file("bunnyConfigVersion.cmake"
                                 VERSION ${PROJECT_VERSION}
                                 COMPATIBILITY SameMajorVersion)

configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION
  ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(EXPORT ${PROJECT_NAME}_Targets
     FILE ${PROJECT_NAME}Targets.cmake
     NAMESPACE ${PROJECT_NAME}::
     DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
          "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
     DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION bunny)
