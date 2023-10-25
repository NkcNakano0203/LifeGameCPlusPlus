#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>

class LifeGame
{
public:
	LifeGame(const unsigned int heightSize, const unsigned int widthSize);

	/// <summary>
	/// 世代を１つ進める
	/// </summary>
	/// <param name="cells">次世代のcellの状態</param>
	/// <returns>全滅したらFalse</returns>
	bool TryNextGeneration(std::vector<bool>& cells);

	/// <summary>
	/// cellの状態を描画する
	/// 生存:■ 死亡:□
	/// </summary>
	void RenderState();

	std::vector<bool> aliveCells;
private:
	/// <summary>
	/// cellの生死を判定する
	/// </summary>
	/// <param name="y">縦の座標</param>
	/// <param name="x">横の座標</param>
	/// <returns>生きているならTrue</returns>
	bool IsAlive(int y, int x);

	unsigned int heightSize;
	unsigned int widthSize;
};