//
// Created by piotr on 15.10.19.
//

#ifndef GOMOKU_MAINMENU_H
#define GOMOKU_MAINMENU_H


#include "Menu.h"
#include "../classes/Menu.cpp"

/**
 * Main Menu class. Allows users to choose between: starting new game,
 * continue last game, or see rankings
 */
class MainMenu: public Menu {
private:
    int option;
    /**
     * Here used as New Game option
     */
    void option1() override;

    /**
     * Here used as Continue option
     */
    void option2() override;

    /**
     * Here used as See Ranking option
     */
    void option3() override;

    /**
     * Never used here
     */
    void option4() override;

public:
    MainMenu();

    /**
     * Displays menu, and collects input
     */
    void chooseOption() override;

    /**
     * Execute option chosen by user
     */
    void executeOption() override;

    void isNumber(std::string text);
};


#endif //GOMOKU_MAINMENU_H
