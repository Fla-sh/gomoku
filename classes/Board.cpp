//
// Created by piotr on 15.10.19.
//

#include <fstream>
#include <iostream>
#include "../headers/Board.h"

std::string Board::linearise() {
    std::string final = "";
    for(int y = 0; y < 15; y++){
        for(int x = 0; x < 15; x++){
            final.append(std::to_string(Board::board[x][y]));
        }
    }
    return final;
}

Board::Board() {
    Board::madeMoves = 0;
    Board::currentPlayer = 1;
    for(int x = 0; x < 15; x++){
        for(int y = 0; y < 15; y++){
            Board::board[x][y] = 0;
        }
    }
}

void Board::move(std::pair<int, int> position) {
    if (position.first >= 15 or position.first < 0) throw "Bad X position";
    else if (position.second >= 15 or position.second < 0) throw "Bad Y position";
    else if(Board::board[position.first][position.second] != 0) throw "Pole zajete";
    else {
        Board::board[position.first][position.second] = Board::currentPlayer + 1;
        Board::currentPlayer = (Board::currentPlayer + 1) % 2;
        Board::madeMoves++;
    }
}

void Board::save() {
    std::fstream file;
    file.open("../Game.save", std::ios::out);
    file << Board::linearise() << std::endl;
    file << Board::currentPlayer << std::endl;
    file << Board::madeMoves << std::endl;
    file.close();
}

int Board::getField(std::pair<int, int> position) {
    if (abs(position.first) >= 15) throw "Bad X position";
    else if (abs(position.second) >= 15) throw "Bad Y position";
    return Board::board[position.first][position.second];
}

void Board::recreate() {
    std::string boardState;
    std::fstream file;
    file.open("../Game.save", std::ios::in);
    file >> boardState;
    file >> Board::currentPlayer;
    file >> Board::madeMoves;
    file.close();
    Board::delinearise(boardState);
}

void Board::delinearise(std::string data) {
    for(int y = 0; y < 15; y++){
        for(int x = 0; x < 15; x++){
            Board::board[x][y] = (int)data[y * 15 + x] - '0';
        }
    }
}

int Board::getPlayer() {
    return Board::currentPlayer + 1;
}

int Board::getTotalMoves() {
    return Board::madeMoves;
}
