//
// Created by piotr on 15.10.19.
//

#include <iostream>
#include "../headers/MainMenu.h"
#include "../headers/Logger.h"
#include "../headers/GameLoop.h"

//New Game
void MainMenu::option1() {
    GameLoop gameLoop = GameLoop();
    gameLoop.startNew();
}

//Continue Game
void MainMenu::option2() {
    GameLoop gameLoop = GameLoop();
    gameLoop.continueGame();
}

//Ranking
void MainMenu::option3() {

}

void MainMenu::option4() {

}

void MainMenu::chooseOption() {
        Logger::safeEvent("Choosing option");
        std::cout << "Wybierz opcje" << std::endl;
        std::cout << "[1] Nowa Gra" << std::endl;
        std::cout << "[2] Kontynuuj" << std::endl;
        std::cout << "[3] Ranking" << std::endl;
        std::cout << Logger::getPrompt() << " ";
        std::cin >> MainMenu::option;
        Logger::safeEvent("Choosen option: " + std::to_string(option));
}

MainMenu::MainMenu() {

}

void MainMenu::executeOption() {
    switch(MainMenu::option){
        case 1:{
            MainMenu::option1();
            break;
        }
        case 2:{
            MainMenu::option2();
            break;
        }
        case 3:{
            MainMenu::option3();
            break;
        }
    }
}

