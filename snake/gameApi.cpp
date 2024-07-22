#include "gameapi.h"

void gameApi::view()
{
   for(int i = 0; i < nx + 2; i++) {
      for(int j = 0; j < ny + 2; j++) {

        if(arr[i][j] == 0)
            (HBRUSH)::SelectObject( _hdc, _BgBrush );
        if(arr[i][j] == 1)
            (HBRUSH)::SelectObject( _hdc, _borderBrush );
        if(arr[i][j] == 2)
            (HBRUSH)::SelectObject( _hdc, _snakeBrush );
        if(arr[i][j] == 3)
            (HBRUSH)::SelectObject( _hdc, _foodBrush );

        Rectangle( _hdc, i*dx, j*dy, i*dx+dx, j*dy+dy );
      }
   }
}

void gameApi::initApi(HWND hwnd)
{
   _hwnd = hwnd;
   _hdc = GetDC( _hwnd );
   _borderBrush = ::CreateSolidBrush(0x00ffffff);
   _BgBrush = ::CreateSolidBrush(0x00000000);
   _snakeBrush = ::CreateSolidBrush(0x0000ff00);
   _foodBrush = ::CreateSolidBrush(0x000000ff);
}

gameApi::~gameApi()
{
   ::DeleteObject( _borderBrush );
   ::DeleteObject( _BgBrush );
   ::DeleteObject( _snakeBrush );
   ::DeleteObject( _foodBrush );
}

void gameApi::changeDir(){
        if(GetAsyncKeyState(VK_UP) && dir != 's')
			dir = 'w';
		if(GetAsyncKeyState(VK_DOWN) && dir != 'w')
			dir = 's';
		if(GetAsyncKeyState(VK_LEFT) && dir != 'd')
			dir = 'a';
		if(GetAsyncKeyState(VK_RIGHT) && dir != 'a')
			dir = 'd';
}
