cmake_minimum_required(VERSION 2.8.9)

project (fprint)

include_directories(/usr/include/python3.5m)
include_directories(include)
file(GLOB SOURCES "src/*.cpp")

#查找当前目录下的所有源文件
#并将名称保存到DIR_SRCS变量中
aux_source_directory(. DIR_SRCS)
#为源文件的编译添加选项
ADD_DEFINITIONS(-g -W -Wall -o2))
#增加源文件编译选项
add_compile_options(-std=c++11)

#得出可执行文件
add_executable(fprint  ${SOURCES})
#link libray in static mode
target_link_libraries(fprint python3.5m)
