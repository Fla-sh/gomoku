//
// Created by piotr on 14.10.19.
//

#include "../headers/Gomoku.h"
#include "../headers/Menu.h"
#include "../classes/Menu.cpp"

Gomoku::Gomoku() {
    Menu menu;
    menu = Menu();
    menu.chooseOption();
}
