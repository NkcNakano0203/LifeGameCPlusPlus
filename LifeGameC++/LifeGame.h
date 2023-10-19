#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>

class LifeGame
{
public:
	LifeGame(const unsigned int heightSize, const unsigned int widthSize);
	std::vector<bool> NextGeneration();
	void RenderState();

	std::vector<bool> aliveCells;
private:
	bool IsAlive(int y, int x);

	unsigned int heightSize;
	unsigned int widthSize;
};