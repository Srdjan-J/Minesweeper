#pragma once
#include "Graphics.h"

class SpriteCodex
{
public:
	// width and height of all tiles
	static constexpr int tileSize = 16;
	// base color for all tiles
	static constexpr Color baseColor = { 192,192,192 };
	// 16x16 tile sprites assume (192,192,192) background and top left origin
	
	static void DrawTile0(int x, int y, Graphics& gfx);
	static void DrawTile1(int x, int y, Graphics& gfx);
	static void DrawTile2(int x, int y, Graphics& gfx);
	static void DrawTile3(int x, int y, Graphics& gfx);
	static void DrawTile4(int x, int y, Graphics& gfx);
	static void DrawTile5(int x, int y, Graphics& gfx);
	static void DrawTile6(int x, int y, Graphics& gfx);
	static void DrawTile7(int x, int y, Graphics& gfx);
	static void DrawTile8(int x, int y, Graphics& gfx);
	static void DrawTileButton(int x, int y, Graphics& gfx);
	static void DrawTileCross(int x, int y, Graphics& gfx);
	static void DrawTileFlag(int x, int y, Graphics& gfx);
	static void DrawTileBomb(int x, int y, Graphics& gfx);
	static void DrawTileBombRed(int x, int y, Graphics& gfx);
	// Tile selector function valid input 0-8
	static void DrawTileNumber(const int pos, int n, Graphics& gfx);
	// Win Screen 254x192 center origin
	static void DrawWin(int x, int y, Graphics& gfx);

	// Text for size selection (center origin)
	//
	static constexpr int sizeselWidth = 240;
	static constexpr int sizeselHeight = 56;
	static void DrawSmall(int x, int y, Graphics& gfx);
	static void DrawMedium(int x, int y, Graphics& gfx);
	static void DrawLarge(int x, int y, Graphics& gfx);
};