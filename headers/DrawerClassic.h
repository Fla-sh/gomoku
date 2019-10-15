//
// Created by piotr on 15.10.19.
//

#ifndef GOMOKU_DRAWERCLASSIC_H
#define GOMOKU_DRAWERCLASSIC_H


#include "Drawer.h"

class DrawerClassic: public Drawer {
    const std::string XMark = "X";
    const std::string OMark = "O";
    const std::string EmptyMark = " ";
    const std::string verticalSeparator = "";
    const std::string horizontalSeparator = "";
public:
    virtual void draw(Board board) override;

};


#endif //GOMOKU_DRAWERCLASSIC_H
