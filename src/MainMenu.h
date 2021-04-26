#ifndef MAINMENU_H
#define MAINMENU_H

#include<SDL.h>
#include<SDL_image.h>
#include"Background.h"

class MainMenu
{
private:
	bool isClicked;
	Background menuBackground;
public:
	MainMenu();
	~MainMenu();
	void Initialize(SDL_Renderer* ren);
	int EventHandling(SDL_Event& e);
	void Render(SDL_Renderer* ren);
	bool getClicked();
};

#endif
