cmake_minimum_required (VERSION 3.9) #最低要求的CMake版本
project(Leetcode) # 项目名称
set (CMAKE_CXX_STANDARD 17)
file(GLOB SRC_FILE *.cpp) # 建立变量SRC_FILE为目录下.c文件列表
add_executable (${PROJECT_NAME} ${SRC_FILE}) # 要求编译可执行文件