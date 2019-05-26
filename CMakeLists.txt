cmake_minimum_required(VERSION 2.8.9)

project (fprint)
include_directories(/usr/include/python3.5m)
include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(fprint  ${SOURCES})

target_link_libraries(fprint python3.5m)
