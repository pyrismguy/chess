cmake_minimum_required(VERSION 3.6)
project(engine)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/window.cpp
        src/window.h
        src/scene.h
        src/scene.cpp
        src/shapes/shape.h
        src/vector.h
        src/ray.h
        src/ray.cpp
        src/stb_image_write.h
        src/objects/object.h
        src/objects/camera.cpp
        src/objects/camera.h src/renderer.cpp src/renderer.h src/image.h src/image.cpp src/shapes/sphere.cpp src/objects/object.cpp src/objects/transform.cpp src/objects/transform.h)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/engine)

add_library(engine STATIC ${SOURCE_FILES})

add_subdirectory(deps/glm)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
if (WIN32)
    set(SDL2_PATH ${CMAKE_SOURCE_DIR}/deps/SDL2/i686-w64-mingw32)
elseif(WIN64)
    set(SDL2_PATH ${CMAKE_SOURCE_DIR}/deps/SDL2/x86_64-w64-mingw32)
endif ()


find_package(SDL2 REQUIRED)

if(SDL2_FOUND)
    target_link_libraries(engine LINK_PRIVATE ${SDL2_LIBRARY})
    target_include_directories(engine PUBLIC ${SDL2_INCLUDE_DIR})
endif()

set(INCLUDE_DIR ${INCLUDE_DIR}
        ${CMAKE_SOURCE_DIR}/deps/glm
        ${CMAKE_SOURCE_DIR}/deps/stb
        ${CMAKE_SOURCE_DIR}/deps/rapidjson/include)

target_include_directories(engine PUBLIC ${INCLUDE_DIR})

add_subdirectory(chess)
