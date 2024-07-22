#ifndef ENGINE_H
#define ENGINE_H

#include <vector>

using namespace std;

struct position{
    int x, y;
};

class Engine{
protected:
    int **arr, **temp;
    int nx, ny, foodX, foodY;
    char dir;
    bool condition;
    bool eaten;
    vector<position> snakeBody;
    vector<position> snakeBodyTemp;
    vector<position> lastEatenFood;

protected:
    Engine(int x, int y);
    virtual ~Engine();
    void snakeMove();
    void eat();
    void genFood();
    int check();
    int getX();
    int getY();

private:
    Engine(const Engine &e);
    Engine &operator=(const Engine &e);

};


#endif // ENGINE_H
