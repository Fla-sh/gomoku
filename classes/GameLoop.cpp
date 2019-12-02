//
// Created by piotr on 15.10.19.
//

#include <iostream>
#include "../headers/GameLoop.h"
#include "../headers/Board.h"
#include "../headers/Drawer.h"
#include "../headers/DrawerClassic.h"
#include "../headers/Ranking.h"
#include "../headers/DrawerAlternative.h"
#include "../headers/DrawerMess.h"

GameLoop::GameLoop() {
    GameLoop::stillPlaying = true;
    GameLoop::drawer = new DrawerMess();
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
                std::cin >> y;
                if(y == "stop"){
                    GameLoop::stillPlaying = false;
                    GameLoop::board.save();
                    std::cout << std::endl << std::endl << std::endl << std::endl;
                    break;
                }

                std::cin >> x;
                if(x == "stop"){
                    GameLoop::stillPlaying = false;
                    GameLoop::board.save();
                    std::cout << std::endl << std::endl << std::endl << std::endl;
                    break;
                }


                std::cout << std::endl << std::endl << std::endl << std::endl;

                isNumber(x);
                isNumber(y);

                GameLoop::board.move(std::pair<int, int>(atoi(x.c_str()), atoi(y.c_str())));
                settingMove = false;
            }
            catch (const char *msg) {
                std::cout << msg << std::endl << std::endl;
            }

            if(GameLoop::board.isGameEnded()){
                GameLoop::end();
                GameLoop::stillPlaying = false;
                break;
            }
            GameLoop::board.save();
        }
    }
}

void GameLoop::isNumber(std::string text) {
    unsigned long length = text.length();
    for(int i = 0; i < length; i++){
        if(text[i] - '0' < 0 or text[i] -'0' >= 10) throw "Podana wartosc nie jest liczba naturalna";
    }
}

GameLoop::~GameLoop() {
    board.save();
}

void GameLoop::end() {
    std::cout << "Gra skonczona!" << std::endl;
    std::cout << "Wygral gracz: " << GameLoop::board.getWinner() << std::endl << std::endl << std::endl << std::endl;

    Ranking ranking;
    ranking = Ranking();
    ranking.add(GameLoop::board.getTotalMoves());

    GameLoop::board = Board();
    GameLoop::board.save();
}


