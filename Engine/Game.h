#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "MinesweeperSprites.h"
#include "Button.h"

class Game
{
public:
	enum class State
	{
		Hidden,
		Flagged,
		Revealed
	};
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
	void DrawBrick(int &x, int &y, int rect_x, int rect_y, int pocetak_x, int pocetak_y, Color color, int broj, Graphics& gfx);
	//bool ButtonArray[100] = { true,true, true,true, true,true, true,true, true,true,true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true };
	bool ButtonArray[100] = { true,true, true,true, true,true, true,true, true,true,true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true };
	bool FlagArray[100] = { true,true, true,true, true,true, true,true, true,true,true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true, true, true,true, true,true, true,true, true,true, true,true, true,true, true,true };
	bool BombArray[100] = { false, false, false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false, false, false };
	bool ButtonArrayX[10] = { true,true,true,true,true,true,true,true,true,true };
	bool ButtonArrayY[10] = { true,true,true,true,true,true,true,true,true,true };
	int FlagArrayBrojX[100];
	int FlagArrayBrojY[100];
	int test = 0;
	int brojac[100];
	int PotpunNizX[100] = { 0,0,0,0,0,0,0,0,0,0,16,16,16,16,16,16,16,16,16,16,32,32,32,32,32,32,32,32,32,32,48,48,48,48,48,48,48,48,48,48,64,64,64,64,64,64,64,64,64,64,80,80,80,80,80,80,80,80,80,80,96,96,96,96,96,96,96,96,96,96,112,112,112,112,112,112,112,112,112,112,128,128,128,128,128,128,128,128,128,128,144,144,144,144,144,144,144,144,144,144 };
	int PotpunNizY[100] = {0,16,32,48,64,80,96,112,128,144,0,16,32,48,64,80,96,112,128,144,0,16,32,48,64,80,96,112,128,144,0,16,32,48,64,80,96,112,128,144,0,16,32,48,64,80,96,112,128,144,0,16,32,48,64,80,96,112,128,144,0,16,32,48,64,80,96,112,128,144,0,16,32,48,64,80,96,112,128,144,0,16,32,48,64,80,96,112,128,144,0,16,32,48,64,80,96,112,128,144 };
	int testFlag = 0;
	int npcX;
	int npcY;
	private:
	bool click = false;
	bool ButtonTile[10] = { true,true, true,true, true,true, true,true, true,true };
	bool RevealedButton = false;
	void ComposeFrame();
	void UpdateModel();
	void MouseClickValue();
	void DrawButtons(int x, int y, int brojX, Graphics& gfx);
	void PlaceMines(int x, int y, Graphics& gfx);
	void InitializeButtons();
	int bomb;
	int bomb1;
	bool bomb3 = false;
	bool redbomb = false;
	int x=0;
	int y=0;
	int q;
	int z1=0;
	int z;
	bool potvrdi = false;
	int ArrayX[11];
	int ArrayY[11];
	int IntFlagArrayX[11];
	int IntFlagArrayY[11];
	int IntFlagArray[100];
	int DrawArray[10] = { 0,1,2,3,4,5,6,7,8,9 };
	bool boolArrayX[10] = { false, false, false, false, false, false, false, false, false, false};
	bool boolArrayY[10]=  { false, false, false, false, false, false, false, false, false, false};
	bool FlagPlaced[100] = { false, false, false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false, false, false };
	void FlagFunction(int brojX);
	bool immunity = false;
private:
	MainWindow& wnd;
	Graphics gfx;
	SpriteCodex sprite;
	Mouse mouse;
	Button1 button;
};