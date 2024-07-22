#ifndef GAMEAPI_H
#define GAMEAPI_H

#include <windows.h>

#include "snakeGame.h"

class gameApi : public snakeGame
{
  public:
      const static int dx = 20, dy = 20;
       int nx, ny;
  public:
      gameApi(int x, int y) : snakeGame(x, y), nx(x), ny(y){};
      virtual ~gameApi();
      void initApi(HWND hwnd);
      virtual void view();
      virtual void changeDir();
  private:
      HDC _hdc;
      HWND _hwnd;
      HBRUSH _snakeBrush, _BgBrush, _foodBrush, _borderBrush;
  private:
      gameApi(const gameApi& g);
      gameApi& operator=(const gameApi& g);
};

#endif
