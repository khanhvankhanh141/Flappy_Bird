#ifndef GAMEOVER_H
#define GAMEOVER_H

#include<SDL.h>
#include<SDL_image.h>
#include"Background.h"

class Gameover
{
private:
    bool Click;
    Background menuGameover;
public:
    Gameover();
    ~Gameover();
    void Init(SDL_Renderer* ren);
    int getEvent(SDL_Event& e);
    void Render(SDL_Renderer* ren);
    bool getClick();
};
#endif // GAMEOVER_H
