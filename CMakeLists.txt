cmake_minimum_required(VERSION 2.8...3.60)

message(STATUS "cpp bmp start")

project(transimg)

# 增加 include
include_directories(./src/core)

# 增加源文件
aux_source_directory(./src/core CORE_SRC)
message(STATUS "Compile files " ${CORE_SRC})

aux_source_directory(./src/test TEST_SRC)
message(STATUS "Compile files " ${TEST_SRC})

# 编译选项
ADD_COMPILE_OPTIONS(-std=c++11)

# 增加宏定义
add_definitions(-D UU)

# 生成程序
add_executable(Test ${CORE_SRC} ${TEST_SRC})
add_executable(Tool ${CORE_SRC} ./src/Tool.cpp)
add_executable(Draw ${CORE_SRC} ./src/Draw.cpp)
add_executable(CalcPi ${CORE_SRC} ./src/CalcPi.cpp)
add_executable(Freefall ${CORE_SRC} ./src/Freefall.cpp)
add_executable(CharDraw ${CORE_SRC} ./src/CharDraw.cpp)

message(STATUS "cpp bmp end")
