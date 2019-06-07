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

#查找当前目录下的所有源文件
#并将名称保存到DIR_SRCS变量中
aux_source_directory(. DIR_SRCS)
#为源文件的编译添加选项
ADD_DEFINITIONS(-g -W -Wall -o2))

#得出可执行文件
add_executable(fprint  ${SOURCES})
#link libray in static mode
target_link_libraries(fprint python3.5m)
