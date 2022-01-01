cmake_minimum_required(VERSION 3.3.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(StreamerUtils)


if(NOT EXISTS ${PROJECT_BINARY_DIR}/.gitignore)
  file(WRITE ${PROJECT_BINARY_DIR}/.gitignore "*")
endif()

file(
    GLOB_RECURSE SOURCE_FILES
    src/*.cpp
    libraries/minhook/src/*.c
)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

add_subdirectory(libraries/cocos-headers)

target_include_directories(${PROJECT_NAME} PRIVATE
    libraries/gd.h/include
    libraries/gd.h
    libraries/mat-dash/include
    libraries/minhook/include
    include
)

target_link_libraries(${PROJECT_NAME}
    cocos2d
)

set_target_properties(${PROJECT_NAME} PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY_DEBUG "D:\\Steam\\steamapps\\common\\Geometry Dash\\adaf-dll"
                      RUNTIME_OUTPUT_DIRECTORY_RELEASE "D:\\Steam\\steamapps\\common\\Geometry Dash\\adaf-dll"
)

add_custom_command(TARGET ${PROJECT_NAME}
    PRE_BUILD
    COMMAND taskkill /f /fi "pid gt 0" /im GeometryDash.exe
)