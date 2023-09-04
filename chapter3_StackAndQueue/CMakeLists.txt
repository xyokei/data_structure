cmake_minimum_required(VERSION 3.25)
project(chapter3_StackAndQueue)

set(CMAKE_CXX_STANDARD 17)
include_directories("../tools/stack") #文件绝对路径 和相对路径
include_directories("../tools/queue") #文件绝对路径 和相对路径

#递归遍历文件夹 用 GLOB_RECURSE
#遍历当前文件夹 SOURCE_FILES
file(GLOB_RECURSE SOURCE_FILES *.cpp)
foreach(A_CPP_FILE ${SOURCE_FILES})
    get_filename_component(EXECUTABLE_NAME ${A_CPP_FILE} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${A_CPP_FILE})
endforeach(A_CPP_FILE ${SOURCE_FILES})