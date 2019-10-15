//
// Created by piotr on 14.10.19.
//

#include "../headers/Gomoku.h"
#include "../headers/Menu.h"
#include "../headers/MainMenu.h"

Gomoku::Gomoku() {
    while(true) {
        Menu *menu = new MainMenu();
        menu->chooseOption();
        menu->executeOption();
    }
}
