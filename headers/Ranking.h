//
// Created by piotr on 15.10.19.
//

#ifndef GOMOKU_RANKING_H
#define GOMOKU_RANKING_H
#include <vector>
#include <string>

/**
 * Facility used to collect data about best results achieved by players.
 * All data are saved to ranking.r file. Facility don't have
 * self contained list/vector of best result. Operation saving and
 * reading results is operating on file each time. This approach saves
 * RAM space, especially if there is a lots of data on record
 */
class Ranking {
private:
    /**
     * Vector with ranking, data are hold in it only for short while
     * when user wants to see its records table.
     */
    std::vector<std::pair<int, std::string> > ranking;

    /**
     * Abstractions layer for std::sort
     */
    void sort();

    /**
     * Current date as formated string
     * @return
     */
    std::string now();
public:
    Ranking();

    /**
     * Appends value to record.r file
     * @param value to append
     */
    void add(int value);

    /**
     * Reads data from record.r file, sort it and display
     * @param amount of data to display
     */
    void display(int amount);
};


#endif //GOMOKU_RANKING_H
