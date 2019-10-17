//
// Created by piotr on 15.10.19.
//

#ifndef GOMOKU_DRAWERCLASSIC_H
#define GOMOKU_DRAWERCLASSIC_H


#include "Drawer.h"

/**
 * Is implementation of Drawer.
 * In this version player1 is X and player2 is O.
 */
class DrawerClassic: public Drawer {
private:
    const std::string XMark = "X";
    const std::string OMark = "O";
    const std::string EmptyMark = " ";
public:
    virtual void draw(Board board) override;

};


#endif //GOMOKU_DRAWERCLASSIC_H
