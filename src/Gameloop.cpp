#include"GameLoop.h"

GameLoop::GameLoop()
{
	window = NULL;
	renderer = NULL;
	GameState = false;
	p.setSrc(0, 0, 24, 32);
	p.setDest(25, HEIGHT/2, 28, 38);
	ground1.setSrc(0, 0, 112, 336);
	ground1.setDest(0, 520, 112, 805);
	ground2.setSrc(0, 0, 112, 336);
	ground2.setDest(805, 520, 112, 805);
	Pipe_Above1.setSrc(0, 0, 320, 52);
	Pipe_Above1.setDest(400, -200, 400, 80);
	Pipe_Below1.setSrc(0, 0, 320, 52);
	Pipe_Below1.setDest(400, 350, 400, 80);
	Pipe_Above2.setSrc(0, 0, 320, 52);
	Pipe_Above2.setDest(700, -200, 400, 80);
	Pipe_Below2.setSrc(0, 0, 320, 52);
	Pipe_Below2.setDest(700, 350, 400, 80);
	Pipe_Above3.setSrc(0, 0, 320, 52);
	Pipe_Above3.setDest(1000, -200, 400, 80);
	Pipe_Below3.setSrc(0, 0, 320, 52);
	Pipe_Below3.setDest(1000, 350, 400, 80);
}

bool GameLoop::getGameState()
{
	return GameState;
}

void GameLoop::Intialize()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	if (window)
	{
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			GameState = true;

			p.CreateTexture("Image/bird_0.png", renderer);
			p.CreateTexture1("Image/bird_1.png", renderer);
			p.CreateTexture2("Image/bird_3.png", renderer);
			b.CreateTexture("Image/background.png", renderer);
			ground1.CreateTexture("Image/base.png", renderer);
			ground2.CreateTexture("Image/landSprite.png", renderer);
			Pipe_Above1.CreateTexture("Image/Pipe_Above.png", renderer);
			Pipe_Below1.CreateTexture("Image/Pipe_Below.png", renderer);
			Pipe_Above2.CreateTexture("Image/Pipe_Above.png", renderer);
			Pipe_Below2.CreateTexture("Image/Pipe_Below.png", renderer);
			Pipe_Above3.CreateTexture("Image/Pipe_Above.png", renderer);
			Pipe_Below3.CreateTexture("Image/Pipe_Below.png", renderer);
			score.CreateFont("Fonts/Number.ttf", 60);
			gen.CreateFont("Fonts/calibrib.ttf", 38);
            gameover.CreateFont("Fonts/Flappy-Bird.ttf",100);
            press.CreateFont("Fonts/Flappy-Bird.ttf",50);
            high.CreateFont("Fonts/calibrib.ttf", 38);
		}
		else
		{
			std::cout << "Not created!" << std::endl;
		}
	}
	else
	{
		std::cout << "window not created!" << std::endl;
	}
}

void GameLoop::MainMenu()
{
	menu.Initialize(renderer);
	while (!menu.getClicked())
	{
		if (menu.EventHandling(event1) == -1)
		{
			GameState = false;
			break;
		}
		SDL_RenderClear(renderer);
		menu.Render(renderer);
		SDL_RenderPresent(renderer);
	}
}


void GameLoop::Event()
{

	p.GetJumpTime();
	SDL_PollEvent(&event1);
	if (event1.type == SDL_QUIT)
	{
		GameState = false;
	}
	if (event1.type == SDL_KEYDOWN)
	{
		if (event1.key.keysym.sym == SDLK_SPACE)
		{
			if (!p.JumpState())
			{
				p.Jump();
			}
			else
			{
				p.Gravity();
			}
		}
	}
	else
	{
		p.Gravity();
	}
}

void GameLoop::Update()
{
	// Finding closest Checkpoint !
	if (Pipe_Below1.getPipe1X() < Pipe_Below2.getPipe2X() && Pipe_Below1.getPipe1X() < Pipe_Below3.getPipe3X())
	{
		if (Pipe_Below1.getPipe1X() < 150)
		{
			nextCheckPoint = Pipe_Below2.getPipe2Y();
		}
		else
		{
			nextCheckPoint = Pipe_Below1.getPipe1Y();
		}
	}
	else if (Pipe_Below2.getPipe2X() < Pipe_Below1.getPipe1X() && Pipe_Below2.getPipe2X() < Pipe_Below3.getPipe3X())
	{
		if (Pipe_Below2.getPipe2X() < 150)
		{
			nextCheckPoint = Pipe_Below3.getPipe3Y();
		}
		else
		{
			nextCheckPoint = Pipe_Below2.getPipe2Y();
		}

	}
	else if (Pipe_Below3.getPipe3X() < Pipe_Below1.getPipe1X() && Pipe_Below3.getPipe3X() < Pipe_Below2.getPipe2X())
	{
		if (Pipe_Below3.getPipe3X() < 150)
		{
			nextCheckPoint = Pipe_Below1.getPipe1Y();
		}
		else
		{
			nextCheckPoint = Pipe_Below3.getPipe3Y();
		}

	}


	// Scoring Mechanics
	std::string s;
	s = std::to_string(points);
	score.Text(s, 255, 255, 255, renderer);
    if(points > best)
    {
        best = points;
    }
    if(best > Highscore())
     {
        SDL_RWops *file = SDL_RWFromFile("Core/score.bin", "w+b");
        if (file)
        {
            SDL_RWwrite(file, &highscore, sizeof(int), 1);
            SDL_RWclose(file);
        }
     }
	// Generation Mechanics
	std::string s2;
	s2 = "Gen: " + std::to_string(generations);
	gen.Text(s2, 255, 255, 255, renderer);
    std::string s5;
	s5 = "High score: " + std::to_string(best);
	high.Text(s5, 255, 255, 255, renderer);

	bool flag1 = false, flag2 = false;
	ground1.GroundUpdate1();
	ground2.GroundUpdate2();
	flag1 = Pipe_Above1.Pipe_Above1Update(variance1, points);
	flag2 = Pipe_Below1.Pipe_Below1Update(variance1);
	if (flag1 && flag2)
	{
		srand(SDL_GetTicks());
		variance1 = rand() % 201 - 100;
		Pipe_Above1.Pipe_Above1Update(variance1, points);
		Pipe_Below1.Pipe_Below1Update(variance1);
	}
	flag1 = Pipe_Above2.Pipe_Above2Update(variance2, points);
	flag2 = Pipe_Below2.Pipe_Below2Update(variance2);
	if (flag1 && flag2)
	{
		srand(SDL_GetTicks());
		variance2 = rand() % 201 - 100;
		Pipe_Above2.Pipe_Above2Update(variance2, points);
		Pipe_Below2.Pipe_Below2Update(variance2);
	}
	flag1 = Pipe_Above3.Pipe_Above3Update(variance3, points);
	flag1 = Pipe_Below3.Pipe_Below3Update(variance3);
	if (flag1 && flag2)
	{
		srand(SDL_GetTicks());
		variance3 = rand() % 201 - 100;
		Pipe_Above3.Pipe_Above3Update(variance3, points);
		Pipe_Below3.Pipe_Below3Update(variance3);
	}


	CollisionDetection();

}

void GameLoop::CollisionDetection()
{

	if (CollisionManager::CheckCollision(p.getDest(), Pipe_Above1.getDest()) || CollisionManager::CheckCollision(p.getDest(), Pipe_Below1.getDest()) ||
		CollisionManager::CheckCollision(p.getDest(), Pipe_Above2.getDest()) || CollisionManager::CheckCollision(p.getDest(), Pipe_Below2.getDest()) ||
		CollisionManager::CheckCollision(p.getDest(), Pipe_Above3.getDest()) || CollisionManager::CheckCollision(p.getDest(), Pipe_Below3.getDest()))
	{
	    Die = true;
	    Birddie();
	    waitUntilKeyPressed();

	}
	else if (CollisionManager::CheckCollision(p.getDest(), ground1.getDest()) || CollisionManager::CheckCollision(p.getDest(), ground2.getDest()) || p.getYpos() < 0)
	{
        Die = true;
        Birddie();
        waitUntilKeyPressed();

	}
}

void GameLoop::Birddie()
{
    std::string s3,s4;
    s3 = "Game Over";
    s4 = "Press any key to start again ! ";
    if(Die == true)
    {
	    gameover.Text(s3,255,255,255,renderer);
	    press.Text(s4,255,255,255,renderer);
        Render();
	    generations++;
	    Reset();
    }
}

void GameLoop::Reset()
{
	points = 0;
	Die = false;
	variance1 = rand() % 201 - 100;
	variance2 = rand() % 201 - 100;
	variance3 = rand() % 201 - 100;
	p.Reset();
	Pipe_Above1.Reset();
	Pipe_Above2.Reset();
	Pipe_Above3.Reset();
	Pipe_Below1.Reset();
	Pipe_Below2.Reset();
	Pipe_Below3.Reset();
}

void GameLoop::waitUntilKeyPressed()
{
    SDL_Event even1;
    while (true) {
        if ( SDL_WaitEvent(&event1) != 0 && (event1.type == SDL_KEYDOWN || event1.type == SDL_QUIT) )
        {
        return;
        }
    SDL_Delay(100);
    }
}


void GameLoop::Render()
{

	SDL_RenderClear(renderer);
	b.Render(renderer);
	Pipe_Above1.PipeRender(renderer);
	Pipe_Below1.PipeRender(renderer);
	Pipe_Above2.PipeRender(renderer);
	Pipe_Below2.PipeRender(renderer);
	Pipe_Above3.PipeRender(renderer);
	Pipe_Below3.PipeRender(renderer);
	ground1.GroundRender(renderer);
	ground2.GroundRender(renderer);
	score.Render(renderer, 375 , 10);
	gen.Render(renderer, 10, 10);
	p.Render(renderer);
	if(Die ==  true )
    {
        gameover.Render(renderer, 250, 200);
        press.Render(renderer, 150, 300);
    }
    high.Render(renderer, 550, 10);

	SDL_RenderPresent(renderer);

}

int GameLoop::Highscore()
{
    SDL_RWops *file = SDL_RWFromFile("Core/score.bin", "r+b");
    if (file)
    {
        SDL_RWread(file, &highscore, sizeof(int), 1);
        SDL_RWclose(file);
    }
    return highscore;
}

void GameLoop::Clear()
{
	score.CloseFont();
	gen.CloseFont();
	gameover.CloseFont();
    press.CloseFont();
	TTF_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
