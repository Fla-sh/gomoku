//
// Created by piotr on 15.10.19.
//

#ifndef GOMOKU_DRAWER_H
#define GOMOKU_DRAWER_H


#include <string>
#include "Board.h"

/**
 * Drawer class represents in console current Board state. Drawer is an abstract class which is implemented
 * in its subclass
 * @see DrawerClassic
 * @see DrawerAlternative
 * @see DrawerMess
 */
class Drawer {
private:
    const std::string XMark;
    const std::string OMark;
    const std::string EmptyMark;
public:
    /**
     * Draws Board on screen
     * @param board board which should be drawn
     */
    virtual void draw(Board board) = 0;
};


#endif //GOMOKU_DRAWER_H
