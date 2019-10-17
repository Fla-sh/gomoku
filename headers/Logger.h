//
// Created by piotr on 14.10.19.
//

#ifndef GOMOKU_LOGGER_H
#define GOMOKU_LOGGER_H


#include <string>
#include <fstream>

/**
 * Facility used to save vital information about processing states
 * and events, for after release program care
 */
class Logger {
public:
    Logger();

    /**
     * Returns setup propmpt symbol
     * @return
     */
    static std::string getPrompt();

    /**
     * Save moves which made players to separate log -> moves.log
     * @param x
     * @param y
     * @param symbol
     */
    static void saveMove(int x, int y, char symbol);

    /**
     * Used to purge mvoe log. Used in early versions, now useless
     * @deprecated
     */
    static void purgeMoveLog();

    /**
     * Save all events in program to main log -> log.log.log
     * @param event data to save
     */
    static void safeEvent(std::string event);

private:
    /**
     * Prompt sign
     */
    static const std::string prompt;

    /**
     * Current date as UTM format
     * @return string with date
     */
    static std::string now();
};


#endif //GOMOKU_LOGGER_H
