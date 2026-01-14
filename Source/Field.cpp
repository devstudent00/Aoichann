#include "Field.h"
#include <DxLib.h>
#include <cassert>
#include <vector>
#include "Player.h"
#define BLOCK_ID 1
#define PLAYER_ID 9

std::vector<std::vector<int>> map = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 9, 0, 0, 1, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 0, 1, 1, 0, 1, 1}
};
// std::vectorは、可変長配列
// <int> は、int型の配列であることを示す
// 配列の配列で、2次元配列 

Field::Field() {
	blockImage = LoadGraph("data/image/bgchar.png");
	assert(blockImage > 0);

	for (int y = 0; y < map.size(); y++) {
		for (int x = 0; x < map[y].size(); x++) {
			if (map[y][x] == PLAYER_ID) {
				new Player(64 * x, 64 * y);
			}
		}
	}
}

Field::~Field()
{
}

void Field::Update() {
	
}

void Field::Draw() {
	for (int y = 0; y < map.size(); y++) {
		for (int x = 0; x < map[y].size(); x++) {
			if (map[y][x] == BLOCK_ID) {
				DrawRectGraph(64 * x, 64 * y, 0, 64, 64, 64, blockImage, true);
			}
		}
	}
	
}

int Field::HitWallRight(int x, int y) {
	int mapX = x / 64;
	int mapY = y / 64;
	if (map[mapY][mapX] == BLOCK_ID) {
		int dX = (x % 64);
		return dX+1;
	}
	return 0;
}

int Field::HitWallLeft(int x, int y)
{
	int mapX = x / 64;
	int mapY = y / 64;
	if (map[mapY][mapX] == BLOCK_ID) {
		int dX = (x % 64);
		return 64 - dX;
	}
	return 0;
}

int Field::HitWallDown(int x, int y) {
	int mapX = x / 64;
	int mapY = y / 64;
	if (map[mapY][mapX] == BLOCK_ID) {
		int dY = (y % 64);
		return dY + 1;
	}
	return 0;
}
