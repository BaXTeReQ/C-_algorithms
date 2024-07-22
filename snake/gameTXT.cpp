#include <iostream>
#include <windows.h>

using namespace std;

#include "gameTXT.h"

void gameTXT::view(){

    for(int i = 0; i < nx + 2; i++){
        for(int j = 0; j < ny + 2; j++){

            if(arr[i][j] == 0)
                cout << " ";
            if(arr[i][j] == 1)
                cout << "-";
            if(arr[i][j] == 2)
                cout << "O";
            if(arr[i][j] == 3)
                cout << "*";
        }
        cout << endl;
    }
}

void gameTXT::changeDir(){
        if(GetAsyncKeyState(VK_UP) && dir != 's')
			dir = 'w';
		if(GetAsyncKeyState(VK_DOWN) && dir != 'w')
			dir = 's';
		if(GetAsyncKeyState(VK_LEFT) && dir != 'd')
			dir = 'a';
		if(GetAsyncKeyState(VK_RIGHT) && dir != 'a')
			dir = 'd';
}
