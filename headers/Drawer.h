//
// Created by piotr on 15.10.19.
//

#ifndef GOMOKU_DRAWER_H
#define GOMOKU_DRAWER_H


#include <string>
#include "Board.h"

class Drawer {
private:
    const std::string XMark;
    const std::string OMark;
    const std::string EmptyMark;
    const std::string verticalSeparator;
    const std::string horizontalSeparator;
public:
    virtual void draw(Board board) = 0;
};


#endif //GOMOKU_DRAWER_H
