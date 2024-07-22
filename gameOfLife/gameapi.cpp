#include "gameapi.h"

GameApi::GameApi(int nnw, int nnk) : Game(nnw, nnk){}

void GameApi::View()
{
   for(int i = 0; i < nw; i++) {
      for(int j = 0; j < nk; j++) {
         if(arr[i][j]) (HBRUSH)::SelectObject( _hdc, _MyBrush );
         else (HBRUSH)::SelectObject( _hdc, _BgBrush );

         Ellipse( _hdc, i*dx, j*dy, i*dx+dx, j*dy+dy );
      }
   }
}

void GameApi::InitApi(HWND hwnd)
{
   _hwnd = hwnd;
   _hdc = GetDC( _hwnd );
   _BgBrush = ::CreateSolidBrush(0x00ecf0f1);
   _MyBrush = ::CreateSolidBrush(0x009b59b6);
}

GameApi::~GameApi()
{
   ::DeleteObject( _MyBrush );
   ::DeleteObject( _BgBrush );
}
