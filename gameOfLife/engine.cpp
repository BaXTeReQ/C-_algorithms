#include <fstream>
#include <time.h>

#include "engine.h"

Engine::Engine(int w, int k) : nw(w), nk(k)
{
    arr = new bool *[nk];
    temp = new bool *[nk];

    for (int i = 0; i < k; i++)
    {
        arr[i] = new bool[nw];
        temp[i] = new bool[nw];
    }
    for(int i = 0; i < nw; i++){
        for(int j = 0; j < nk; j++){
            arr[i][j] = 0;
            temp[i][j] = 0;
        }
    }
    for(int i = 0; i < nw; i++)
        for(int j = 0; j < nk; j++)
            arr[i][j] = rand() % 2;
};

int Engine::sum(int i, int j)
{
    int ip, im, jp, jm;

    if(i < nw - 1) ip = i + 1;
    else ip = 0;
    if(i > 0) im = i - 1;
    else im = nw - 1;
    if(j < nk - 1) jp = j + 1;
    else jp = 0;
    if(j > 0) jm = j - 1;
    else jm = nk - 1;

    return arr[ip][j] + arr[ip][jp] + arr[i][jp] + arr[im][jp]
    + arr[im][j] + arr[im][jm] + arr[i][jm] + arr[ip][jm];
}

void Engine::analyze()
{
    for (int i = 0; i < nw; i++)
    {
        for (int j = 0; j < nk; j++)
        {
            if(arr[i][j] == 0){
                if(sum(i, j) == 3) temp[i][j] = 1;
                else temp[i][j] = 0;
            }
            if(arr[i][j] == 1){
                if (sum(i, j) == 2)
                    temp[i][j] = 1;
                if(sum(i, j) == 3)
                    temp[i][j] = 1;
                if(sum(i, j) != 2 && sum(i,j) != 3)
                    temp[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < nw; i++)
    {
        for (int j = 0; j < nk; j++)
        {
            arr[i][j] = temp[i][j];
        }
    }
}
