cmake_minimum_required(VERSION 3.6)
project(engine)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/window.cpp src/window.h src/scene.h src/scene.cpp src/shapes.h src/vector.h)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/engine)

add_library(engine STATIC ${SOURCE_FILES})

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(BUILD_STATIC_LIBS ON CACHE BOOL "" FORCE)
set(BUILD_TESTS OFF CACHE BOOL "" FORCE)

add_subdirectory(deps/tinyxml2)

target_link_libraries(engine LINK_PUBLIC tinyxml2_static)
target_include_directories(engine PUBLIC ${CMAKE_SOURCE_DIR}/deps/tinyxml2)

add_subdirectory(chess)
