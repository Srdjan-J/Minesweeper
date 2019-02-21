#pragma once
#include "MinesweeperSprites.h"
#include "Graphics.h"
class Button1
{
public:
	Button1() = default;
	void Draw(Graphics& gfx);
	bool ButtonArray[101] = { true,true, true,true, true,true, true,true, true,true,true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true,true, true };
private:
	SpriteCodex sprite;
};