cmake_minimum_required(VERSION 3.12)
project(gomoku)

set(CMAKE_CXX_STANDARD 14)

add_executable(gomoku main.cpp classes/Logger.cpp headers/Logger.h classes/MainMenu.cpp headers/MainMenu.h classes/Drawer.cpp headers/Drawer.h classes/Board.cpp headers/Board.h classes/DrawerClassic.cpp headers/DrawerClassic.h classes/GameLoop.cpp headers/GameLoop.h)