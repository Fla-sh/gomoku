//
// Created by piotr on 15.10.19.
//

#ifndef GOMOKU_MAINMENU_H
#define GOMOKU_MAINMENU_H


#include "Menu.h"
#include "../classes/Menu.cpp"

class MainMenu: public Menu::Menu {
private:
    int option;
    void option1() override;
    void option2() override;
    void option3() override;
    void option4() override;

public:
    MainMenu();
    void chooseOption() override;
    void executeOption() override;
};


#endif //GOMOKU_MAINMENU_H
