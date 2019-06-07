cmake_minimum_required(VERSION 2.8.9)

project (fprint)
include_directories(/usr/include/python3.5m)
include_directories(include)
file(GLOB SOURCES "src/*.cpp")

#判断编译器类型,如果是gcc编译器,则在编译选项中加入c++11支持 
if(CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-std=c++11)
    message(STATUS "optional:-std=c++11")   
endif(CMAKE_COMPILER_IS_GNUCXX)
add_executable(fprint  ${SOURCES})


target_link_libraries(fprint python3.5m)
