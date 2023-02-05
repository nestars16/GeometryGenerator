cmake_minimum_required(VERSION 3.25.1)

project(GeometryGenerator)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/out/build)
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/imgui-master)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp)
file(GLOB_RECURSE IMGUI ${IMGUI_DIR}/*.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${SRC_DIR}/glad.c ${IMGUI})

target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/libglfw3.a)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wshadow -Wnon-virtual-dtor 
  -Wcast-align -Wconversion -Wsign-conversion
-Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference
-Wuseless-cast)