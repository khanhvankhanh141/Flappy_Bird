#ifndef GAMELOOP_H
#define GAMELOOP_H

#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<cstdlib>
#include"Player.h"
#include"Background.h"
#include"CollisionManager.h"
#include"TextManager.h"
#include"MainMenu.h"
#include"Gameover.h"

class GameLoop
{
private:
	Player p;
	Background b;
	Background ground1,ground2;
	Background Pipe_Above1;
	Background Pipe_Below1;
	Background Pipe_Above2;
	Background Pipe_Below2;
	Background Pipe_Above3;
	Background Pipe_Below3;
	Background leaderboard;
	TextManager score;
	TextManager gen;
	TextManager gameover;
	TextManager press;
	TextManager high;
	MainMenu menu;
	const int HEIGHT = 600;
	const int WIDTH = 800;
	int points = 0;
	int generations = 0;
	int nextCheckPoint = 0;
	int best;
	int highscore;
	int variance1 = rand() % 201 - 100;
	int variance2 = rand() % 201 - 100;
	int variance3 = rand() % 201 - 100;
	bool GameState;
	bool Die = false;
	SDL_Window* window;
	SDL_Event event1;
	SDL_Renderer* renderer;
public:
	GameLoop();
	void MainMenu();
	bool getGameState();
	void Update();
	void Reset();
	int Highscore();
	void Birddie();
	void waitUntilKeyPressed();
	void CollisionDetection();
	void Intialize();
	void Event();
	void Render();
	void Clear();
};

#endif
