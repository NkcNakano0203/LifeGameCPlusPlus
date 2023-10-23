#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "Parse.hpp"
#include "LifeGame.h"

using namespace std;

vector<int> InitSetting(int& height, int& width);

int main()
{
	vector<int> init;
	int height;
	int width;
	int generationCount = 0;

	init = InitSetting(height, width);

	mt19937 mt{ std::random_device{}() };
	uniform_int_distribution<int> dist(0, 1);

	for (int i = 0; i < init.size(); i++)
	{
		// ランダムに0,1を代入する
		init.at(i) = dist(mt);
		cout << init.at(i);
	}

	LifeGame* lifeGame = new LifeGame(height, width);
	IntToBool(init, height, width, lifeGame->aliveCells);

	// 自動で世代を進める
	while (true)
	{
		// コンソールのクリア
		system("cls");
		cout << generationCount << "世代目" << endl;
		lifeGame->RenderState();
		// 待機
		Sleep(1000);
		lifeGame->aliveCells = lifeGame->NextGeneration();
		generationCount++;
	}

	delete lifeGame;
}

/// <summary>
/// 初期設定
/// </summary>
/// <param name="height">縦</param>
/// <param name="width">横</param>
/// <returns>(height*width)</returns>
vector<int> InitSetting(int& height, int& width)
{
	while (true)
	{
		cout << "横の長さは？：";
		cin >> width;
		if (width != 0) break;
		cout << "数字を入力してね！" << endl;
	}

	while (true)
	{
		cout << "縦の長さは？：";
		cin >> height;
		if (height != 0) break;
		cout << "数字を入力してね！" << endl;
	}

	vector<int> arr(height * width);
	return	arr;
}