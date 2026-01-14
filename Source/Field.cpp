#include "Field.h"
#include <DxLib.h>
#include <cassert>
#include <vector>
#define BLOCK_ID 1

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
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 1, 1, 0, 1, 1}
};
// std::vectorは、可変長配列
// <int> は、int型の配列であることを示す
// 配列の配列で、2次元配列 

Field::Field() {
	blockImage = LoadGraph("data/image/bgchar.png");
	assert(blockImage > 0);
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
