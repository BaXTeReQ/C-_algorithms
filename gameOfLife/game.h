#ifndef GAME_H
#define GAME_H

#include "engine.h"

class Game : public Engine
{
   public:
      Game(int nnw, int nnk);
      virtual ~Game() {}
      void StartGame();
      virtual void View() = 0;
   protected:
      void Delay(long n);
   private:
      Game(const Game& g);
      Game& operator=(const Game& g);
};

#endif
