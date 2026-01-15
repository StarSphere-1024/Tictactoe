cmake_minimum_required(VERSION 3.10)   # 指定最低 CMake 版本
project(Tictactoe VERSION 1.0)          # 定义项目名称和版本

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(queue 
   ${CMAKE_SOURCE_DIR}/lib/queue/queue.c
)

# 指定库的头文件
target_include_directories(queue PUBLIC ${CMAKE_SOURCE_DIR}/lib/queue)

include_directories(${CMAKE_SOURCE_DIR}/include)

aux_source_directory(${CMAKE_SOURCE_DIR}/Src SRC_LIST)

# 创建可执行文件目标
add_executable(Tictactoe ${SRC_LIST})

# 链接库到可执行文件
target_link_libraries(Tictactoe PRIVATE queue)