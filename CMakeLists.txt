cmake_minimum_required(VERSION 3.15)
project(compiladores C)

set(CMAKE_C_STANDARD 99)

add_executable(compiladores exp.c lexer.c lexer.h)