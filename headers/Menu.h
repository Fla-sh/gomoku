//
// Created by piotr on 14.10.19.
//

#ifndef GOMOKU_MENU_H
#define GOMOKU_MENU_H

/**
 * Abstract class for menu creation. Each menu can have up to 4 options.
 * Process of collecting response, and executing it is separated into
 * two different funcitons
 * @see MainMenu
 */
class Menu {
private:
    virtual void option1() = 0;
    virtual void option2() = 0;
    virtual void option3() = 0;
    virtual void option4() = 0;

public:
    //Menu();
    virtual void executeOption() = 0;
    virtual void chooseOption() = 0;
};


#endif //GOMOKU_MENU_H
