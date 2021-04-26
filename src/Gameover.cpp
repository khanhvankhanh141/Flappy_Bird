#include"Gameover.h"

Gameover::Gameover()
{
    Click = false;
}

void Gameover::Init(SDL_Renderer* ren)
{
    menuGameover.CreateTexture("Image/gameover.png", ren);
}

int Gameover::getEvent(SDL_Event& e)
{
    SDL_PollEvent(&e);
    if(e.type == SDL_QUIT)
    {
        return -1;
    }
    else if(e.type == SDL_MOUSEBUTTONDOWN)
    {
        Click = true;
    }
    return 0;
}

void Gameover::Render(SDL_Renderer* ren)
{
    menuGameover.Render(ren);
}

bool Gameover::getClick()
{
    return Click;
}

Gameover::~Gameover()
{
    Click = false;
}
