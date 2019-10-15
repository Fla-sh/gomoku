//
// Created by piotr on 15.10.19.
//

#ifndef GOMOKU_BOARD_H
#define GOMOKU_BOARD_H

#include <utility>
#include <string>

class Board {
private:
    int board[15][15];
    std::string linearise();
    void delinearise(std::string data);
    int currentPlayer;
    int madeMoves;

public:
    Board();
    void move(std::pair<int,int> position);
    void save();
    int getField(std::pair<int,int> position);
    void recreate();
    int getPlayer();
    int getTotalMoves();
};


#endif //GOMOKU_BOARD_H
