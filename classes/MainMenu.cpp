//
// Created by piotr on 15.10.19.
//

#include <iostream>
#include "../headers/MainMenu.h"
#include "../headers/Logger.h"
#include "../headers/GameLoop.h"
#include "../headers/Ranking.h"

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
    Ranking ranking;
    ranking = Ranking();
    ranking.display(10);
}

void MainMenu::option4() {

}

void MainMenu::chooseOption() {
    bool chosen = false;
    std::string tmp;
    while (!chosen){
        try {
            Logger::safeEvent("Choosing option");
            std::cout << "GLOWNE MENU" << std::endl;
            std::cout << "Wybierz opcje" << std::endl;
            std::cout << "[1] Nowa Gra" << std::endl;
            std::cout << "[2] Kontynuuj" << std::endl;
            std::cout << "[3] Ranking" << std::endl;
            std::cout << Logger::getPrompt() << " ";
            std::cin >> tmp;

            isNumber(tmp);
            MainMenu::option = atoi(tmp.c_str());

            if (MainMenu::option <= 3 and MainMenu::option > 0) chosen = true;
            else std::cout << MainMenu::option << " nie jest poprawna wartoscia" << std::endl << std::endl << std::endl << std::endl;

            std::cout << std::endl << std::endl << std::endl << std::endl;
            Logger::safeEvent("Choosen option: " + std::to_string(option));
        }
        catch(const char * msg){
            std::cout << msg << std::endl << std::endl << std::endl << std::endl;
        }
    }
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

void MainMenu::isNumber(std::string text) {
    unsigned long length = text.length();
    for(int i = 0; i < length; i++){
        if(text[i] - '0' < 0 or text[i] -'0' >= 10) throw "Podana wartosc nie jest liczba naturalna";
    }
}
