#include <iostream>
#include <windows.h>

using namespace std;

#include "snakeGame.h"

void snakeGame::startGame(){

    genFood();

    while(condition){
        changeDir();
        snakeMove();
        if(!condition) continue;
        Sleep(200);
        system("CLS");
        view();
    }
}

