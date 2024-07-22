#include <iostream>
#include <windows.h>

using namespace std;

#include <vector>

#include "engine.h"

Engine::Engine(int x, int y) : nx(x), ny(y){

    condition = true;
    eaten = false;

    dir = 's';

    nx = nx + 2;
    ny = ny + 2;

    arr = new int *[ny];
    temp = new int *[ny];

    for(int i = 0; i < ny; i++){
        arr[i] = new int[nx];
        temp[i] = new int[nx];
    }

    snakeBody.push_back({nx / 2, ny / 2 - 1});
    snakeBodyTemp.push_back({nx / 2, ny / 2 - 1});

    lastEatenFood.push_back({ 0, 0 });

    for(int i = 0; i < nx; i++)
    for(int j = 0; j < ny; j++){
        arr[i][j] = 0;
        temp[i][j] = 0;

        if(i == 0){
            arr[i][j] = 1;
            temp[i][j] = 1;
        }
        if(j == 0){
            arr[i][j] = 1;
            temp[i][j] = 1;
        }
        if(i == nx - 1){
            arr[i][j] = 1;
            temp[i][j] = 1;
        }
        if(j == ny - 1){
            arr[i][j] = 1;
            temp[i][j] = 1;
        }
    }

    for(size_t i = 0; i < snakeBody.size(); i++){
        arr[snakeBody[i].x][snakeBody[i].y] = 2;
        temp[snakeBody[i].x][snakeBody[i].y] = 2;
    }
}

Engine::~Engine(){
    for(int i = 0; i < nx; i++)
    for(int j = 0; j < ny; j++){
        delete arr[i];
        delete temp[i];
    }

    delete []arr;
    delete []temp;
}

void Engine::snakeMove(){

    for(int i = 1; i < nx - 1; i++){
        for(int j = 1; j < ny - 1; j++){
            temp[i][j] = 0;
        }
    }

    temp[foodX][foodY] = 3;

    switch(dir){
        case 'w':
            snakeBodyTemp[0].y--;
            break;
        case 's':
            snakeBodyTemp[0].y++;
            break;
        case 'a':
            snakeBodyTemp[0].x--;
            break;
        case 'd':
            snakeBodyTemp[0].x++;
            break;
    }

    condition = check();

    if(eaten){
        snakeBodyTemp.push_back({ lastEatenFood[0].x, lastEatenFood[0].y });
        snakeBody.push_back({ lastEatenFood[0].x, lastEatenFood[0].y });
        eaten = false;
    }

    if(snakeBodyTemp.size() > 1){
        for(size_t i = 0; i < snakeBodyTemp.size(); i++){
            snakeBodyTemp[i + 1].x = snakeBody[i].x;
            snakeBodyTemp[i + 1].y = snakeBody[i].y;
        }
    }

    for(size_t i = 0; i < snakeBody.size(); i++){
        snakeBody[i].x = snakeBodyTemp[i].x;
        snakeBody[i].y = snakeBodyTemp[i].y;
    }

    for(size_t i = 0; i < snakeBody.size(); i++){
        temp[snakeBody[i].x][snakeBody[i].y] = 2;
    }

    if(arr[snakeBody[0].x][snakeBody[0].y] == 3){
        eat();
    }

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            arr[i][j] = temp[i][j];
        }
    }
}

void Engine::eat(){
    lastEatenFood[0].x = foodX;
    lastEatenFood[0].y = foodY;
    eaten = 1;
    genFood();
}

void Engine::genFood(){

    foodX = rand() % getX();
    foodY = rand() % getY();

    while(temp[foodX][foodY] != 0 || temp[snakeBodyTemp[0].x][snakeBodyTemp[0].y] == temp[foodX][foodY]){
       foodX = rand() % getX();
       foodY = rand() % getY();
    }
}

int Engine::check(){
    if(temp[snakeBodyTemp[0].x][snakeBodyTemp[0].y] == 1 || arr[snakeBodyTemp[0].x][snakeBodyTemp[0].y] == 2){
            return false;
    }
    return true;
}

int Engine::getX(){
    return nx - 1;
}

int Engine::getY(){
    return ny - 1;
}
