#include "MainWindow.h"
#include "Game.h"
#include <random>
#include <iostream>
#include <ctime>
using namespace std;
std::random_device rd;
std::mt19937 rng(time(0));
std::uniform_int_distribution<int> Bomb(0, 99);
Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}
int m;
int s;
int k=0;
void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	MouseClickValue();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
}

void Game::MouseClickValue()
{
}

void Game::FlagFunction(int brojX)
{
	FlagArray[brojX] = true;
}

void Game::PlaceMines(int x, int y, Graphics & gfx)
{
	sprite.DrawTileBombRed(x, y, gfx);
}

void Game::DrawButtons(int x, int y, int brojX, Graphics & gfx)
{
	for (int i = 0; i < 11; i++) 
	{
		for (int j = 0; j < 11; j++)
		{
			int sum = 16;
			{
				ArrayX[i] = sum*i;
				ArrayY[j] = sum*j;
				IntFlagArrayX[i] = sum*i;
				IntFlagArrayY[j] = sum*j;
			}
		}
	}
	if (ButtonArray[brojX] == true)
	{
		sprite.DrawTileButton(x, y, gfx);
	}
	if (ButtonArray[brojX] == false)
	{
		sprite.DrawTile0(x, y, gfx);
	}
	if (FlagArray[brojX] == false)
	{
		sprite.DrawTileFlag(x, y, gfx);
	}
	if (BombArray[brojX] == true && bomb3 == true)//NEW
	{
		sprite.DrawTileBomb(x, y, gfx);
		for (static bool first = true; first; first = false)
		{
			sprite.DrawTileBombRed(x, y, gfx);
		}
	}
	while (!wnd.mouse.IsEmpty())
	{
		const auto e = wnd.mouse.Read();
		if (e.GetType() == Mouse::Event::Type::LPress)
		{
			test = 0;
		}
		if (e.GetType() == Mouse::Event::Type::RPress)
		{
			testFlag = 0;
		}
	}

	if (testFlag == 0)
	{
		if (ButtonArray[brojX] != false)
		{
			if ((GetKeyState(VK_RBUTTON) & 0x100) != 0)
			{
				int flagX = wnd.mouse.GetPosX();
				int flagY = wnd.mouse.GetPosY();
				int IntFlagX = flagX / 16;
				int IntFlagY = flagY / 16;
				if (flagX >= x && flagX <= x + 15 && flagY >= y && flagY <= y + 15)
				{
					if (FlagArray[brojX] == false)
					{
						FlagFunction(brojX);
						immunity = true;
					}
					if (FlagArray[brojX] != false && immunity == false)
					{
						FlagArray[brojX] = false;
					}
					testFlag = 1;
				}
			}
		}
		immunity = false;
	}
	//BOMBS
	for (static bool first = true; first; first = false)
	{
		for (int oo = 0; oo < 10; oo++)
		{
			bomb = Bomb(rng);
			if (bomb1 == bomb)
			{
				bomb = Bomb(rng);
			}
			bomb1 = bomb;
			BombArray[bomb] = true;
		}
	}
	if (test == 0)
	{
		if (FlagArray[brojX] != false)
		{
			if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				wnd.mouse.GetPosX();
				wnd.mouse.GetPosY();
				m = wnd.mouse.GetPosX();
				s = wnd.mouse.GetPosY();
				int u = m / 16;
				int p = s / 16;
				q = u;
				z = p;
					if (m >= ArrayX[u] && m <= ArrayX[u + 1] && s >= ArrayY[p] && s <= ArrayY[p + 1])
					{
						//kad se pozove odradi ono sto treba i onda ponisti
						//for (static bool first = true; first; first = false) pozove f-ju jednom
						ButtonArrayX[u] = false;

						if (m >= x && m <= x + 15 && s >= y && s <= y + 15)
						{
							ButtonArray[brojX] = false;
							test = 1;
							if (BombArray[brojX] == true)
							{
								bomb3 = true;
								PlaceMines(x, y, gfx);
								redbomb = true;
							}
							//sprite.DrawTile0(ArrayX[u], ArrayY[p], gfx);
						}
					}
				}
			}
		}
	}

void Game::ComposeFrame()
{
	for (int i = 0; i < 160; i++)
	{
		for (int j = 0; j < 160; j++)
		{
			gfx.PutPixel(i,j,Colors::MineField);
		}
	}
	InitializeButtons();
	}

void Game::InitializeButtons()
{
	DrawButtons(0, 0,   0, gfx);
	DrawButtons(0, 16,  1, gfx);
	DrawButtons(0, 32,  2, gfx);
	DrawButtons(0, 48,  3, gfx);
	DrawButtons(0, 64,  4, gfx);
	DrawButtons(0, 80,  5, gfx);
	DrawButtons(0, 96,  6, gfx);
	DrawButtons(0, 112, 7, gfx);
	DrawButtons(0, 128, 8, gfx);
	DrawButtons(0, 144, 9, gfx);

	DrawButtons(16, 0,   10, gfx);
	DrawButtons(16, 16,  11, gfx);
	DrawButtons(16, 32,  12, gfx);
	DrawButtons(16, 48,  13, gfx);
	DrawButtons(16, 64,  14, gfx);
	DrawButtons(16, 80,  15, gfx);
	DrawButtons(16, 96,  16, gfx);
	DrawButtons(16, 112, 17, gfx);
	DrawButtons(16, 128, 18, gfx);
	DrawButtons(16, 144, 19, gfx);

	DrawButtons(32, 0,   20, gfx);
	DrawButtons(32, 16,  21, gfx);
	DrawButtons(32, 32,  22, gfx);
	DrawButtons(32, 48,  23, gfx);
	DrawButtons(32, 64,  24, gfx);
	DrawButtons(32, 80,  25, gfx);
	DrawButtons(32, 96,  26, gfx);
	DrawButtons(32, 112, 27, gfx);
	DrawButtons(32, 128, 28, gfx);
	DrawButtons(32, 144, 29, gfx);

	DrawButtons(48, 0,   30, gfx);
	DrawButtons(48, 16,  31, gfx);
	DrawButtons(48, 32,  32, gfx);
	DrawButtons(48, 48,  33, gfx);
	DrawButtons(48, 64,  34, gfx);
	DrawButtons(48, 80,  35, gfx);
	DrawButtons(48, 96,  36, gfx);
	DrawButtons(48, 112, 37, gfx);
	DrawButtons(48, 128, 38, gfx);
	DrawButtons(48, 144, 39, gfx);

	DrawButtons(64, 0,   40, gfx);
	DrawButtons(64, 16,  41, gfx);
	DrawButtons(64, 32,  42, gfx);
	DrawButtons(64, 48,  43, gfx);
	DrawButtons(64, 64,  44, gfx);
	DrawButtons(64, 80,  45, gfx);
	DrawButtons(64, 96,  46, gfx);
	DrawButtons(64, 112, 47, gfx);
	DrawButtons(64, 128, 48, gfx);
	DrawButtons(64, 144, 49, gfx);

	DrawButtons(80, 0,   50, gfx);
	DrawButtons(80, 16,  51, gfx);
	DrawButtons(80, 32,  52, gfx);
	DrawButtons(80, 48,  53, gfx);
	DrawButtons(80, 64,  54, gfx);
	DrawButtons(80, 80,  55, gfx);
	DrawButtons(80, 96,  56, gfx);
	DrawButtons(80, 112, 57, gfx);
	DrawButtons(80, 128, 58, gfx);
	DrawButtons(80, 144, 59, gfx);

	DrawButtons(96, 0,   60, gfx);
	DrawButtons(96, 16,  61, gfx);
	DrawButtons(96, 32,  62, gfx);
	DrawButtons(96, 48,  63, gfx);
	DrawButtons(96, 64,  64, gfx);
	DrawButtons(96, 80,  65, gfx);
	DrawButtons(96, 96,  66, gfx);
	DrawButtons(96, 112, 67, gfx);
	DrawButtons(96, 128, 68, gfx);
	DrawButtons(96, 144, 69, gfx);

	DrawButtons(112, 0,   70, gfx);
	DrawButtons(112, 16,  71, gfx);
	DrawButtons(112, 32,  72, gfx);
	DrawButtons(112, 48,  73, gfx);
	DrawButtons(112, 64,  74, gfx);
	DrawButtons(112, 80,  75, gfx);
	DrawButtons(112, 96,  76, gfx);
	DrawButtons(112, 112, 77, gfx);
	DrawButtons(112, 128, 78, gfx);
	DrawButtons(112, 144, 79, gfx);

	DrawButtons(128, 0,   80, gfx);
	DrawButtons(128, 16,  81, gfx);
	DrawButtons(128, 32,  82, gfx);
	DrawButtons(128, 48,  83, gfx);
	DrawButtons(128, 64,  84, gfx);
	DrawButtons(128, 80,  85, gfx);
	DrawButtons(128, 96,  86, gfx);
	DrawButtons(128, 112, 87, gfx);
	DrawButtons(128, 128, 88, gfx);
	DrawButtons(128, 144, 89, gfx);

	DrawButtons(144, 0,   90, gfx);
	DrawButtons(144, 16,  91, gfx);
	DrawButtons(144, 32,  92, gfx);
	DrawButtons(144, 48,  93, gfx);
	DrawButtons(144, 64,  94, gfx);
	DrawButtons(144, 80,  95, gfx);
	DrawButtons(144, 96,  96, gfx);
	DrawButtons(144, 112, 97, gfx);
	DrawButtons(144, 128, 98, gfx);
	DrawButtons(144, 144, 99, gfx);
}