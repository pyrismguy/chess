cmake_minimum_required(VERSION 3.6)   # CMake version check
project(chess)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

set(SOURCE_FILES main.cpp)            # Add main.cpp file of project root directory as source file
add_executable(chess ${SOURCE_FILES})       # Add executable target with source files listed in SOURCE_FILES variable

target_link_libraries(chess LINK_PUBLIC engine)
target_include_directories(chess PUBLIC ${INCLUDE_DIR})

configure_file(data/scene.xml ${PROJECT_BINARY_DIR}/data/scene.xml)