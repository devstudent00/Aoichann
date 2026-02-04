//#define _CRT_SECURE_NO_WARNINGS
#include "Field.h"
#include <assert.h>
#include <vector>
#include "Player.h"
#include "csvReader.h"
#include "Bird.h"
#include "Tortoise.h"
#include "DataHolder.h"

//std::vector<std::vector<int>> map = {
//	{ 1,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,1,0,0,1,0,0,0,1 },
//	{ 1,9,0,0,1,0,1,0,0,0,1 },
//	{ 1,1,1,1,0,1,1,0,0,0,1 },
//};
std::vector<std::vector<int>> map;

// std::vectorは、可変長の配列
// <int>は、intの配列

Field::Field()
{
	hImage = LoadGraph("data/image/bgchar.png");
	assert(hImage > 0);

	//CSVから読んでmapを作る
	DataHolder* dh = FindGameObject<DataHolder>();
	char filename[20];
	sprintf_s(filename, "data/stage%02d.csv", dh->stageNumber);
	CsvReader* csv = new CsvReader(filename);
	int lines = csv->GetLines(); // CSVの行数
	map.resize(lines);
	for (int y = 0; y < lines; y++) { // １行ずつ読む
		int cols = csv->GetColumns(y);
		map[y].resize(cols);
		for (int x = 0; x < cols; x++) {
			map[y][x] = csv->GetInt(y, x);
		}
	}
	delete csv;

	for (int y = 0; y < map.size(); y++) {
		for (int x = 0; x < map[y].size(); x++) {
			if (map[y][x] == 9) { // プレイヤーの初期位置
				new Player(x * 64, y * 64);
			}
			else if (map[y][x] == 10) { // 鳥の初期位置
				new Bird(x * 64, y * 64);
			}
			else if (map[y][x] == 11) { // 亀の初期位置
				new Tortoise(x * 64, y * 64);
			}
		}
	}
}

Field::~Field()
{
}

void Field::Update()
{
}

int Field::scroll = 0;

void Field::Draw()
{
	for (int y = 0; y < map.size(); y++) {
		for (int x = 0; x < map[y].size(); x++) {
			if (map[y][x] == 1) {
				DrawRectGraph(x * 64 - scroll, y * 64, 0, 64, 64, 64, hImage, TRUE);
			}
			if (map[y][x] == 2) {
				DrawRectGraph(x * 64 - scroll, y * 64 - (64*2),
					0, 64*5, 
					64*3, 64*3, hImage, TRUE);
			}
		}
	}
}

int Field::HitWallRight(int x, int y)
{
	if (IsInWall(x, y)) {
		int dx = x % 64;
		return dx+1;
	}
	return 0;
}

int Field::HitWallLeft(int x, int y)
{
	if (IsInWall(x, y)) {
		int dx = x % 64;
		return 64-dx;
	}
	return 0;
}

int Field::HitWallDown(int x, int y)
{
	if (IsInWall(x, y)) {
		int dy = y % 64;
		return dy+1;
	}
	return 0;
}

bool Field::IsInWall(int x, int y)
{
	if (y < 0 || y >= map.size() * 64) {
		return false;
	}
	int mapy = y / 64;
	if (x < 0 || x >= map[mapy].size() * 64) {
		return false;
	}
	int mapx = x / 64;
	if (map[mapy][mapx] == 1) {
		return true;
	}
	return false;
}

bool Field::IsGoal(int x, int y) {
	if (y < 0 || y >= map.size() * 64) {
		return false;
	}
	int mapy = y / 64;
	if (x < 0 || x >= map[mapy].size() * 64) {
		return false;
	}
	int mapx = x / 64;
	if (map[mapy][mapx] == 2) {
		return true;
	}
	return false;
}
