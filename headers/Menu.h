//
// Created by piotr on 14.10.19.
//

#ifndef GOMOKU_MENU_H
#define GOMOKU_MENU_H


class Menu {
private:
    int option;
    void newGame();
    void continueGame();

public:
    Menu();
    void chooseOption();
};


#endif //GOMOKU_MENU_H
