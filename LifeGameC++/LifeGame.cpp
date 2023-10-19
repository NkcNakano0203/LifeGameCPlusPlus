#include "LifeGame.h"

using namespace std;

LifeGame::LifeGame(const int heightSize, const int widthSize)
{
	this->heightSize = heightSize;
	this->widthSize = widthSize;

	aliveCells.resize(heightSize * widthSize);
}

/// <summary>
/// cellの生死を判定する
/// </summary>
/// <param name="y">縦の座標</param>
/// <param name="x">横の座標</param>
/// <returns>生きているならTrue</returns>
bool LifeGame::IsAlive(int y, int x)
{
	int lifeCount = 0;

	// 自分含めた周囲9マスのcellの生存状態を確認する
	for (int i = y - 1; i < y + 1; i++)
	{
		// 0 <= i < heightSize
		if ((unsigned int)i > heightSize) continue;
		for (int j = x - 1; j < x + 1; j++)
		{
			// 0 <= j < widthSize
			if ((unsigned int)j > widthSize) continue;

			if (!aliveCells.at(i * j)) continue;
			lifeCount++;
		}
	}

	if (aliveCells.at(y * x))
	{
		// 周囲8マスの生存cell数
		int aroundLifeCount = lifeCount - 1;
		// 周囲の生きているcellが 2<=x<=3 ならば生存
		return aroundLifeCount >= 2 && aroundLifeCount <= 3;
	}
	else
	{
		// 自分が死んでいて周囲の生きているcell数が3つならば誕生
		return lifeCount == 3;
	}
}

/// <summary>
/// 世代を１つ進める
/// </summary>
/// <returns>次世代のcellの状態</returns>
vector<bool> LifeGame::NextGeneration()
{
	vector<bool> newGene(heightSize * widthSize);
	for (int y = 0; y < heightSize; y++)
	{
		for (int x = 0; x < widthSize; x++)
		{
			newGene.at(y * x) = IsAlive(y, x);
		}
	}
	return newGene;
}

/// <summary>
/// cellの状態を描画する
/// 生存:■ 死亡:□
/// </summary>
void LifeGame::RenderState()
{
	for (int y = 0; y < heightSize; y++)
	{
		for (int x = 0; x < widthSize; x++)
		{
			if (aliveCells.at(y * x))
			{
				cout << "■";
			}
			else
			{
				cout << "□";
			}
		}
		cout << "\n";
	}
}