cmake_minimum_required(VERSION 3.0)
project(webserver)

# 配置编译选项
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

# 配置最终的可执行文件输出的路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 配置头文件的搜索路径
include_directories(${PROJECT_SOURCE_DIR}/code)
include_directories(${PROJECT_SOURCE_DIR}/code/buffer)
include_directories(${PROJECT_SOURCE_DIR}/code/config)
include_directories(${PROJECT_SOURCE_DIR}/code/http)
include_directories(${PROJECT_SOURCE_DIR}/code/kafka)
include_directories(${PROJECT_SOURCE_DIR}/code/log)
include_directories(${PROJECT_SOURCE_DIR}/code/pool)
include_directories(${PROJECT_SOURCE_DIR}/code/server)
include_directories(${PROJECT_SOURCE_DIR}/code/timer)


# 加载子目录
add_subdirectory(code)