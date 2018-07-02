cmake_minimum_required(VERSION 3.10)
project(Mario)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 17)

include_directories(srcs/includes)
include_directories(srcs/includes/Graphical)

file(GLOB_RECURSE INCLUDES_1 srcs/includes/*.hpp)
file(GLOB_RECURSE INCLUDES_2 srcs/includes/*.h)
file(GLOB_RECURSE SOURCES srcs/srcs/*.cpp)

add_executable(Mario
        ${INCLUDES_1}
        ${INCLUDES_2}
        ${SOURCES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Mario ${SFML_LIBRARIES})
endif ()