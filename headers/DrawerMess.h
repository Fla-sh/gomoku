//
// Created by piotr on 15.10.19.
//

#ifndef GOMOKU_DRAWERMESS_H
#define GOMOKU_DRAWERMESS_H


#include <string>
#include "Board.h"
#include "Drawer.h"

/**
 * Is implementation of Drawer.
 * In this version player1 is X and player2 is O and empty fields are marked as dots.
 */
class DrawerMess: public Drawer {
private:
    const std::string XMark = "X";
    const std::string OMark = "O";
    const std::string EmptyMark = ".";
public:
    virtual void draw(Board board) override;

};


#endif //GOMOKU_DRAWERMESS_H
