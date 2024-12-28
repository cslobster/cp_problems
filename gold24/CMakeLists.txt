cmake_minimum_required(VERSION 3.28)
project(gold24)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp)
add_executable(p1 p1.cpp)
add_executable(p1_2 p1_2.cpp)
add_executable(p2 p2.cpp)
add_executable(p2_2 p2_2.cpp)
add_executable(p3 p3.cpp)
add_executable(p3_2 p3_2.cpp)
add_executable(p2_3 p2_3.cpp)
add_executable(test test.cpp)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -g")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")