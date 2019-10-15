//
// Created by piotr on 14.10.19.
//

#include "../headers/Logger.h"
#include <ctime>
#include <iostream>

const std::string Logger::prompt = "-->";

Logger::Logger() {
}

void Logger::saveMove(int x, int y, char symbol) {
    std::cout << "   x is " << x
              << " y is " << y
              << " symbols is " << symbol
              << std::endl;

    std::fstream logFile;
    logFile.open("../moves.log", std::ios::app);
    logFile << Logger::now()
                                        << "   x is " << x
                                        << " y is " << y
                                        << " symbols is " << symbol
                                        << std::endl;
    logFile.close();
}

void Logger::purgeMoveLog() {
    std::fstream logFile;
    logFile.open("../moves.log", std::ios::in);
    logFile << "";
    logFile.close();
}

void Logger::safeEvent(std::string event) {
    std::cout << event << std::endl;
    std::fstream logFile;
    logFile.open("../log.log.log", std::ios::app);
    logFile << Logger::now() << "   " << event << std::endl << std::endl;
    logFile.close();
}

std::string Logger::now() {
    time_t now = time(0);
    return ctime(&now);
}

std::string Logger::getPrompt() {
    return Logger::prompt;
}

