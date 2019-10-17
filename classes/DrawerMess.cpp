//
// Created by piotr on 15.10.19.
//

#include "../headers/DrawerMess.h"
//
// Created by piotr on 15.10.19.
//

#include <iostream>
#include "../headers/DrawerMess.h"

void DrawerMess::draw(Board board) {
    std::cout << "Plansza" << std::endl;
    std::cout << "    |0|1|2|3|4|5|6|7|8|9|10|11|12|13|14" << std::endl;
    for(int y = 0; y < 15; y++){
        if(y < 10) std::cout << y << "   |";
        else std::cout << y << "  |";

        for(int x = 0; x < 15; x++){
            std::pair<int, int> position(x, y);
            if(x > 9) std::cout << " ";
            if(board.getField(position) == 1) std::cout << DrawerMess::OMark;
            else if(board.getField(position) == 2) std::cout << DrawerMess::XMark;
            else std::cout << DrawerMess::EmptyMark;
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------------------------" << std::endl;
}
