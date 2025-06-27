cmake_minimum_required(VERSION 4.0.0)
project(opengl)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 创建可执行文件
FILE(GLOB_RECURSE SRC_FILE "src/*.cpp" "src/*.c" "src/*.h")
add_executable(opengl ${SRC_FILE})

# 添加头文件路径
target_include_directories(opengl PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_directories(opengl PRIVATE
    ${PROJECT_SOURCE_DIR}/lib
)

target_link_libraries(opengl PRIVATE
    glfw3
)
