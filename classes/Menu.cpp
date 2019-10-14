//
// Created by piotr on 14.10.19.
//

#include "../headers/Menu.h"
#include "../headers/Logger.h"
#include <iostream>

Menu::Menu() {
}

void Menu::chooseOption() {
    Logger::safeEvent("Choosing option");
    std::cout << "Wybierz opcje: " << std::endl;
    std::cout << "[1] Nowa Gra" << std::endl;
    std::cout << "[2] Kontynuuj" << std::endl;
    std::cout << "[3] Ranking" << std::endl;
    std::cout << "--> ";
    std::cin >> Menu::option;
    Logger::safeEvent("Choosen option is: " + std::to_string(Menu::option));
}

void Menu::newGame() {

}

void Menu::continueGame() {

}
