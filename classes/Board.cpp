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
    Board::winner = 0;
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

int Board::isGameEnded() {
    int horizontal = Board::findHorizontal();
    int vertical = Board::findVertical();
    int diagonal = Board::findDiagonal();

    if(horizontal){
        Board::winner = horizontal;
        return horizontal;
    }
    if(vertical){
        Board::winner = vertical;
        return vertical;
    }
    if(diagonal){
        Board::winner = diagonal;
        return diagonal;
    }

    return 0;
}

int Board::findHorizontal() {
    for(int x = 0; x < 15; x++)
        for(int y = 0; y <= 10; y++){
            if( Board::board[x][y] != 0 and
                Board::board[x][y] == Board::board[x][y + 1] and
                Board::board[x][y] == Board::board[x][y + 2] and
                Board::board[x][y] == Board::board[x][y + 3] and
                Board::board[x][y] == Board::board[x][y + 4])
                return Board::board[x][y];
        }
    return 0;
}

int Board::findVertical() {
    for(int y = 0; y < 15; y++){
        for(int x = 0; x <= 10; x++){
            if( Board::board[x][y] != 0 and
                Board::board[x][y] == Board::board[x + 1][y] and
                Board::board[x][y] == Board::board[x + 2][y] and
                Board::board[x][y] == Board::board[x + 3][y] and
                Board::board[x][y] == Board::board[x + 4][y])
                return Board::board[x][y];
        }
    }
    return 0;
}

int Board::findDiagonal() {
    //up-down left-right
    for(int x = 0; x <= 10; x++){
        for(int y = 0; y <= 10; y++){
            if( Board::board[x][y] != 0 and
                Board::board[x][y] == Board::board[x + 1][y + 1] and
                Board::board[x][y] == Board::board[x + 2][y + 2] and
                Board::board[x][y] == Board::board[x + 3][y + 3] and
                Board::board[x][y] == Board::board[x + 4][y + 4])
                return Board::board[x][y];
        }
    }

    //up-down right-left
    for(int x = 0; x <= 10; x++){
        for(int y = 14; y > 3; y--){
            if( Board::board[x][y] != 0 and
                Board::board[x][y] == Board::board[x + 1][y - 1] and
                Board::board[x][y] == Board::board[x + 2][y - 2] and
                Board::board[x][y] == Board::board[x + 3][y - 3] and
                Board::board[x][y] == Board::board[x + 4][y - 4])
                return Board::board[x][y];
        }
    }
    return 0;
}

/**
 * Getter for winner player
 * @return winner player
 */
int Board::getWinner() {
    return Board::winner;
}
