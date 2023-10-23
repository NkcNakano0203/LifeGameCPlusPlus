#include "LifeGame.h"
#include "Parse.hpp"

using namespace std;

LifeGame::LifeGame(const unsigned int heightSize, const unsigned int widthSize)
{
	this->heightSize = heightSize;
	this->widthSize = widthSize;

	aliveCells.resize(heightSize * widthSize);
}

bool LifeGame::IsAlive(int y, int x)
{
	int lifeCount = 0;

	// 自分含めた周囲9マスのcellの生存状態を確認する
	for (int i = y - 1; i <= y + 1; i++)
	{
		// 0 <= i < heightSize
		if ((unsigned int)i >= heightSize) continue;

		for (int j = x - 1; j <= x + 1; j++)
		{
			// 0 <= j < widthSize
			if ((unsigned int)j >= widthSize) continue;

			//int index = y * widthSize + x;

			if (!aliveCells.at(PositionToIndex(i, j, widthSize))) continue;
			lifeCount++;
		}
	}

	if (aliveCells.at(PositionToIndex(y, x, widthSize)))
	{
		// 中心(自分)を抜いた周囲8マスの生存cell数
		int aroundLifeCount = lifeCount - 1;
		// 周囲の生きているcellが２つか３つならば生存
		return aroundLifeCount == 2 || aroundLifeCount == 3;
	}
	else
	{
		// 自分が死んでいて周囲の生きているcell数が3つならば誕生
		return lifeCount == 3;
	}
}

vector<bool> LifeGame::NextGeneration()
{
	vector<bool> newGene(heightSize * widthSize);
	for (int y = 0; y < heightSize; y++)
	{
		for (int x = 0; x < widthSize; x++)
		{
			newGene.at(PositionToIndex(y, x, widthSize)) = IsAlive(y, x);
		}
	}
	return newGene;
}

void LifeGame::RenderState()
{
	for (int y = 0; y < heightSize; y++)
	{
		for (int x = 0; x < widthSize; x++)
		{
			cout << (aliveCells.at(PositionToIndex(y, x, widthSize)) ? "■" : "□");
		}
		cout << "\n";
	}
}