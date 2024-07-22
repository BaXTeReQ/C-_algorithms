#ifndef GAMETXT_H
#define GAMETXT_H

#include "snakeGame.h"

class gameTXT : public snakeGame{
public:
    int nx, ny;

public:
    gameTXT(int x, int y) : snakeGame(x, y), nx(x), ny(y){};
    ~gameTXT() = default;

    virtual void view();
    virtual void changeDir();

private:
    gameTXT(const gameTXT &e);
    gameTXT &operator=(const gameTXT &e);
};


#endif // GAMETXT_H
