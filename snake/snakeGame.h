#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include "engine.h"

class snakeGame : public Engine{
protected:
    int nx, ny;

public:
    snakeGame(int x, int y) : Engine(x, y){};
    virtual ~snakeGame() = default;
    void startGame();
    virtual void view() = 0;
    virtual void changeDir() = 0;

private:
    snakeGame(const snakeGame &e);
    snakeGame &operator=(const snakeGame &e);

};

#endif // SNAKEGAME_H
