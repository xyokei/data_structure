cmake_minimum_required(VERSION 3.25)
project(chapter5_tree)
set(CMAKE_CXX_STANDARD 17)

#递归遍历文件夹 用 GLOB_RECURSE
#遍历当前文件夹 SOURCE_FILES
file(GLOB_RECURSE SOURCE_FILES "*.cpp")
file(GLOB_RECURSE HEADER_FILES "*.h")
foreach(SOURCE_FILE ${SOURCE_FILES})
    # 将source_file的后缀名去掉 并保存到base_name
    string(REGEX REPLACE "\\.[^.]*$" "" BASE_NAME ${SOURCE_FILE})
    # 在header_files 文件中查找 同名文件且以.h结尾
    list(FIND HEADER_FILES "${BASE_NAME}.h" INDEX)
    # 获取文件路径的文件名 保存到 EXECUTABLE_NAME
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)
    #要是一一对应就放开，没有 可报错也可不报
#    if(INDEX EQUAL -1)
#        message(FATAL_ERROR "没有找到与 ${BASE_NAME}.h 同名的头文件")
#    endif()

    # 添加源文件和对应的头文件到你的目标
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE} ${HEADER_FILES})
endforeach()