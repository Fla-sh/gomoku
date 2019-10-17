//
// Created by piotr on 15.10.19.
//

#ifndef GOMOKU_DRAWERALTERNATIVE_H
#define GOMOKU_DRAWERALTERNATIVE_H


#include "Board.h"
#include "Drawer.h"

/**
 * Is implementation of Drawer.
 * In this version player1 is + and player2 is o.
 */
class DrawerAlternative: public Drawer{
private:
    const std::string XMark = "+";
    const std::string OMark = "o";
    const std::string EmptyMark = " ";
public:
    virtual void draw(Board board) override;
};


#endif //GOMOKU_DRAWERALTERNATIVE_H
