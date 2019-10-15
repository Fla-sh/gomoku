//
// Created by piotr on 15.10.19.
//

#include <iostream>
#include "../headers/GameLoop.h"
#include "../headers/Board.h"
#include "../headers/Drawer.h"
#include "../headers/DrawerClassic.h"

GameLoop::GameLoop() {
    GameLoop::stillPlaying = true;
    GameLoop::drawer = new DrawerClassic();
    GameLoop::board = Board();
}

void GameLoop::startNew() {
    GameLoop::play();
}

void GameLoop::continueGame() {
    board.recreate();
    GameLoop::play();
}


void GameLoop::play() {
    while(GameLoop::stillPlaying) {
        std::string x;
        std::string y;
        bool settingMove = true;
        GameLoop::drawer->draw(board);

        while (settingMove) {
            try {
                std::cout << "Wykonano ruchow: " << GameLoop::board.getTotalMoves() << std::endl;
                std::cout << "Ruch gracza " << GameLoop::board.getPlayer() << ": ";
                std::cin >> x;
                if(x == "stop"){
                    GameLoop::stillPlaying = false;
                    GameLoop::board.save();
                    break;
                }
                std::cin >> y;
                if(y == "stop"){
                    GameLoop::stillPlaying = false;
                    GameLoop::board.save();
                    break;
                }

                isNumber(x);
                isNumber(y);

                GameLoop::board.move(std::pair<int, int>(atoi(x.c_str()), atoi(y.c_str())));
                settingMove = false;
                GameLoop::board.save();
            }
            catch (const char *msg) {
                std::cout << msg << std::endl << std::endl;
            }
        }
    }
}

void GameLoop::isNumber(std::string text) {
    int length = text.length();
    for(int i = 0; i < length; i++){
        if(text[i] - '0' < 0 or text[i] -'0' >= 10) throw "Podana wartosc nie jest liczba naturalna";
    }
}


