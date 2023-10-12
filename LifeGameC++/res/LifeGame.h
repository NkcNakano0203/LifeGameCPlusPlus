#pragma once
#include <Windows.h>
#include <iostream>

class LifeGame
{
public:
	LifeGame(int heightSize, int widthSize);
	bool* NextGeneration();
	void RenderState();

	bool aliveCells[1][1];
private:
	bool IsAlive(int y, int x);

	int32_t heightSize;
	int32_t widthSize;
};

LifeGame::LifeGame(int heightSize, int widthSize)
{
	this->heightSize = heightSize;
	this->widthSize = widthSize;

	aliveCells[heightSize][widthSize];
}
