//
// Created by piotr on 15.10.19.
//

#ifndef GOMOKU_GAMELOOP_H
#define GOMOKU_GAMELOOP_H

#include "Board.h"
#include "Drawer.h"
#include "DrawerClassic.h"

/**
 * Class which is main Game loop.
 * Contains method for controlling game state.
 * Class is not main Program loop, which is Gomoku class
 */
class GameLoop {
private:
    /**
     * Flag pointing true if game is not ended in some reason, e.g. won of one of players
     */
    bool stillPlaying;

    /**
     * Class which represents board
     */
    Board board;

    /**
     * Contains information about chosen Drawer
     */
    Drawer * drawer;

    /**
     * Function which reads user inputs, and calls Board and Drawer, as well as
     * checking if inputs was valid, and if player wants to exit game
     */
    void play();

    /**
     * Called if game was won by one of the players. Notify who is the winner
     * save results to Ranking, and save empty board, so choosing to continue
     * in main menu don't bring board with immediately winning setup
     */
    void end();

    /**
     * Check if given text is a unsigned int
     * @param text value to check
     */
    void isNumber(std::string text);
public:
    GameLoop();
    ~GameLoop();

    /**
     * Starts new game, just calls play() function
     */
    void startNew();

    /**
     * Loads last saved Board setup, and calls play()
     */
    void continueGame();
};


#endif //GOMOKU_GAMELOOP_H
