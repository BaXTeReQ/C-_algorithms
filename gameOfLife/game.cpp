#include <time.h>
#include "game.h"

Game::Game(int nnw, int nnk) : Engine(nnw, nnk){}

void Game::StartGame()
{
   for(int i=0; i<1; i++) {
      View();
      analyze();
      Delay(100);
   }
}

void Game::Delay(long n)
{
   long t0 = clock();
   while(clock()-t0<n) ;
}
