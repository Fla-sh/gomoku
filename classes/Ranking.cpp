//
// Created by piotr on 15.10.19.
//

#include <algorithm>
#include <fstream>
#include <iostream>
#include "../headers/Ranking.h"
#include <algorithm>
#include <cstring>

void Ranking::sort() {
    std::sort(Ranking::ranking.begin(), Ranking::ranking.end());
}

Ranking::Ranking() {

}

void Ranking::add(int value) {
    std::fstream file;
    file.open("../ranking.r", std::ios::app);
    file << std::endl << Ranking::now() << " " << value;
    file.close();
}

void Ranking::display(int amount) {
    std::fstream file;
    file.open("../ranking.r", std::ios::in);
    while(!file.eof()){
        std::pair<int, std::string> aPair;
        std::string date;
        int value;
        file >> date >> value;
        aPair = std::pair<int, std::string>(value, date);
        Ranking::ranking.push_back(aPair);
    }
    Ranking::sort();
    amount = std::min(amount, (int)Ranking::ranking.size());
    std::cout << "TABLICA WYNIKOW" << std::endl;
    std::cout << "Data" << "                    " << "Wynik:" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    for(int i = 0; i < amount; i++){
        std::cout << Ranking::ranking[i].second << "    " << Ranking::ranking[i].first << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl << std::endl;
}

std::string Ranking::now() {
    time_t now = time(0);
    tm * time = localtime(&now);
    int year = time->tm_year;
    int month = time->tm_mon;
    int day = time->tm_mday;
    int hour = time->tm_hour;
    int minute = time->tm_min;
    int sec = time->tm_sec;

    std::string result;
    result.append(std::to_string(1900 + year));
    result.append(".");

    if(month < 9) result.append("0" + std::to_string(1 + month));
    else result.append(std::to_string(1 + month));
    result.append(".");

    if(day < 10) result.append("0" + std::to_string(day));
    else result.append(std::to_string(day));
    result.append("->");

    if(hour < 10) result.append("0" + std::to_string(hour));
    else result.append(std::to_string(hour));
    result.append(":");

    if(minute < 10) result.append("0" + std::to_string(minute));
    else result.append(std::to_string(minute));
    result.append(":");

    if(sec < 10) result.append("0" + std::to_string(sec));
    else result.append(std::to_string(sec));

    return  result;
}
