#pragma once
#include "../Library/GameObject.h"

class DataHolder : public GameObject {
public:
	DataHolder();
	~DataHolder();

	int stageNumber;
};