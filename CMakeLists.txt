cmake_minimum_required(VERSION 4.0)
project(DataAndAlogorithm)
add_compile_options("$<$<C_COMPILER_ID:GNU>:-fexec-charset=GBK>")
add_compile_options("$<$<CXX_COMPILER_ID:GNU>:-fexec-charset=GBK>")
set(CMAKE_CXX_STANDARD 20)

add_executable(DataAndAlogorithm main.cpp)
