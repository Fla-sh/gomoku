//
// Created by piotr on 15.10.19.
//

#ifndef GOMOKU_BOARD_H
#define GOMOKU_BOARD_H

#include <utility>
#include <string>

/**
    * Class represents board on which players are playing. It is 15x15 fields size.
    * Each player puts its marks on board.
    * Board does not have Drawer service in-built. It's implemented in Drawer Class.
    */
class Board {
private:
    /**
     * Actual board
     */
    int board[15][15];

    /**
     * Player which won
     */
    int winner;

    /**
    * Function linearise bord into string, which is used to save game progress
    * @return board as linearised string
    */
    std::string linearise();

    /**
     * Translate game state from string into 2D array -> board
     * @param data string we like to translate
     */
    void delinearise(std::string data);

    /**
     * Number of player which made move.
     * Updated after move was made
     */
    int currentPlayer;

    /**
     * Number of made moves.
     * Updated after move was made
     */
    int madeMoves;

    /**
     * Check if in any row was 5 the same signs
     * @return player number if any player won, or 0 if not
     */
    int findHorizontal();

    /**
    * Same as previous but performed in columns
    * @return player number if any player won, or 0 if not
    */
    int findVertical();

    /**
    * Same as previous, but performed in diagonals
    * @return player number if any player won, or 0 if not
    */
    int findDiagonal();

public:
    Board();

    /**
    * Update board with player move.
    * Notice players are choosen by function no by caller.
    * @param position position on which we put mark
    */
    void move(std::pair<int,int> position);

    /**
    * Save game state to file -> Game.save
    */
    void save();

    /**
    * Returns mark on pointed field
    * @param position position wich we'd like to check
    * @return mark as number
    */
    int getField(std::pair<int,int> position);

    /**
    * Recreates board state after save
    */
    void recreate();

    /**
    * Getter for current player
    * @return current player as number
    */
    int getPlayer();

    /**
    * Getter for total number of made moves during this game
    * @return total number of moves
    */
    int getTotalMoves();
    int getWinner();

    /**
    * Check if endgame condition is fulfiled
    * @return player number if any player won, or 0 if not
    */
    int isGameEnded();
};


#endif //GOMOKU_BOARD_H
