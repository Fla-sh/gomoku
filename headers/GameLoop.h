//
// Created by piotr on 15.10.19.
//

#ifndef GOMOKU_GAMELOOP_H
#define GOMOKU_GAMELOOP_H

#include "Board.h"
#include "Drawer.h"
#include "DrawerClassic.h"

class GameLoop {
private:
    bool stillPlaying;
    Board board;
    Drawer * drawer;
    void play();
    void isNumber(std::string text);
public:
    GameLoop();
    void startNew();
    void continueGame();
};


#endif //GOMOKU_GAMELOOP_H
