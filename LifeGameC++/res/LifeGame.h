#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>

class LifeGame
{
public:
	LifeGame(const int heightSize, const int widthSize);
	std::vector<bool> NextGeneration();
	void RenderState();

	std::vector<bool> aliveCells;
private:
	bool IsAlive(int y, int x);

	int heightSize;
	int widthSize;
};