#ifndef GAMEAPI_H
#define GAMEAPI_H

#include <windows.h>

#include "game.h"

class GameApi : public Game
{
  public:
      const static int dx=20, dy=20;
  public:
      GameApi(int nnw, int nnk);
      virtual ~GameApi();
      void InitApi(HWND hwnd);
      virtual void View();
  private:
      HDC _hdc;
      HWND _hwnd;
      HBRUSH _MyBrush, _BgBrush;
  private:
      GameApi(const GameApi& g);
      GameApi& operator=(const GameApi& g);
};

#endif
