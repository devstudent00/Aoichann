#include "Character.h"
#include "Field.h"

Character::Character()
{
}

Character::Character(int x, int y)
{
	hImage = -1;
	position = VECTOR3(x, y, 0);
	patX = 0;
	patY = 0;
}

Character::~Character()
{
	if (hImage > 0) {
		DeleteGraph(hImage);
	}
}

void Character::Draw()
{
	DrawRectGraph((int)position.x - Field::scroll, (int)position.y, 0, 64 * 0, 64, 64, hImage, TRUE);
}
