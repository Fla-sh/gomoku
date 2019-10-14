cmake_minimum_required(VERSION 3.12)
project(gomoku)

set(CMAKE_CXX_STANDARD 14)

add_executable(gomoku main.cpp classes/Logger.cpp headers/Logger.h)